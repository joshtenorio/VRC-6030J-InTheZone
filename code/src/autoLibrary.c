#include "main.h"

void autoTankDrive(int leftTarget, int rightTarget){  

  int rightCurrent = encoderGet(rightDriveShaft);
  int leftCurrent = encoderGet(leftDriveShaft);            
  
  int leftSpeed = PID(leftCurrent, leftTarget, PID_DRIVETRAIN);
  int rightSpeed = PID(rightCurrent, rightTarget, PID_DRIVETRAIN);
  tankDrive(leftSpeed, -rightSpeed);
}

void autoChainBar(int target){ 

  int current = encoderGet(encoderChainB);
  
  int speed = PID(current, target, PID_CHAINBAR);
  chainBar(speed);
}

void autoLinearGear(int target){ 
  int current = encoderGet(shaftLinearGear);
  
  int speed = PID(current, target, PID_LINEARGEAR);
  linearGear(speed);
}

void autoPloopTest(){
  autoTankDrive(3600, 3600);
}
void autoPloopTest2(){
  encoderReset(leftDriveShaft);
  encoderReset(rightDriveShaft);
  while(leftDriveShaft < 3600){
    autoTankDrive(3600, 3600);
  }
  delay(5);
  while(leftDriveShaft > 3599){
    autoTankDrive(0, 0);
  }
}
/*
void autoStationaryGoal(){
  while(encoderChainB < [target value of chainbar]){
    autoChainBar( ); //chainbar goes to other side
  }
  while(leftDriveShaft < [target value] && rightDriveShaft < [target value]) {
    autoTankDrive( , ); //go forward
  }
  while(shaftLinearGear < [target value]){ //need to test this, could be > instead of <
    autoLinearGear( ); //linear gear up
  }
  autoChainBar( ); //chainbar moves over to stack cone on stationary
  autoTimeConeG(90, ); //coneg stacks cone, need time
  
}
*/




















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
