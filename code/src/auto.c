/** @file auto.c
 * @brief File for autonomous code
 *
 * This file should contain the user autonomous() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

/*
 * Runs the user autonomous code. This function will be started in its own task with the default
 * priority and stack size whenever the robot is enabled via the Field Management System or the
 * VEX Competition Switch in the autonomous mode. If the robot is disabled or communications is
 * lost, the autonomous task will be stopped by the kernel. Re-enabling the robot will restart
 * the task, not re-start it from where it left off.
 *
 * Code running in the autonomous task cannot access information from the VEX Joystick. However,
 * the autonomous function can be invoked from another task if a VEX Competition Switch is not
 * available, and it can access joystick information if called in this way.
 *
 * The autonomous task may exit, unlike operatorControl() which should never exit. If it does
 * so, the robot will await a switch to another mode or disable/enable cycle.
 */

void autonomous(){

  //autoPloopTest();
  //auto20PtRedRight();
  autoSkills();
  //autoBetterSkills();
	/*
	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(1000, -20);
	delay(5);
	while (smartMotorGet(MOTOR_DRIVE_LF) > 30) {
		autoTankDrive(1000, -20); //135 degree turn right
		delay(1);
	}
	tankDrive(0, 0);
	
	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(225, -225);
	delay(1);
	while (smartMotorGet(MOTOR_DRIVE_LF) > 30) {
		autoTankDrive(225, -225); //135 degree turn left
		delay(1);
	}
	tankDrive(0, 0);
  

 mobileGoal(-100);
 delay(1250); //mob goal in
  mobileGoal(0);
  
	mobileGoal(100);
	delay(1300); //mob goal out
	mobileGoal(0);
  */
}