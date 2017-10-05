#include "main.h"

//declare global variables
//////////////////////////
int slewTmp;
int slewTarget[10];

//////////////////////////
//// Other Variables /////
//////////////////////////


//////////////////////////
//// Helper Functions ////
//////////////////////////
int min(int i1, int i2){
  if(i1>=i2) return i2;
  else return i1;
}

int max(int i1, int i2){
  if(i1<=i2) return i2;
  else return i1;
}

void slewControlTask (void * parameter) {
  //Slew rate control (run as task in init.c)
  //works together with smartMotorSet -- always use smartMotorSet!
  extern int slewTmp;
  extern int slewTarget[10];
  while (1) {
    //if (isEnabled ()) {//only runs if competition switch is enabled
    for (int i = 0; i < 10; i++) { //Cycle through each motor port
      slewTmp = motorGet(i+1); //returns the last speed sent to the motor
      slewTmp += min(15, abs(slewTarget[i]-slewTmp))*(slewTarget[i]-slewTmp)/abs(slewTarget[i]-slewTmp);
      motorSet (i+1, slewTmp);
    }//}
  wait (20);
}}

void smartMotorSet(int motor, int cmd){
  //uses slewControlTask, which needs to be running in the background or nothing will happen
  extern int slewTarget[10];
  if(abs(cmd)<15) cmd=0;
  slewTarget[motor-1]=cmd;
}

////////////////////////////////////////
////Functions Called by opcontrol.c ////
////////////////////////////////////////
void tankdrive(){
	if(abs(joystickGetAnalog(JS_VEXNET, JS_Right_y))>20) { 
		smartMotorSet(DRIVETRAIN_RB, joystickGetAnalog(JS_VEXNET, JS_Right_y));
		smartMotorSet(DRIVETRAIN_RF, joystickGetAnalog(JS_VEXNET, JS_Right_y));
	}
	else {
		smartMotorSet(DRIVETRAIN_RB, 0);
		smartMotorSet(DRIVETRAIN_RF, 0);
	}
	if(abs(joystickGetAnalog(JS_VEXNET, JS_Left_y))>20) {
		smartMotorSet(DRIVETRAIN_LB, -joystickGetAnalog(JS_VEXNET, JS_Left_y));
		smartMotorSet(DRIVETRAIN_LF, -joystickGetAnalog(JS_VEXNET, JS_Left_y));
	}
	else {
		smartMotorSet(DRIVETRAIN_LB, 0);
		smartMotorSet(DRIVETRAIN_LF, 0);
	}                                                             
	delay(20);
}
void conegrabber(void) { 
	if(joystickGetDigital(JS_VEXNET, SHOULDER_R, JOY_UP)) { 
		smartMotorSet(CONEGRAB, 32);    
	}
	else if(joystickGetDigital(JS_VEXNET, SHOULDER_R, JOY_DOWN)) { 
		smartMotorSet(CONEGRAB, -32);
	}
	else {
		smartMotorSet(CONEGRAB, 0); 
	}
	delay(20);	
}
void lineargear(void) { 
	if(joystickGetAnalog(JS_VEXNET, JS_RIGHT_X)>60) { //linear gear code is set for half speed
		smartMotorSet(LINEARGEAR, joystickGetAnalog(JS_VEXNET, JS_RIGHT_X)-60);
	}
	else if(joystickGetAnalog(JS_VEXNET, JS_RIGHT_X)<-60) {
		smartMotorSet(LINEARGEAR, joystickGetAnalog(JS_VEXNET, JS_RIGHT_X)+60);
	}
	else {
		smartMotorSet(LINEARGEAR_R, 0);
	}
		delay(20);
}
void calibrate(void) {
	if(joystickGetDigital(JS_VEXNET, DPAD_L, JOY_UP)) { //IMPORTANT!!! MUST HOLD THIS FOR AT LEAST ONE FULL SECOND
		analogCalibrate(POTGOAL); 
		analogCalibrate(POTCHAIN);
		analogCalibrate(POTCONE);
	}
}
void goalgrabber(void) {  //i have a concept for a P loop for more control this 
	if(joystickGetDigital(JS_VEXNET, SHOULDER_L, JOY_DOWN)) {
		smartMotorSet(GOALGRAB, 25);
	}
	else if(joystickGetDigital(JS_VEXNET, SHOULDER_L, JOY_UP)) {
		smartMotorSet(GOALGRAB, -25);
	}
	else {
		smartMotorSet(GOALGRAB, 0);
	}
}
void ploopliftgoal(void) {
	while(joystickGetDigital(1, 5, JOY_DOWN) {
		int kP = .1;
		int loadGoal = <when mob goal lifter is dropped & can load the mob goal>
		int currValue1 = analogReadCalibrated(POTGOAL)
		int currError1 = loadGoal - currValue1
		int currSpeed1 = kP * currError1

		smartMotorSet(GOALGRAB, currSpeed1);
	}
	while(joystickGetDigital(1, 5, JOY_UP) {
		int kP = .1;
		int moveGoal = <when mob goal lifter is carried and lifted off the ground>
		int currValue2 = analogReadCalibrated(POTGOAL)
		int currError2 = moveGoal - currValue2
		int currSpeed2 = kP * currError2

		smartMotorSet(GOALGRAB, currSpeed2);
		}
	}

void chainbar(void) {  
	if(joystickGetAnalog(JS_VEXNET, JS_LEFT_Y)>50) {
		smartMotorSet(CHAINBAR, joystickGetAnalog(JS_VEXNET, JS_LEFT_Y)-50);
	}
	else if(joystickGetAnalog(JS_VEXNET, JS_LEFT_Y)<-50) {
		smartMotorSet(CHAINBAR, joystickGetAnalog(JS_VEXNET, JS_LEFT_Y)+50);
	}
	else {
		smartMotorSet(CHAINBAR, 0);
	}
}

/*
I'm just a Jester,
it's jest me.

I'm an idiota 
In a tree.

I go to Worlds
And the earth cries in shame.
-Jestme.txt
*/
////////////////////////////////////////
//////Functions called by auto.c ///////
////////////////////////////////////////
void plooptest1(void) {
	int kP = .1;
	int desiredValue = 2700;

while(getEncoder(driveEncoderR) <= desiredValue) {
	int currValue3 = getEncoder(driveEncoderR);
	int currError3 = desiredValue - currValue3;
	int currSpeed3 = kP * currError3;

	motorSet(DRIVETRAIN_LB, CurrSpeed3);
	motorSet(DRIVETRAIN_LF, CurrSpeed3);
	motorSet(DRIVETRAIN_RB, CurrSpeed3);
	motorSet(DRIVETRAIN_RF, CurrSpeed3);
	delay(25);
}

}
void timedelay1(void) {
	smartMotorSet(DRIVETRAIN_LB, 127);
	smartMotorSet(DRIVETRAIN_RB, 127);
	smartMotorSet(DRIVETRAIN_LF, 127);
	smartMotorSet(DRIVETRAIN_RF, 127);
	delay(3000);
	motorStop(DRIVETRAIN_RB);
	motorStop(DRIVETRAIN_LB);
	motorStop(DRIVETRAIN_RF);
	motorStop(DRIVETRAIN_LF);
	delay(10);
}