#include "main.h"

void autoTankDrive(int leftTarget, int rightTarget){  

  int rightCurrent = encoderGet(rightDriveShaft);
  int leftCurrent = encoderGet(leftDriveShaft);            
    
  int leftSpeed = PID(leftCurrent, leftTarget, 0, 0.2, 0, 0);
  int rightSpeed = PID(rightCurrent, rightTarget, 0, 0.2, 0, 0);
  tankDrive(leftSpeed, rightSpeed);
  printf("going: %d\n", encoderGet(leftDriveShaft));
}

void autoChainBar(int target){ 

  int current = encoderGet(encoderChainB);
  
  int speed = PID(current, target, 2, 0.7, 0, 0);
  chainBar(speed);
}

void autoLinearGear(int target){ 
  int current = encoderGet(shaftLinearGear);
  
  int speed = PID(current, target, PID_LINEARGEAR);
  linearGear(speed);
}

void autoPloopTest(){   //backup auton
  encoderReset(leftDriveShaft);
  encoderReset(rightDriveShaft);
  autoTankDrive(1400, 1400);
  delay(4);
  while(smartMotorGet(MOTOR_DRIVE_LF) > 20) {
    autoTankDrive(1400, 1400); //go forward
    delay(5);
    printf("goinga: %d\n", smartMotorGet(MOTOR_DRIVE_LF));
  }  
   printf("pick up cone: %d\n", encoderGet(MOTOR_DRIVE_LF));
  tankDrive(0, 0);
}


void autoPloopTest2(){  //primary auton
  autoChainBar(-180);
  delay(750);
  autoChainBar(-60);
  
  mobileGoal(75);
  delay(1250);
  mobileGoal(0);
  
  encoderReset(leftDriveShaft);
  encoderReset(rightDriveShaft);
  autoTankDrive(1400, 1400);
  delay(4);
  while(smartMotorGet(MOTOR_DRIVE_LF) > 20) {
    autoTankDrive(1400, 1400); //go forward
    delay(5);
    printf("goinga: %d\n", smartMotorGet(MOTOR_DRIVE_LF));
  }  
   printf("pick up cone: %d\n", encoderGet(MOTOR_DRIVE_LF));
  tankDrive(0, 0);
  delay(4);
  
  mobileGoal(-100);
  delay(1350);
  mobileGoal(0);
  
  chainBar(0);
  
  encoderReset(leftDriveShaft);
  encoderReset(rightDriveShaft);
  autoTankDrive(-500, -500);
  delay(4);
  while(smartMotorGet(MOTOR_DRIVE_LF) < -20) {
    autoTankDrive(-500, -500); //go forward
    delay(5);
    printf("goinga: %d\n", smartMotorGet(MOTOR_DRIVE_LF));
  }  
   printf("pick up cone: %d\n", encoderGet(MOTOR_DRIVE_LF));
  tankDrive(0, 0);
}

void autoTimeConeG(int speed, int time){
  coneGrabber(speed);
  delay(time);
  coneGrabber(0);
}

void autoTimeMobileGoal(int speed, int time){
  mobileGoal(speed);
  delay(time);
  mobileGoal(speed);
}
