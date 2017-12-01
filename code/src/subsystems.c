#include "main.h"

void tankDrive(int leftSpeed, int rightSpeed){
  smartMotorSet(MOTOR_DRIVE_LF, leftSpeed);
  smartMotorSet(MOTOR_DRIVE_LB, leftSpeed);
  smartMotorSet(MOTOR_DRIVE_RF, -rightSpeed);
  smartMotorSet(MOTOR_DRIVE_RB, -rightSpeed);
}

void mobileGoal(int speed){
  smartMotorSet(MOTORS_MOGO, speed);
}

void linearGear(int speed){
  smartMotorSet(MOTORS_LINEAR, speed);
} 

void chainBar(int speed){
  smartMotorSet(MOTORS_CHAINB, speed);
}

void coneGrabber(int speed){
  smartMotorSet(MOTOR_CONEG, speed);
}
/*
void autoReset() {         
  //need values for target
  int chainbarTarget = <need value>; //when chainbar is on opposite side of mobile goal
  int lineargearMax = <need value>; //highest point of the linear gear
  int lineargearMin = <need value>; //lowest point of the linear gear
  while(lineargearMax>encoderGet(shaftLinearGear)) {
    autoLinearGear(linearGearMax);
  }
  autoChainBar(chainbarTarget); //might need delay values in between movements so 
  autoLinearGear(lineargearMin);
 
}
*/



/*
int cbRecentReadingsAdj[3] = {0,0,0}; //Left to right = recent to old
int cbRecentReadingSummation = 0;
void conceptChainBar(){
  int speed;
  int current = encoderGet(encoderChainB);
  if(current != cbRecentReadingsAdj[0]){ //updating array
    cbRecentReadingsAdj[2] = cbRecentReadingsAdj[1];
    cbRecentReadingsAdj[1] = cbRecentReadingsAdj[0];
    cbRecentReadingsAdj[0] = current;
    cbRecentReadingSummation = 0;
  }
  else { //In case velocity is actually 0
    cbRecentReadingSummation += current;
    if(cbRecentReadingSummation / current == 4 && cbRecentReadingSummation % current == 0){
      cbRecentReadingsAdj = {current,current,current};
    }
  }
  int angularVelocity = cbRecentReadingsAdj[0] - cbRecentReadingsAdj[1];
  int maxAngularVelocity = 0;
  if(angularVelocity >= maxAngularVelocity) {
    maxAngularVelocity = angularVelocity;
  }
  if(abs(angularVelocity)<maxAngularVelocity){
    //regular PID with some kP value
  }
  else {
    //regular PID but with adjusted constant values
  }
}
*/
