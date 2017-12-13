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

void opcontrolLinearGear(){   //will be reconfigured for cascade lift
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
   const int positionVertical = 0; //needs to be changed/adjusted
   int speed;
   int target;
   int current = encoderGet(encoderChainB);
   
   if((current > positionVertical && (joystickGetDigital(2, 5, JOY_DOWN) || target > current)) || (current < positionVertical && joystickGetDigital(2, 5, JOY_UP))){
      
   }
   else {
     
   }
   

   
   if(joystickGetDigital(2, 5, JOY_UP)){
     //target = current;
     speed = 75;
   }
   else if(joystickGetDigital(2, 5, JOY_DOWN)){
     //target = current;
     speed = -75;
   } 
   else if(joystickGetDigital(2, 8, JOY_LEFT)){                                           
     speed = -min(60, max(-60, PID(current, -60, 1, 0.8, 0, 0)));    //holds chainbar right above mobile goal lifter
     //target = current;
   }  
   else if(joystickGetDigital(2, 8, JOY_RIGHT)){
     speed = -min(60, max(-60, PID(current, -180, 1, 0.8, 0, 0)));  //holds chainbar to driver load level
   }
   else {
    speed=0;
    //chainbarPID(current, cbTarget, 0.7, 0.7);
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

static float cascadeLiftStack[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //these two arrays need to be updated with real target values
static float chainBarStack[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //each float in the array corresponds to a number for 
int coneCount = 0;
void opcontrolStack(){
  int chainbarSpeed;
  int cascadeliftSpeed;
  if(joystickGetDigital(1, 7, JOY_UP)){
    coneCount = 0;
  }
  if(joystickGetDigital(1, 7, JOY_LEFT)){
    
  }
}


