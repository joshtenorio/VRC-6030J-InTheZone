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
    speed = 70;
  }
  else if(joystickGetDigital(2, 6, JOY_DOWN)){
    speed = -50;
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
  if(joystickGetDigital(2, 5, JOY_UP)){
    speed = 100;
  }
  else if(joystickGetDigital(2, 5, JOY_DOWN)){
    speed = -100;
  }
  else {
    speed = 0;
  }
  chainBar(speed);
}