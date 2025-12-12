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

4. **RoboRIO Imaging**: [Imaging Your RoboRIO Guide](https://docs.wpilib.org/en/stable/docs/zero-to-robot/step-3/imaging-your-roborio.html)

NOTE: MAKE SURE ALL THE SOFTWARE IS ON THE LATEST VERSION

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
