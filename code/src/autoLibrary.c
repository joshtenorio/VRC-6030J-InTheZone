#include "main.h"

void autoTankDrive(int leftTarget, int rightTarget){  //kP needs tweaking
  float kP = .1;
  //float kI = <need value>;
  int rightCurrent = encoderGet(rightDriveShaft);
  int leftCurrent = encoderGet(leftDriveShaft);             //everything here that needs to use the P function needs tweaking
  
  int leftSpeed = P(leftCurrent, leftTarget, kP);
  int rightSpeed = P(rightCurrent, rightTarget, kP);
  tankDrive(leftSpeed, rightSpeed);
}

void autoChainBar(int target){ //kP needs tweaking
  float kP = .1;
  //float kI = <need value>;
  int current = encoderGet(shaftChainB);
  
  int speed = P(current, target, kP);
  chainBar(speed);
}

void autoLinearGear(int target){ //kP needs tweaking
  float kP = .1;
  //float kI = <need value>;
  int current = encoderGet(shaftLinearGear);
  
  int speed = P(current, target, kP);
  linearGear(speed);
}

void autoPloopTest(){
  autoTankDrive(1800, 1800);
}











void autoTimeTankDrive(int leftSpeed, int rightSpeed, int time) {
  tankDrive(leftSpeed, rightSpeed);
  delay(time);
  tankDrive(0, 0);
}

void autoTimeMobileGoal(int speed, int time) {
  mobileGoal(speed);
  delay(time);
  mobileGoal(0);
}

void autoTimeConeG(int speed, int time){
  coneGrabber(speed);
  delay(time);
  coneGrabber(0);
}
