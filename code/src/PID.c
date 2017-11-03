#include "main.h"

float P(float current, float target, float kP){
  float error = target - current;
  float motorSpeed = error * kP;
  return motorSpeed;
}