/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       MAIN.CPP                                                  */
/*    Author:       ANDREW HENKE                                              */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Team 2894A Competition formatted program                  */
/*                  including autonomous, user control,                       */
/*                  and subsystem monitoring and data logging funtions        */
/*    Last Modified 01/14/2020 04:22                                          */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftMotor            motor         1
// rightMotor           motor         2
// ScissorLeft          motor         3
// ScissorRight         motor         4
// Clamp                motor         11
// Controller1          controller
// leftMotorFwd         motor         8
// rightMotorFwd        motor         9
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
using namespace vex;

competition Competition;

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {

  // Robot Configuration Initialization
  vexcodeInit();
}

/*---------------------------------------------------------------------------*/
/*                              Autonomous Task                              */
/*                                                                           */
/*          Autonomous programming is in developmemt and testing,            */
/*              and has been removed for quality purposes.                   */
/*---------------------------------------------------------------------------*/
void autonomous(void) {

  ScissorLeft.stop(brake);
  ScissorRight.stop(brake);
  Clamp.stop(brake);
  leftMotor.setVelocity(95, percent);
  leftMotorFwd.setVelocity(95, percent);
  rightMotor.setVelocity(95, percent);
  rightMotorFwd.setVelocity(95, percent);
  leftMotor.spin(reverse);
  leftMotorFwd.spin(reverse);
  rightMotor.spin(reverse);
  rightMotorFwd.spin(reverse);
  wait(3, seconds);
  leftMotor.stop(brake);
  leftMotorFwd.stop(brake);
  rightMotorFwd.stop(brake);
  rightMotor.stop(brake);
  wait(0.5, seconds);
  leftMotor.spin(fwd);
  leftMotorFwd.spin(fwd);
  rightMotor.spin(fwd);
  rightMotorFwd.spin(fwd);
  wait(3, seconds);
  leftMotor.stop(brake);
  leftMotorFwd.stop(brake);
  rightMotorFwd.stop(brake);
  rightMotor.stop(brake);

  Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(1, 1);
  Controller1.Screen.print(ScissorLeft.temperature(percent));
  Controller1.Screen.newLine();
  Controller1.Screen.print(ScissorRight.temperature(percent));
  Controller1.Screen.newLine();
  Controller1.Screen.print(Clamp.temperature(percent));
  wait(1, seconds);
  Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(1, 1);
  Controller1.Screen.print("Battery Charge");
  wait(0.2, seconds);
  Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(1, 1);
  Controller1.Screen.print(Brain.Battery.capacity(percent));
  wait(1, seconds);
  Controller1.Screen.clearScreen();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*                 ORDER OF USER CONTROL PROGRAMMING SEGMENTS:               */
/*                                                                           */
/*                          TANK MODE JOYSTICK CONRTOL                       */
/*        SCISSOR LIFT SIMULTANEOUS DUAL MOTOR JOYSTICK BUTTON CONTROL       */
/*                          CLAMP JOYSTICK BUTTON CONTROL                    */
/*                                                                           */
/*          LAST MODIFIED:                                                   */
/*             01/14/2020                                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/

void drivercontrol(void) {

  /*----------------------------------JOYSTICK-CONTROL--------------------------*/
  while (true) {
    leftMotor.spin(vex::directionType::fwd, Controller1.Axis3.value(),
                   vex::velocityUnits::pct); //(Axis3+Axis4)/2
    leftMotorFwd.spin(vex::directionType::fwd, Controller1.Axis3.value(),
                      vex::velocityUnits::pct); //(Axis3+Axis4)/2
    rightMotor.spin(vex::directionType::fwd, Controller1.Axis2.value(),
                    vex::velocityUnits::pct); //(Axis3-Axis4)/2
    rightMotorFwd.spin(vex::directionType::fwd, Controller1.Axis2.value(),
                       vex::velocityUnits::pct); //(Axis3-Axis4)/2

    if (Controller1.ButtonR2.pressing()) {
      ScissorLeft.spin(forward);
      ScissorRight.spin(forward);
    } else if (Controller1.ButtonR1.pressing()) {
      ScissorLeft.spin(reverse);
      ScissorRight.spin(reverse);
    } else {

      ScissorLeft.stop(brake);
      ScissorRight.stop(brake);
    }
    if (Controller1.ButtonL1.pressing()) {
      Clamp.setVelocity(75, percent);
      Clamp.spin(fwd);

    } else if (Controller1.ButtonL2.pressing()) {
      Clamp.setVelocity(75, percent);
      Clamp.spin(reverse);
    } else {
      Clamp.stop(brake);
    }
    if (Controller1.ButtonB.pressing()) {
      Brain.Screen.clearScreen();
      Brain.Screen.printAt(2, 40, "REFRESHING");
      wait(0.2, seconds);
      Brain.Screen.clearScreen();
      Brain.Screen.printAt(2, 40, "BLMotor Temp: %f",
                           leftMotor.temperature(percentUnits::pct));
      Brain.Screen.printAt(2, 60, "FLMotor Temp: %f",
                           leftMotorFwd.temperature(percentUnits::pct));
      Brain.Screen.printAt(2, 80, "BR Motor Temp: %f",
                           rightMotor.temperature(percentUnits::pct));
      Brain.Screen.printAt(2, 100, "FR Motor Temp: %f",
                           rightMotorFwd.temperature(percentUnits::pct));
      Brain.Screen.printAt(2, 120, "Lift Right Motor Temp: %f",
                           ScissorRight.temperature(percentUnits::pct));
      Brain.Screen.printAt(2, 140, "Lift Left Motor Temp: %f",
                           ScissorLeft.temperature(percentUnits::pct));
      Brain.Screen.printAt(2, 160, "Clamp Motor Temp: %f",
                           Clamp.temperature(percentUnits::pct));
      Brain.Screen.printAt(2, 180, "Brain Battery Voltage: %f",
                           Brain.Battery.voltage());
      Brain.Screen.printAt(2, 200, "Brain Battery Current: %f",
                           Brain.Battery.current());
    }
    if (Controller1.ButtonA.pressing()) {
      Controller1.Screen.clearScreen();
      Controller1.Screen.setCursor(1, 1);
      Controller1.Screen.print("REFRESHING");
      wait(0.25, seconds);
      Controller1.Screen.clearScreen();
      Controller1.Screen.setCursor(1, 1);
      Controller1.Screen.print(Clamp.temperature(temperatureUnits::celsius));
      Controller1.Screen.newLine();
      Controller1.Screen.print(Clamp.temperature(percent));
      Controller1.Screen.newLine();
      Controller1.Screen.print(Clamp.temperature(temperatureUnits::fahrenheit));
    }
  }

  wait(20, msec);

  vex::task::sleep(20);
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(drivercontrol);

  pre_auton();

  while (true) {
    wait(100, msec);
  }
}
