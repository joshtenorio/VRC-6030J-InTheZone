#include "main.h"

void auto20PtRedRighta() {  //primary auton

	encoderReset(encoderChainB); //bring chainbar up
	delay(20);
	autoChainBar(-60);
	delay(1000);

	mobileGoal(75);
	delay(1250);
	mobileGoal(0);//mobile goal goes out 

	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(1400, 1400);
	delay(4);

	while (smartMotorGet(MOTOR_DRIVE_LF) > 30) {
		autoTankDrive(1600, 1600);            //go forward
		delay(5);
	}


	tankDrive(0, 0);  //stop drivetrain
	delay(4);

	mobileGoal(-100);
	delay(1350);
	mobileGoal(0);  //mobile goal goes back in 

	chainBar(0); //stops chainbar PID
	delay(750);

	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(0, -700);
	delay(4);

	while (smartMotorGet(MOTOR_DRIVE_LF) < -20) {
		autoTankDrive(0, -700); //rotate facing the scoring goal
		delay(5);
	}
	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(1000, 1000);
	delay(4);

	while (smartMotorGet(MOTOR_DRIVE_LF) < 30) {
		autoTankDrive(1000, 1000);
		delay(5);
	}
}
  ///// test the rotating feature then continue ////

/* hi sofia i fixed some of your code just so it would compile, I added an end brace/curly brace and changed the name of the function because theres already
a function named auto20PtRedRight
-Josh, 1 31 18 10:14 PM
*/
  