// #include <frc/TimedRobot.h>
// #include <frc/RobotBase.h>
// #include "rev/SparkMax.h"
// #include "rev/config/SparkMaxConfig.h"
// #include <iostream>

// class Robot : public frc::TimedRobot
// {
// public:
//   Robot()
//   : 
//     motor{
//         1, rev::spark::SparkMax::MotorType::kBrushless},
//         controller{motor.GetClosedLoopController()}
//   {
//     rev::spark::SparkMaxConfig config{};

//     config.encoder.PositionConversionFactor(1.0);
//     config.encoder.VelocityConversionFactor(1.0);

//     config.closedLoop.Pid(0.0001, 0.000001, 0.0005); // P, I, D

//     motor.Configure(
//         config,
//         rev::spark::SparkMax::ResetMode::kResetSafeParameters,
//         rev::spark::SparkMax::PersistMode::kNoPersistParameters
//     );
//   }

//   void TeleopPeriodic() override {
//     double targetRPM = -300.0;

//     controller.SetReference(
//         targetRPM,
//         rev::spark::SparkBase::ControlType::kVelocity
//     );

//     double currentRPM = motor.GetEncoder().GetVelocity();

//     std::cout << "Measure RPM: " << currentRPM << std::endl;
//   }


// private:
//   rev::spark::SparkMax motor;
//   rev::spark::SparkClosedLoopController controller;
// };

// #ifndef RUNNING_FRC_TESTS
// int main() {
//   return frc::StartRobot<Robot>();
// }
// #endif

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
