#include "main.h"


void autoBetterSkills() {
	encoderReset(encoderChainB); //bring chainbar up
	delay(20);
	autoChainBar(-50); //original was -80
	delay(1200);

	mobileGoal(100);
	delay(1450);
	mobileGoal(0); //mob goal out

	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(1800, 1800);
	delay(1);
	while (smartMotorGet(MOTOR_DRIVE_LF) > 30) {
		autoTankDrive(1800, 1800);            //go forward
		delay(1);
	}
	tankDrive(0, 0);  //stop drivetrain
	delay(1);

	mobileGoal(-100);
	delay(1350);
	mobileGoal(0);  //mobile goal goes back in 

	chainBar(0); //stops chainbar PID
	delay(500);
	
	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(-1200, -1200);
	delay(1);
	while (smartMotorGet(MOTOR_DRIVE_LF) < -30) {
		autoTankDrive(-1200, -1200); //go backwards
		delay(1);
	}

	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(-250, 250);
	delay(1);
	while (smartMotorGet(MOTOR_DRIVE_LF) < -30) {
		autoTankDrive(-250, 250); //135 degree turn left
		delay(1);
	}
	/*
	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(600, 600);
	delay(1);
	while (smartMotorGet(MOTOR_DRIVE_LF) > 30) {
		autoTankDrive(600, 600);            //go forward
		delay(1);
	}


	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(-225, 225);
	delay(1);
	while (smartMotorGet(MOTOR_DRIVE_LF) < -30) {
		autoTankDrive(-225, 225); //90 degree turn left
		delay(1);
	}

	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(400, 400);
	delay(1);
	while (smartMotorGet(MOTOR_DRIVE_LF) > 30) {
		autoTankDrive(400, 400); //going forward into the 10 pt zone
		delay(1);
	} */
	encoderReset(encoderChainB); //bring chainbar up
	delay(20);
	autoChainBar(-40);
	delay(1200);
	
	mobileGoal(100);
	delay(1300);
	mobileGoal(0); //mob goal out

	tankDrive(127, 127);
	delay(400);
	tankDrive(0, 0);

	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(-600, -600);
	delay(1);
	while (smartMotorGet(MOTOR_DRIVE_LF) < -30) {
		autoTankDrive(-600, -600); //go backwards
		delay(1);
	}
	tankDrive(0, 0);

	mobileGoal(-100);
	delay(1250);
	mobileGoal(0);  //mobile goal goes back in 

	chainBar(0); //stops chainbar PID
	delay(500);

	tankDrive(0, 0);
	chainBar(0);
	mobileGoal(0);
	
}


