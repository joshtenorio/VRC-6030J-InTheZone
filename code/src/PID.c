#include "main.h"

unsigned long startTimes[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
float targetOld[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int PID(float current, float target, int mechanismIdentifier, float kP, float kI, float kD){
  if(target != targetOld[mechanismIdentifier] || startTimes[mechanismIdentifier] == 0){
    startTimes[mechanismIdentifier] = millis();
    targetOld[mechanismIdentifier] = target;
  }
  //long elapsedTime = runTime(startTimes[mechanismIdentifier]);
  
  float currError = target - current;
  /*float error[2] = {0,0}; //left to right = recent to old
  if(error[0] != error[1]){
    error[1] = error[0];
    error[0] = currError;
  }
  float integral = integral + error[0]*elapsedTime;
  float derivative = */

  float pTerm = kP*currError;
  float iTerm = kI*0;
  float dTerm = kD*0;
  int motorSpeed = pTerm + iTerm + dTerm;
  return motorSpeed;
}


int chainbarPID(int current, int target, float wgkP, float agkP){
  float currError = target - current; //float because multiplied by kP
  
  if(currError*current < 0){ //against gravity
    return agkP*currError;
  } 
  else { //with gravity
    return wgkP*currError;  
  }
  
}

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
/*
  const long startTime = millis();
  float elapsedTime = (float)runTime(startTime);
  float errror = target - current;
  float error[2] = {0,0};
  if(errror != error[0]){
    error[1] = error[0];
    error[0] = errror;
  }
  float integral = integral + errror*elapsedTime;
  float derivative = (error[1] - error[0]) / elapsedTime;
  float pTerm = errror*kP;
  float iTerm = kI*integral;
  float bias = 0;       //what
  float dTerm = kD*derivative + bias;
  float motorSpeed = pTerm + iTerm + dTerm;
  return (int)motorSpeed;
}


int P(float current, float target, float kP){         //HAVE SOMEONE CHECK THESE
  float error = target - current;
  float motorSpeed = error * kP;
  return (int)motorSpeed;
}

int PI(float current, float target, float kP, float kI){
  int startTime = 0;
  float targetOld = 0;
  if(target != targetOld){
    startTime = millis();
    targetOld = target;
  }
  float error = target - current;
  float elapsedTime = (float)runTime(startTime);
  float integral += error*elapsedTime;
  float pTerm = kP*error;
  float iTerm = kI*integral;
  float motorSpeed = pTerm + iTerm;
  return (int)motorSpeed;

*/
