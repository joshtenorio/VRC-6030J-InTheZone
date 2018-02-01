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






void autoBetterSkills() {
	encoderReset(encoderChainB); //bring chainbar up
	delay(20);
	autoChainBar(-80);
	delay(800);

	mobileGoal(100);
	delay(1250);
	mobileGoal(0);//mobile goal goes out (values need to be reworked and potentiometer needs extension cable wire)

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
	delay(1350);
	mobileGoal(0);  //mobile goal goes back in 

	chainBar(0); //stops chainbar PID
	delay(700);

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
	autoTankDrive(-700, 700);
	delay(1);
	while (smartMotorGet(MOTOR_DRIVE_LF) < -30) {
		autoTankDrive(-700, 700); //135 degree turn left
		delay(1);
	}
	
}