#include "main.h"


void autoBetterSkills() {
	encoderReset(encoderChainB); //bring chainbar up
	delay(20);
	autoChainBar(64); //original was -80
	delay(1200);

	mobileGoal(100);
	delay(1450);
	mobileGoal(0); //mob goal out

	autoSmartTankDrive(1300, 1300); //drive forward, this is experimental testing

	mobileGoal(-100);
	delay(1350);
	mobileGoal(0);  //mobile goal goes back in 
	delay(200);
	chainBar(0); //stops chainbar PID
	delay(600);
	
	autoSmartTankDrive(-900, -900);
	autoSmartTankDrive(-550, 550); //135 degree turn left, if doesnt work try 337 
	autoSmartTankDrive(700, 700);
	autoSmartTankDrive(-300, 300);
	autoSmartTankDrive(570, 570);
	coneGrabber(90);
	autoChainBar(75);
	delay(100);
	coneGrabber(0);

	/*
	autoSmartTankDrive(-150, -150); //go backwards kind of

	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(500, 500);
	delay(1);
	while (smartMotorGet(MOTOR_DRIVE_LF) > 30) {
		autoTankDrive(500, 500); //going forward into the 10 pt zone
		delay(1);
	} 
	
	coneGrabber(90); //remove cone
	encoderReset(encoderChainB); //bring chainbar up
	delay(200);
	autoChainBar(-55);
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
	*/
}


