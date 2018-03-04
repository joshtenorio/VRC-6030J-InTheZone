#include "main.h"


void autonBetter20PtRedRight() {
	encoderReset(encoderChainB); //bring chainbar up
	delay(20);
	autoChainBar(65); //original was -80
	delay(700);
	mobileGoal(100);
	delay(1450);
	mobileGoal(0); //mob goal out
	autoSmartTankDrive(1300, 1300); //drive forward
	mobileGoal(-100);
	delay(1350);
	mobileGoal(0);  //mobile goal goes back in 
	//delay(200);
	chainBar(0); //stops chainbar PID
	delay(600);
	autoSmartTankDrive(-900, -900);
	autoSmartTankDrive(-550, 550); //135 degree turn left, if doesnt work try 337 
	autoSmartTankDrive(700, 700);
	autoSmartTankDrive(-300, 300);
	autoSmartTankDrive(530, 530);
	delay(40);
	coneGrabber(90);
	autoChainBar(75);
	delay(100);
	coneGrabber(0);

	mobileGoal(100); //havent tested this block of code
	delay(1350);
	mobileGoal(0);
	autoSmartTankDrive(-700, -700);
	mobileGoal (-100);
	delay(1350);
	mobileGoal(0);
	chainBar(0);
}


void auton10PtRight() {
	encoderReset(encoderChainB);
	delay(20);
	autoHoldChainBar(86); //hold chainbar up
	mobileGoal(100);
	delay(1450);
	mobileGoal(0); //mob goal out
	autoSmartTankDrive(1300, 1300); //drive forward
	mobileGoal(-100);
	delay(1350);
	mobileGoal(0);  //mobile goal goes back in 
	delay(100);
	chainBar(0); 
	delay(400);
	autoSmartTankDrive(-900, -900);
	autoSmartTankDrive(-550, 550); //135 degree turn left
	autoSmartTankDrive(300, 300);
	autoSmartTankDrive(-300, 300);
	autoSmartTankDrive(170, 170);
	delay(40);
	coneGrabber(90);
	delay(40);
	autoHoldChainBar(86);
	delay(100);
	mobileGoal(100); 
	delay(1450);
	mobileGoal(0); 
	coneGrabber(0);
	delay(300);
	autoResetDriveEncoders();
	autoTankDrive(-3000, -1400); 
	mobileGoal(-100); 
	delay(1350);
	mobileGoal(0);
	chainBar(0);
	while (abs(smartMotorGet(MOTOR_DRIVE_LF)) > 33) {
		autoTankDrive(-3000, -1400);
		delay(1);
	}
	tankDrive(0, 0);
}

void auton10PtLeft() {
	encoderReset(encoderChainB); //bring chainbar up
	delay(20);
	autoHoldChainBar(85);
	delay(400);
	mobileGoal(100);
	delay(1450);
	mobileGoal(0); //mob goal out
	autoSmartTankDrive(1300, 1300); //drive forward
	mobileGoal(-100);
	delay(1350);
	mobileGoal(0);  //mobile goal goes back in 
	delay(100);
	chainBar(0);
	delay(500);
	autoSmartTankDrive(-900, -900);
	autoSmartTankDrive(520, -520); //135 degree turn right
	autoSmartTankDrive(180, 180);
	autoSmartTankDrive(300, -300);
	autoSmartTankDrive(350, 350);
	delay(40);
	coneGrabber(90);
	delay(40);
	autoHoldChainBar(85);
	mobileGoal(100);
	delay(1450);
	mobileGoal(0);
	coneGrabber(0);
	delay(300);
	autoResetDriveEncoders();
	autoTankDrive(-1400, -1400);
	mobileGoal(-100);
	delay(1350);
	mobileGoal(0);
	chainBar(0);
	while (abs(smartMotorGet(MOTOR_DRIVE_LF)) > 33) {
		autoTankDrive(-1400, -1400);
		delay(1);
	}
	tankDrive(0, 0);
}
void auton10PtRightSynch() { //should be same as normal 10 pt right auton, but this one attempts synchronization
	encoderReset(encoderChainB); //bring chainbar up
	delay(20);
	autoChainBar(70); 
	delay(400);
	autoSmartTankDrive(1300, 1300);
	mobileGoal(100);
	delay(1450);
	mobileGoal(0); //mob goal out
	mobileGoal(-100);
	delay(1350);
	mobileGoal(0);  //mobile goal goes back in 
	delay(200);
	chainBar(0);
	delay(500);
	autoSmartTankDrive(-900, -900); 
	autoSmartTankDrive(500, -500);/* //135 degree turn left 
	autoSmartTankDrive(300, 300);
	delay(40);
	coneGrabber(90);
	delay(40);
	autoChainBar(55);
	delay(100);
	mobileGoal(100);
	delay(1350);
	mobileGoal(0);
	coneGrabber(0);
	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(-3800, -1000);
	delay(440);
	mobileGoal(-100);
	delay(1350);
	mobileGoal(0);
	chainBar(0);
	delay(1);
	while (abs(smartMotorGet(MOTOR_DRIVE_LF)) > 33) {
		autoTankDrive(-3800, -1000);
		delay(1);
	}
	tankDrive(0, 0); */
}

void autonBlitz() {
	autoSmartTankDrive(5000, 5000);
}
   