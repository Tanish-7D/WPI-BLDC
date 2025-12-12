# WPI-BLDC

RoboRio 2.0 code that controls the Neo Brushless Motor through SPARK MAX CAN hardware.

---

## Prerequisites

Before installing WPI-BLDC, ensure you have the following:

- **WPILib**: The latest version of WPILib installed on your Windows computer
- **FRC Game Tools**: Including the FRC Driver Station
- **REV Hardware Client**: For configuring SPARK MAX controllers

---

## Installation

### Required Software

1. **WPILib**: [Download and Installation Guide](https://docs.wpilib.org/en/stable/docs/zero-to-robot/step-2/wpilib-setup.html)

2. **FRC Game Tools**: [NI FRC Game Tools Download](https://www.ni.com/en-us/support/downloads/drivers/download.frc-game-tools.html)

3. **REV Hardware Client**: [REV Hardware Client Download](https://docs.revrobotics.com/rev-hardware-client/)

4. **RoboRIO Imaging**: [Imaging Your RoboRIO Guide](https://frcdocs.wpi.edu/en/2022/docs/software/roborio-info/roborio2-imaging.html)

*NOTE: MAKE SURE ALL THE SOFTWARE IS ON THE LATEST VERSION*

---

## Cloning the Repository

### Using Command Line

Open a terminal or command prompt and run:

```bash
# Clone the repository
git clone https://github.com/Tanish-7D/WPI-BLDC.git

# Navigate to the project directory
cd WPI-BLDC
```

---

## Building the Project

1. Right-click on the build.gradle
2. Scroll down and select Build Robot Code
3. After building, right-click on the build.gradle again, and this time select Deploy Robot Code to send the code to ROBORIO 2.0

---

## Robot.cpp

Since the ROBORIO 2.0 only builds the file Robot.cpp, we included two different ways to run the motor in the same file. <br>

2 different ways to run the motor:

  1. The commented-out code contains a PID control that runs the motor at 57 RPM

```bash
#include <frc/TimedRobot.h>
#include <frc/RobotBase.h>
#include "rev/SparkMax.h"
#include "rev/config/SparkMaxConfig.h"
#include <iostream>

class Robot : public frc::TimedRobot
{
 public:
   Robot()
   : 
     motor{
         1, rev::spark::SparkMax::MotorType::kBrushless},
         controller{motor.GetClosedLoopController()}
   {
     rev::spark::SparkMaxConfig config{};

     config.encoder.PositionConversionFactor(1.0);
     config.encoder.VelocityConversionFactor(1.0);

     config.closedLoop.Pid(0.0001, 0.000001, 0.0005); // P, I, D

     motor.Configure(
         config,
         rev::spark::SparkMax::ResetMode::kResetSafeParameters,
         rev::spark::SparkMax::PersistMode::kNoPersistParameters
     );
   }

   void TeleopPeriodic() override {
     double targetRPM = -300.0;

     controller.SetReference(
         targetRPM,
         rev::spark::SparkBase::ControlType::kVelocity
     );

     double currentRPM = motor.GetEncoder().GetVelocity();

     std::cout << "Measure RPM: " << currentRPM << std::endl;
   }


 private:
   rev::spark::SparkMax motor;
   rev::spark::SparkClosedLoopController controller;
 };

 #ifndef RUNNING_FRC_TESTS
 int main() {
   return frc::StartRobot<Robot>();
 }
 #endif
```
  2. The rest of the code runs the motor at 30% of its maximum speed <br>
  
```bash
#include <frc/TimedRobot.h>
#include <frc/RobotBase.h>
#include "rev/SparkMax.h"

class Robot : public frc::TimedRobot
{
public:
  Robot()
    : motor{1, rev::spark::SparkMax::MotorType::kBrushless}
  {}

  void TeleopPeriodic() override {
    motor.Set(-0.3);
  }

private:
  rev::spark::SparkMax motor;
};

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
```

NOTE: For some unknown reason, the second way to run the motor switches directions when it's built, so make sure to check the direction and change the code depending on your requirement
