#include "main.h"

void autoSkills() {
	int cbCurrent = encoderGet(encoderChainB);
	encoderReset(encoderChainB); //bring chainbar up
	delay(20);
	chainBar(-min(60, max(-60, PID(cbCurrent, -80, 1, 0.8, 0, 0))));
	delay(1000);

	mobileGoal(100);
	delay(1300);
	mobileGoal(0);//mobile goal goes out 

	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(1600, 1600); //rework these values
	delay(1);
	while (smartMotorGet(MOTOR_DRIVE_LF) > 30) {
		autoTankDrive(1600, 1600);            //go forward
		delay(1);
	}
	tankDrive(0, 0);  //stop drivetrain
	delay(1);

	mobileGoal(-100);
	delay(1350);
	mobileGoal(0);  //mobile goal goes back in 
	chainBar(0);

	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(-500, -500); 
	delay(1);
	while (smartMotorGet(MOTOR_DRIVE_LF) > 30) {
		autoTankDrive(-500, -500);            //go backwards
		delay(1);
	}
	tankDrive(0, 0);  //stop drivetrain
	delay(1);

	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(-500, -500); 
	delay(1);
	while (smartMotorGet(MOTOR_DRIVE_LF) > 30) {
		autoTankDrive(-200, 200);            //go turn left, need values
		delay(1);
	}
	tankDrive(0, 0);  //stop drivetrain
	delay(1);

	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(230, 230); //rework these values
	delay(1);
	while (smartMotorGet(MOTOR_DRIVE_LF) > 30) {
		autoTankDrive(230, 230);            //go forward a bit
		delay(1);
	}
	tankDrive(0, 0);  //stop drivetrain
	delay(1);
}


void autoBetterSkills() {
	encoderReset(encoderChainB); //bring chainbar up
	delay(20);
	autoChainBar(-80);
	delay(1200);

	mobileGoal(100);
	delay(1300);
	mobileGoal(0); //mob goal out

	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(1600, 1600);
	delay(1);
	while (smartMotorGet(MOTOR_DRIVE_LF) > 30) {
		autoTankDrive(1600, 1600);            //go forward
		delay(1);
	}
	tankDrive(0, 0);  //stop drivetrain
	delay(1);

	mobileGoal(-100);
	delay(1250);
	mobileGoal(0);  //mobile goal goes back in 

	chainBar(0); //stops chainbar PID
	delay(500);

	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(-1000, -1000);
	delay(1);
	while (smartMotorGet(MOTOR_DRIVE_LF) < -30) {
		autoTankDrive(-1000, -1000); //go backwards
		delay(1);
	}

	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(-337, 337);
	delay(1);
	while (smartMotorGet(MOTOR_DRIVE_LF) < -30) {
		autoTankDrive(-337, 337); //135 degree turn left
		delay(1);
	}
	
}