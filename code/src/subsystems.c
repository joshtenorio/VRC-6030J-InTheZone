#include "main.h"

void tankDrive(){
	if(abs(joystickGetAnalog(1, 3))>20){
		smartMotorSet(MOTOR_DRIVE_LF, joystickGetAnalog(1, 3));
		smartMotorSet(MOTOR_DRIVE_LB, joystickGetAnalog(1, 3));
	}
	else {
		smartMotorSet(MOTOR_DRIVE_LF, 0);
		smartMotorSet(MOTOR_DRIVE_LB, 0);
	}
	if(abs(joystickGetAnalog(1, MOTOR_DRIVE_LF))>20){
		smartMotorSet(MOTOR_DRIVE_RF, -joystickGetAnalog(1, 2));
		smartMotorSet(MOTOR_DRIVE_RB, -joystickGetAnalog(1, 2));
	}
	else {
		smartMotorSet(MOTOR_DRIVE_RF, 0);
		smartMotorSet(MOTOR_DRIVE_RB, 0);
	}
}

void mobileGoal(){
	if(joystickGetDigital(1, 5, JOY_UP)){
		smartMotorSet(MOTORS_MOGO, 75);
	}
	else {
		if(joystickGetDigital(1, 5, JOY_DOWN)){
			smartMotorSet(MOTORS_MOGO, -75);
		}
		else{
			if(joystickGetDigital(1, 6, JOY_UP)){
				smartMotorSet(MOTORS_MOGO, 100);
			}
			else {
				if(joystickGetDigital(1, 6, JOY_DOWN)){
					smartMotorSet(MOTORS_MOGO, -100  );
				}
				else {
					smartMotorSet(MOTORS_MOGO, 0);
				}
			}
		}
	}
}

void linearGear(){
	if(joystickGetDigital(2, 6, JOY_UP) || 0) {
		smartMotorSet(MOTORS_LINEAR, 100);
	}
	else{
		if(joystickGetDigital(2, 6, JOY_DOWN) || 0){
			smartMotorSet(MOTORS_LINEAR, -50);
		}
		else {
			smartMotorSet(MOTORS_LINEAR, 0);
		}
	}
}

void chainBar(){
	if(joystickGetDigital(2, 5, JOY_UP) || 0){
		smartMotorSet(MOTORS_CHAINB, 100);
	}
	else {
		if(joystickGetDigital(2, 5, JOY_DOWN) || 0){
			smartMotorSet(MOTORS_CHAINB, -100);
		}
		else {
			smartMotorSet(MOTORS_CHAINB, 0);
		}
	}
}

void coneGrabber(){
	if(joystickGetDigital(2, 7, JOY_DOWN) || 0){
		smartMotorSet(MOTOR_CONEG, 90);
	}
	else{
		if(joystickGetDigital(2, 8, JOY_DOWN) || 0){
			smartMotorSet(MOTOR_CONEG, -90);
		}
		else {
			smartMotorSet(MOTOR_CONEG, 0);
		}
	}
}



