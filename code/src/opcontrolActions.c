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
	static int target = 0;
	int current = encoderGet(shaftLinearGear);

	if(joystickGetDigital(2, 6, JOY_UP)){
		speed = 127;
		target = encoderGet(shaftLinearGear);
	} 
	else if(joystickGetDigital(2, 6, JOY_DOWN)){
		speed = -60;
		target = encoderGet(shaftLinearGear);   
	} 
	else {
		//speed = 0;
		speed = -min(120, max(-12, PID(current, target, 2, 0.8, 0, 0)));
		//printf("linear gear value, target, speed: %d, %d, %d\n", encoderGet(shaftLinearGear), target, smartMotorGet(MOTORS_LINEAR));
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
   int current = encoderGet(encoderChainB);
   static int cbTarget = 0; 

   if(joystickGetDigital(2, 5, JOY_UP)){ //move chainbar
     speed = 75; 
	 print("button press");  
	 cbTarget = encoderGet(encoderChainB);
   }
   else if(joystickGetDigital(2, 5, JOY_DOWN)){ //move chainbar
     speed = -75;
	 print("button press");
	 cbTarget = encoderGet(encoderChainB);
   } 
   
   else if(joystickGetDigital(2, 8, JOY_LEFT)){                                           
     speed = -min(60, max(-60, PID(current, -70, 1, 0.8, 0, 0)));    //holds chainbar right above mobile goal lifter (preset)
   }  
   else { //if no chainbar control buttons are being pressed
	   if (current > -15) { //checks if chainbar is resting above mobile goal, if it is will not run PID (dead band)
		   speed=0;
	   }
	   else {
		   speed = -min(60, max(-60, PID(current, cbTarget, 1, 0.9, 0, 0))); //run hold last position PID
		   printf("Chainbar value, target, speed: %d\n, %d, %d\n", encoderGet(encoderChainB), cbTarget, smartMotorGet(MOTORS_CHAINB));
	   }
   } 
   chainBar(speed); //setting speed for chainbar
 }

//static float linearGearStack[3] = {0, 0, 0}; //these two arrays need to be updated with real target values
static float chainBarStack[3] = {0, -25, -36}; //each float in the array corresponds to the number of cones in stack
void opcontrolStack(){
	static int coneCount = 0;  //each float in the array is a target value for each mechanism
	static int buttonState = 0; //refers to down button on vexnet joystick, group 7
	static int prevButtonState = 0; //holds last state of down button vexnet joystick, group 7

	int chainbarSpeed;
	//int linearGearSpeed;
	int coneGrabberSpeed;
	int cbCurrent = encoderGet(encoderChainB);
	//int lgCurrent = encoderGet(shaftLinearGear);
	if(joystickGetDigital(2, 7, JOY_RIGHT)){ //reset cone stack
		coneCount = 0;
	}
	else if(joystickGetDigital(2, 7, JOY_LEFT)){ //hold this to auto stack

		chainbarSpeed = -min(60, max(-60, PID(cbCurrent, -180, 1, 0.8, 0, 0)));
		while (abs(smartMotorGet(MOTORS_CHAINB)) > 20) { //bring chainbar to driver load station
			chainbarSpeed = -min(60, max(-60, PID(cbCurrent, -180, 1, 0.8, 0, 0)));
			delay(1);
		}
		/*
		linearGearSpeed = -min(120, max(-120, PID(lgCurrent, linearGearStack[coneCount], 2, 0.8, 0, 0)));
		while ((abs(smartMotorGet(MOTORS_LINEAR)) > 20)) {
			linearGearSpeed = -min(120, max(-120, PID(lgCurrent, linearGearStack[coneCount], 2, 0.8, 0, 0))); //bring linear gear to driver station level
			delay(1);
		} */
	
		coneGrabberSpeed = 0;
		delay(20);
		coneGrabberSpeed = -90; //this needs speed to pick up cone
		delay(200);
		coneGrabberSpeed = 0;
		/*
		linearGearSpeed = -min(127, max(-127, PID(lgCurrent, linearGearStack[coneCount], 2, 0.8, 0, 0)));
		while ((abs(smartMotorGet(MOTORS_LINEAR)) > 20)) {
			linearGearSpeed = -min(127, max(-127, PID(lgCurrent, linearGearStack[coneCount], 2, 0.7, 0, 0))); //bring linear gear to stack
			delay(1);
		} */

		chainbarSpeed = -min(60, max(-60, PID(cbCurrent, chainBarStack[coneCount], 1, 0.8, 0, 0)));
		while (abs(smartMotorGet(MOTORS_CHAINB)) > 20) { //bring chainbar to mobile goal stack
			chainbarSpeed = -min(60, max(-60, PID(cbCurrent, chainBarStack[coneCount], 1, 0.8, 0, 0)));
			delay(1);
		}
		coneGrabberSpeed = 90; //drop cone
		coneCount += 1;
	}

	//linearGear(linearGearSpeed);
	chainBar(chainbarSpeed);
	coneGrabber(coneGrabberSpeed);
}

void opcontrolDebug() {
	if (joystickGetDigital(2, 7, JOY_UP)) {
		encoderReset(encoderChainB);
		encoderReset(leftDriveShaft);
		encoderReset(rightDriveShaft);
		encoderReset(shaftLinearGear);
	}
}

void opcontrolPanic() {
	if (joystickGetDigital(2, 8, JOY_UP)) {
		tankDrive(0, 0);
		mobileGoal(0);
		linearGear(0);
		chainBar(0);
		coneGrabber(0);
	}
}