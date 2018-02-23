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

}


