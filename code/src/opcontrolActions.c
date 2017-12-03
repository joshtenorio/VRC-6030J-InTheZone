#include "main.h"

void opcontrolTankDrive(){
  tankDrive(abs(joystickGetAnalog(1,3))>20 ? joystickGetAnalog(1,3) : 0,
          abs(joystickGetAnalog(1,2))>20 ? joystickGetAnalog(1,2) : 0);
}

void opcontrolMobileGoal(){
  int speed;
  /*
  if(encoderGet(encoderChainB) < 40){   //need new values
    speed = 0;
  }
  else{ */
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
  //}
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



void opcontrolChainBar(){                         //change code so that cortex gets target position when button is released not pressed
   int speed;
   int extern cbTarget;
   int current = encoderGet(encoderChainB);
   
   if(joystickGetDigital(2, 5, JOY_UP)){
     cbTarget = current;
     speed = 75;
     //cbButtonState[0] = 1; //up
   }
   else if(joystickGetDigital(2, 5, JOY_DOWN)){
     cbTarget = current;
     speed = -75;
     //cbButtonState[0] = -1; //down
   }
   else if(cbTarget != 0){                                           
     speed =0;
     //speed = min(75, max(-75,chainbarPID(encoderGet(encoderChainB), -60, 0.7, 0.7)));   //int chainbarPID(float current, float target, float wgkP, float agkP){
     //cbButtonState[1] = 1; //up
     //cbButtonState[1] = -1; //down
   }
   else {
     speed=0;
   }
   chainBar(speed);
 }

void opcontrolDebug(){
  if(joystickGetDigital(2, 7, JOY_UP)){
  encoderReset(encoderChainB);
  encoderReset(leftDriveShaft);
  encoderReset(rightDriveShaft);
  encoderReset(shaftLinearGear);
  }
}


