#include "main.h"

void tankDrive(short leftSpeed, short rightSpeed){
  smartMotorSet(MOTOR_DRIVE_LF, leftSpeed);
  smartMotorSet(MOTOR_DRIVE_LB, leftSpeed);
  smartMotorSet(MOTOR_DRIVE_RF, -rightSpeed);
  smartMotorSet(MOTOR_DRIVE_RB, -rightSpeed);
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
          smartMotorSet(MOTORS_MOGO, -100 );
        }
        else {
          smartMotorSet(MOTORS_MOGO, 0);
        }
      }
    }
  }
}

void linearGear(){
  if(joystickGetDigital(2, 6, JOY_UP)){
    smartMotorSet(MOTORS_LINEAR, 70);
  }
  else{
    if(joystickGetDigital(2, 6, JOY_DOWN)){
      smartMotorSet(MOTORS_LINEAR, -50);
    }
    else {
      smartMotorSet(MOTORS_LINEAR, 0);
    }
  }
}

void chainBar(){
  if(joystickGetDigital(2, 5, JOY_UP)){
    smartMotorSet(MOTORS_CHAINB, 100);
  }
  else {
    if(joystickGetDigital(2, 5, JOY_DOWN)){
      smartMotorSet(MOTORS_CHAINB, -100);
    }
    else {
      smartMotorSet(MOTORS_CHAINB, 0);
    }
  }
}

void coneGrabber(){
  if(joystickGetDigital(2, 7, JOY_DOWN)){
    smartMotorSet(MOTOR_CONEG, 90);
  }
  else{
    if(joystickGetDigital(2,8, JOY_DOWN)){
      smartMotorSet(MOTOR_CONEG, -90);
    }
    else {
      smartMotorSet(MOTOR_CONEG, 0);
    }
  }
}




