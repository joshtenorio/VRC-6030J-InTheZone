#include "main.h"


void autonBetterSkills() {
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
	mobileGoal(-100);
	delay(1350);
	mobileGoal(0);
	chainBar(0);


}


