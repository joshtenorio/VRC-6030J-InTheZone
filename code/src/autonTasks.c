#include "main.h"

void auto20PtRedRight() {  //primary auton

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
	autoTankDrive(-700, -700);
	delay(4);

	while (smartMotorGet(MOTOR_DRIVE_LF) < -20) {
		autoTankDrive(-700, -700); //go backwards
		delay(5);
	}

	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(-400, 400); 
	delay(50);

	while (smartMotorGet(MOTOR_DRIVE_LF) < -30) {
		autoTankDrive(-400, 400); //go turn left
		delay(5);
	}

	encoderReset(leftDriveShaft);
	encoderGet(rightDriveShaft);
	autoTankDrive(720, 720); 
	delay(50);

	while (smartMotorGet(MOTOR_DRIVE_LF) > 25) { //go forward slightly
		autoTankDrive(720, 720); 
		delay(5);
	}

	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	while (smartMotorGet(MOTOR_DRIVE_LF) < -25) {
		autoTankDrive(-600, 400); //go turn left
		delay(5);
	}

	encoderReset(leftDriveShaft);
	encoderGet(rightDriveShaft);
	autoTankDrive(3600, 3600); 
	delay(50);

	while (smartMotorGet(MOTOR_DRIVE_LF) > 25) {
		autoTankDrive(3600, 3600); //go forward into scoring zone
		delay(5);
		tankDrive(0, 0);
	}

	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(800, 800);

	while (smartMotorGet(MOTOR_DRIVE_LF) > 25) {
		autoTankDrive(800, 800); //goes into the 10 pt zone
		delay(5);
	}

	//autoChainBar(-60); //chainbar goes up
	delay(500);

	mobileGoal(100); //mobile goal goes out
	delay(1100);
	mobileGoal(0);


	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(-500, -500);

	while (smartMotorGet(MOTOR_DRIVE_LF) <-25) {
		autoTankDrive(-500, -500); //go away from mobile goal
		delay(5);
	}

	mobileGoal(-75);
	delay(1000);
	mobileGoal(0);
	//chainBar(0);  //mobile goal goes back in and chainbar drops

	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(-2000, -2000);

	while (smartMotorGet(MOTOR_DRIVE_LF) <-25) {
		autoTankDrive(-2000, -2000); //moves away from mobile goal some more
		delay(5);
	}

}

/*void autoBetter20PtRedRight() {
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
	autoTankDrive(-1000, -1000);
	delay(4);
	while (smartMotorGet(MOTOR_DRIVE_LF) < -20) {
		autoTankDrive(-1000, -1000); //go backwards
		delay(5);
	}

}
*












//self destruct autonomous 
/* encoderReset(leftDriveShaft);
   encoderReset(rightDriveShaft);
   autoTankDrive(-500,500);
   
   while (smartMotorGet(MOTOR_DRIVE_LF)<25){
     autoTankDrive(-500,500); //turn left
     delay (5);
   } 
  encoderReset(leftDriveShaft);
   encoderReset(rightDriveShaft);
   autoTankDrive(500,500);   
   
   while (smartMotorGet(MOTOR_DRIVE_LF)<25){
     autoTankDrive(500,500); //go forward
     delay(5); 
     } 
  encoderReset(leftDriveShaft);
   encoderReset(rightDriveShaft);
   autoTankDrive(500,-500);   
   
   while (smartMotorGet(MOTOR_DRIVE_LF)<25){
     autoTankDrive(500,-500); //turn right 
     delay(5);
   }
  encoderReset(leftDriveShaft);
   encoderReset(rightDriveShaft);
   autoTankDrive(1800,1800);   
   
   while (smartMotorGet(MOTOR_DRIVE_LF)<25){
     autoTankDrive(1800,1800); //go forward
     delay(5);
    }
   */
   