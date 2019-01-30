#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    Gyro,           sensorGyro)
#pragma config(Sensor, dgtl1,  AutonSelector,  sensorTouch)
#pragma config(Sensor, I2C_1,  WheelEncoder,   sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           Gun,           tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           TowerUp,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           TowerDown,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           Claw,          tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           Intake,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           RightFront,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           LeftRear,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           RightRear,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           LeftFront,     tmotorVex393_MC29, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port10,          Gun2,          tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma DebuggerWindows("debugStream")
#pragma DebuggerWindows("vexCompetitionControl")

//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

#include "helper.c"
#include "sensor.c"
#include "chassis.c"
#include "gun.c"
#include "tower.c"
#include "intake.c"
#include "claw.c"
#include "lcd.c"
#include "auton_basic.c"
#include "auton1.c"
#include "auton2.c"
#include "auton3.c"
#include "auton4.c"
#include "autonSkills1.c"
#include "autonSkills2.c"
#include "debug.c"
#include "onebuttonauton.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
void pre_auton() {
  resetGyroSensor();
  resetWheelEncoder();
}

task autonomous() {
  int mode = _get_lcd_input();
  if(mode == 1) {
    auton1();
  } else if(mode == 2) {
    auton2();
  } else if(mode == 3) {
    auton3();
  } else if(mode == 4) {
    auton4();
  } else if(mode == 5) {
    autonSkills1();
  } else if(mode == 6) {
    autonSkills2();
  }
}

void startUserControlTasks() {
  startTask(chassis_control);
  startTask(gun_control);
  startTask(tower_control);
  startTask(intake_control);
  startTask(claw_control);
  startTask(lcd_control);
}

void stopUserControlTasks() {
  stopTask(chassis_control);
  stopTask(gun_control);
  stopTask(tower_control);
  stopTask(intake_control);
  stopTask(claw_control);
  stopTask(lcd_control);
}

task usercontrol() {
  startUserControlTasks();

  while (true)
  {
    if(vexRT(Btn7U) == 1 && vexRt(Btn7D) == 1) {
      stopUserControlTasks();
      wait1Msec(100);
      onebuttonauton();
      startUserControlTasks();
    }

    printDebug();
    wait1Msec(1000);
  }
}
