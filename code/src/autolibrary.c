#include "main.h"

void autoTankDrive(int leftTarget, int rightTarget){  

  int rightCurrent = encoderGet(rightDriveShaft);
  int leftCurrent = encoderGet(leftDriveShaft);            
    
  int leftSpeed = PID(leftCurrent, leftTarget, 0, 2, 0, 0);
  int rightSpeed = PID(rightCurrent, rightTarget, 0, 2, 0, 0);
  tankDrive(leftSpeed, rightSpeed);
  printf("going: %d\n", smartMotorGet(MOTOR_DRIVE_LF));

}

void autoSmartTankDrive(int leftTarget, int rightTarget) {
	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
	autoTankDrive(leftTarget, rightTarget);
	delay(1);
	while (abs(smartMotorGet(MOTOR_DRIVE_LF)) > 35) {
		autoTankDrive(leftTarget, rightTarget); 
		delay(1);
	}
	tankDrive(0, 0);  
	delay(1);
}

void autoChainBar(int target){ 

  int current = encoderGet(encoderChainB);
  
  int speed = min(60, max(-60, PID(current, target, 1, 0.8, 0, 0)));
  chainBar(speed);
  printf("chainbar moving %d\n", smartMotorGet(MOTORS_CHAINB));
}

void autoLinearGear(int target){ 
  int current = encoderGet(shaftLinearGear);
  
  int speed = PID(current, target, PID_LINEARGEAR);
  linearGear(speed);
}

void autoResetDriveEncoders() {
	encoderReset(leftDriveShaft);
	encoderReset(rightDriveShaft);
}

void autoTimeConeG(int speed, int time) {
	coneGrabber(speed);
	delay(time);
	coneGrabber(0);
}







