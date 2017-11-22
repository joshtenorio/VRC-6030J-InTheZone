#include "main.h"

void opcontrolTankDrive(){
  tankDrive(abs(joystickGetAnalog(1,3))>20 ? joystickGetAnalog(1,3) : 0,
          abs(joystickGetAnalog(1,2))>20 ? joystickGetAnalog(1,2) : 0);
}

void opcontrolMobileGoal(){
  int speed;
  if(joystickGetDigital(1, 5, JOY_UP)){
    speed = 75;
  }
  else if(joystickGetDigital(1, 5, JOY_DOWN)){
    speed = -75;
  }
  else if(joystickGetDigital(1, 6, JOY_UP)){
    speed = 100;
  }
  else if(joystickGetDigital(1, 6, JOY_DOWN)){
    speed = -100;
  }
  else {
    speed = 0;
  }
  mobileGoal(speed);
}

void opcontrolLinearGear(){
  int speed;
  if(joystickGetDigital(2, 6, JOY_UP)){
    speed = 127;
  }
  else if(joystickGetDigital(2, 6, JOY_DOWN)){
    speed = -127;
  }
  else {
    speed = 0;
  }
  linearGear(speed);
}

void opcontrolConeGrabber(){
  int speed;
  if(joystickGetDigital(2, 7, JOY_DOWN)){
    speed = 90;
  }
  else if(joystickGetDigital(2, 8, JOY_DOWN)){
    speed = -90;
  }
  else {
    speed = 0;
  }
  coneGrabber(speed);
}

void opcontrolChainBar(){ 
  int speed;
  int target = 0;
  if(joystickGetDigital(2, 5, JOY_UP)){
    speed = 75;
    target = encoderGet(encoderChainB);
  }
  else if(joystickGetDigital(2, 5, JOY_DOWN)){
    speed = -75;
    target = encoderGet(encoderChainB);
  }
  else {
    speed = 0;
    autoChainBar(target);
  }
  chainBar(speed);
}

/*
void opcontrolChainBarAndConeG(){
  int chainbarSpeed;
  int conegSpeed;
  if(joystickGetDigital(2, 7, JOY_UP)){
    chainbarSpeed = -75;
    conegSpeed = -90;
  }
  else if(joystickGetDigital(2, 5, JOY_UP)){
    chainbarSpeed = 75;
    conegSpeed = 0;
  }
  else if(joystickGetDigital(2, 5, JOY_DOWN)){
    chainbarSpeed = -75;
    conegSpeed = 0;
  }
  else if(joystickGetDigital(2, 7, JOY_DOWN)){
    chainbarSpeed = 0;
    conegSpeed = 90;
  }
  else if(joystickGetDigital(2, 8, JOY_DOWN)){
    chainbarSpeed = 0;
    conegSpeed = -90;
  }
  else{
    chainbarSpeed = 0;
    conegSpeed = 0;
  }
  chainBar(chainbarSpeed);
  coneGrabber(conegSpeed);
}
*/


