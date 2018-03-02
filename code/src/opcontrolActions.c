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
     speed = 65; 

	 cbTarget = encoderGet(encoderChainB);
   }
   else if(joystickGetDigital(2, 5, JOY_DOWN)){ //move chainbar
     speed = -65;

	 cbTarget = encoderGet(encoderChainB);
   } 
   
   else if(joystickGetDigital(2, 8, JOY_LEFT)){                                           
     speed = min(60, max(-60, PID(current, 70, 1, 0.8, 0, 0)));    //holds chainbar right above mobile goal lifter (preset)
	 cbTarget = encoderGet(encoderChainB);
	 printf("Chainbar value, 70, speed: %d\n, %d, %d\n", encoderGet(encoderChainB), 70, smartMotorGet(MOTORS_CHAINB));
   }  
   else { //if no chainbar control buttons are being pressed
	   if (cbTarget > -15) { //checks if chainbar is resting above mobile goal, if it is will not run PID (dead band)
		   speed=0;
	   }
	   else {
		   speed = min(60, max(-60, PID(current, cbTarget, 1, 0.6, 0, 0))); //run hold last position PID
		   printf("Chainbar value, target, speed: %d\n, %d, %d\n", encoderGet(encoderChainB), cbTarget, smartMotorGet(MOTORS_CHAINB));
	   }
   } 
   chainBar(speed); //setting speed for chainbar
 }


static int chainBarStack[4] = {0, 25, 36, 36}; //each float in the array corresponds to the number of cones in stack
void opcontrolStack(){
	static int coneCount = 0;  //each float in the array is a target value for each mechanism
	int cbCurrent = encoderGet(encoderChainB);

	if(joystickGetDigital(2, 7, JOY_RIGHT)){ //reset cone stack variable
		coneCount = 0;
	}
	else if(joystickGetDigital(2, 7, JOY_LEFT)){ //hold this to auto stack


		chainBar(min(60, max(-60, PID(cbCurrent, chainBarStack[coneCount], 1, 0.8, 0, 0))));
		while (abs(smartMotorGet(MOTORS_CHAINB)) > 30) { //bring chainbar to mobile goal stack
			cbCurrent = encoderGet(encoderChainB);
			chainBar(min(60, max(-60, PID(cbCurrent, chainBarStack[coneCount], 1, 0.8, 0, 0))));
			if ((abs(chainBarStack[coneCount] - cbCurrent) <= 40) || (joystickGetDigital(2, 8, JOY_UP))) {
				break;
			}
			printf("chainbar speed, target, 190, current, cone count: %d %d, %d, %d, %d\n", smartMotorGet(MOTORS_CHAINB), chainBarStack[coneCount], 190, encoderGet(encoderChainB), coneCount);
			delay(1);
		}
		delay(400);
		coneGrabber(90); //dropping cone

		coneCount += 1;
		printf("//////////////coneCount = %d\n", coneCount);

		chainBar(min(60, max(-60, PID(cbCurrent, 190, 1, 0.8, 0, 0))));
		while (abs(smartMotorGet(MOTORS_CHAINB)) > 30) { //bring chainbar to driver load station
			cbCurrent = encoderGet(encoderChainB);
			chainBar(min(60, max(-60, PID(cbCurrent, 190, 1, 0.8, 0, 0))));
			printf("CHAINBAR speed, 190, current: %d, %d, %d\n", smartMotorGet(MOTORS_CHAINB), 190, encoderGet(encoderChainB));
			if ((abs(190 - cbCurrent) <= 40) || (joystickGetDigital(2, 8, JOY_UP))) {
				break;
			}
			delay(1);
		}

		coneGrabber(0);
		delay(20);
		coneGrabber(-90); //this needs speed to pick up cone
		delay(400);
		coneGrabber(0);


	}
	else { //if autostack isn't running, run normal chainbar/conegrabber opcontrol functions
		opcontrolChainBar();
		opcontrolConeGrabber();
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

void opcontrolDebug() {
	if (joystickGetDigital(2, 7, JOY_UP)) {
		encoderReset(encoderChainB);
		encoderReset(leftDriveShaft);
		encoderReset(rightDriveShaft);
		encoderReset(shaftLinearGear);
	}
}

