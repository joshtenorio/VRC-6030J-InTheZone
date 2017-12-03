#include "main.h"

void autoTankDrive(int leftTarget, int rightTarget){  

  int rightCurrent = encoderGet(rightDriveShaft);
  int leftCurrent = encoderGet(leftDriveShaft);            
  
  int leftSpeed = PID(leftCurrent, leftTarget, 0, 0.2, 0, 0);
  int rightSpeed = PID(rightCurrent, rightTarget, 0, 0.2, 0, 0);
  tankDrive(leftSpeed, -rightSpeed);
}

void autoChainBar(int target){ 

  int current = encoderGet(encoderChainB);
  
  int speed = chainbarPID(current, target, 0.4, 0.7);
  chainBar(speed);
}

void autoLinearGear(int target){ 
  int current = encoderGet(shaftLinearGear);
  
  int speed = PID(current, target, PID_LINEARGEAR);
  linearGear(speed);
}

void autoPloopTest(){
  encoderReset(leftDriveShaft);
  encoderReset(rightDriveShaft);
  autoTankDrive(1800, 1800);
}
void autoPloopTest2(){
  encoderReset(leftDriveShaft);
  encoderReset(rightDriveShaft);
  while(leftDriveShaft < 1800){
    autoTankDrive(1800, 1800);
  }
  delay(5);
  while(leftDriveShaft > 1799){
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


void autoTimeConeG(int speed, int time){
  coneGrabber(speed);
  delay(time);
  coneGrabber(0);
}
