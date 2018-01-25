#include "main.h"

void autoSkills() {
	encoderReset(encoderChainB); //bring chainbar up
	delay(20);
	autoChainBar(-80);
	delay(800);

	mobileGoal(75);
	delay(1350);
	mobileGoal(0);//mobile goal goes out 

	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(1200, 1200); //rework these values
	delay(1);
	while (smartMotorGet(MOTOR_DRIVE_LF) > 30) {
		autoTankDrive(1200, 1200);            //go forward
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