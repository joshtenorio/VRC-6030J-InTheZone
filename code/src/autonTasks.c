#include "main.h"

void autoPloopTest2() {  //primary auton
	encoderReset(encoderChainB);
	delay(50);
	//autoChainBar(-60);
	delay(1000);

	mobileGoal(75);
	delay(1250);
	mobileGoal(0);//goes out 

	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(1400, 1400);
	delay(4);

	while (smartMotorGet(MOTOR_DRIVE_LF) > 30) {
		autoTankDrive(1600, 1600); //go forward
		delay(5);
		printf("goinga: %d\n", smartMotorGet(MOTOR_DRIVE_LF));
	}

	printf("pick up cone: %d\n", encoderGet(MOTOR_DRIVE_LF));
	tankDrive(0, 0);
	delay(4);

	mobileGoal(-100);
	delay(1350);
	mobileGoal(0);  //goes back in 

	//chainBar(0); //stops chainbar
	delay(750);

	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(-500, -500);
	delay(4);

	while (smartMotorGet(MOTOR_DRIVE_LF) < -20) {
		autoTankDrive(-500, -500); //go backwards
		delay(5);
		printf("goinga: %d\n", smartMotorGet(MOTOR_DRIVE_LF));
		printf("pick up cone: %d\n", encoderGet(MOTOR_DRIVE_LF));
		tankDrive(0, 0);
	}

	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(-400, 400); //slightly turn
	delay(50);

	while (smartMotorGet(MOTOR_DRIVE_LF) < -30) {
		autoTankDrive(-400, 400); //go turn
		delay(5);
	}

	encoderReset(leftDriveShaft);
	encoderGet(rightDriveShaft);
	autoTankDrive(720, 720); //go forward slightly
	delay(50);

	while (smartMotorGet(MOTOR_DRIVE_LF) > 25) {
		autoTankDrive(720, 720); 
		delay(5);

	}


	delay(20);



	while (smartMotorGet(MOTOR_DRIVE_LF) < -25) {
		autoTankDrive(-600, 400); //go turn
		delay(5);
	}

	encoderReset(leftDriveShaft);
	encoderGet(rightDriveShaft);
	autoTankDrive(3600, 3600); //go forward 
	delay(50);

	while (smartMotorGet(MOTOR_DRIVE_LF) > 25) {
		autoTankDrive(3600, 3600); //go back to the scoring zone
		delay(5);
		printf("goinga: %d\n", smartMotorGet(MOTOR_DRIVE_LF));
		printf("pick up cone: %d\n", encoderGet(MOTOR_DRIVE_LF));
		tankDrive(0, 0);
	}

	encoderReset(leftDriveShaft);
	encoderGet(rightDriveShaft);
	autoTankDrive(1800, 1800);
	delay(50);

	while (smartMotorGet(MOTOR_DRIVE_LF) > 25) {
		autoTankDrive(1800, 1800); //go back to the scoring zone
		delay(5);
	}

	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(800, 800);

	while (smartMotorGet(MOTOR_DRIVE_LF) > 25) {
		autoTankDrive(800, 800); //goes into the zone
		delay(5);
	}

	//autoChainBar(-60); //chainbar goes up
	delay(800);

	mobileGoal(100); //mobile goal goes out
	delay(1100);
	mobileGoal(0);

	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(400, 400);

	while (smartMotorGet(MOTOR_DRIVE_LF) > 25) {
		autoTankDrive(400, 400); //goes into the zone
		delay(5);
	}

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
	//chainBar(0);  //mobile goal goes back in

	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(-2000, -2000);

	while (smartMotorGet(MOTOR_DRIVE_LF) <-25) {
		autoTankDrive(-2000, -2000); //moves away from mobile goal
		delay(5);
	}

}