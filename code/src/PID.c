#include "main.h"

int P(float current, float target, float kP){
  float error = target - current;
  int motorSpeed = error * kP;
  return motorSpeed;
}

float PI(float target, float current, float kP, float kI) {
  
}