#include "main.h"

int P(float current, float target, float kP){
  float error = target - current;
  int motorSpeed = error * kP;
  return motorSpeed;
}

int PI(float current, float target, float kP, float kI){
  const int startTime = millis();
  float error = target - current;
  int elapsedTime = runTime(startTime);
  float integral += error*elapsedTime;
  float pTerm = kP*error;
  float iTerm = kI*integral;
  int motorSpeed = pTerm + iTerm;
  return motorSpeed;
}

int PID(float current, float target, float kP, float kI, float kD){
  const int startTime = millis();
  float errror = target - current;
  int elapsedTime = runTime(startTime);
  float error[2] = {0,0};
  if(errror != error[0]){
    error[1] = error[0];
    error[0] = errror;
  }
  float integral = integral + error*runTime;
  float derivative = (error[1] - error[0]) / runTime;
  float pTerm = error*kP;
  float iTerm = kI*integral;
  //float dTerm = 
  //int motorSpeed = pTerm + iTerm + dTerm;
  //return motorSpeed;
}
