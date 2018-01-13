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
	 print("button press");
   }
   else if(joystickGetDigital(2, 5, JOY_DOWN)){
     //target = current;
     speed = -75;
	 print("button press");
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

static float linearGearStack[10] = {0, 0, 0, 150, 0, 0, 0, 0, 0, 0}; //these two arrays need to be updated with real target values
static float chainBarStack[10] = {0, -25, -36, -20, 0, 0, 0, 0, 0, 0}; //each float in the array corresponds to the number of cones in stack
int coneCount = 0;  //each float in the array is a target value for each mechanism
int buttonState = 0; //refers to down button on vexnet joystick, group 7
int prevButtonState = 0; //holds last state of down button vexnet joystick, group 7
void opcontrolStack(){
	int chainbarSpeed;
	int linearGearSpeed;
	int coneGrabberSpeed;
	int cbCurrent = encoderGet(encoderChainB);
	int lgCurrent = encoderGet(shaftLinearGear);
	if(joystickGetDigital(1, 7, JOY_UP)){ //reset cone stack
		coneCount = 0;
	}
	else if(joystickGetDigital(1, 7, JOY_LEFT)){ //hold this to auto stack

		chainbarSpeed = -min(60, max(-60, PID(cbCurrent, -180, 1, 0.8, 0, 0)));
		while (abs(smartMotorGet(MOTORS_CHAINB)) > 20) { //bring chainbar to driver load station
			chainbarSpeed = -min(60, max(-60, PID(cbCurrent, -180, 1, 0.8, 0, 0)));
			delay(1);
		}

		linearGearSpeed = -min(127, max(-127, PID(lgCurrent, linearGearStack[coneCount], 2, 0.8, 0, 0)));
		while ((abs(smartMotorGet(MOTORS_LINEAR)) > 20)) {
			linearGearSpeed = -min(127, max(-127, PID(lgCurrent, linearGearStack[coneCount], 2, 0.8, 0, 0))); //bring linear gear to driver station level
			delay(1);
		}
	
		coneGrabberSpeed = 0;
		delay(20);
		coneGrabberSpeed = -90; //this needs speed to pick up cone
		delay(200);
		coneGrabberSpeed = 0;

		linearGearSpeed = -min(127, max(-127, PID(lgCurrent, linearGearStack[coneCount], 2, 0.8, 0, 0)));
		while ((abs(smartMotorGet(MOTORS_LINEAR)) > 20)) {
			linearGearSpeed = -min(127, max(-127, PID(lgCurrent, linearGearStack[coneCount], 2, 0.7, 0, 0))); //bring linear gear to stack
			delay(1);
		}

		chainbarSpeed = -min(60, max(-60, PID(cbCurrent, chainBarStack[coneCount], 1, 0.8, 0, 0)));
		while (abs(smartMotorGet(MOTORS_CHAINB)) > 20) { //bring chainbar to mobile goal stack
			chainbarSpeed = -min(60, max(-60, PID(cbCurrent, chainBarStack[coneCount], 1, 0.8, 0, 0)));
			delay(1);
		}
		coneGrabberSpeed = 90; //drop cone
		coneCount += 1;
	}

	linearGear(linearGearSpeed);
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
	else if (joystickGetDigital(1, 7, JOY_DOWN)) { //remove a cone from stack (need to find a way to only happen once for one button press)
		chainBar(0);
		linearGear(0);
		coneGrabber(0);
		print("button press");
	}

	if (buttonState != prevButtonState) { //if button state doesn't equal previous button state
		if (buttonState == 1) { //if button state has been pressed
			coneCount -= 1;
			print("cone removed");
			buttonState = 0;
			prevButtonState = buttonState; //setting previous button state to current button state
		}
	}

}