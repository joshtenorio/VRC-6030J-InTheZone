#include "main.h"

void tankDrive(int leftSpeed, int rightSpeed){
  smartMotorSet(MOTOR_DRIVE_LF, leftSpeed);
  smartMotorSet(MOTOR_DRIVE_LB, leftSpeed);
  smartMotorSet(MOTOR_DRIVE_RF, -rightSpeed);
  smartMotorSet(MOTOR_DRIVE_RB, -rightSpeed);
}

void mobileGoal(int speed){
  smartMotorSet(MOTORS_MOGO, speed);
}

void linearGear(int speed){
  smartMotorSet(MOTORS_LINEAR, speed);
} 

void chainBar(int speed){
  smartMotorSet(MOTORS_CHAINB, speed);
}

void coneGrabber(int speed){
  smartMotorSet(MOTOR_CONEG, speed);
}
