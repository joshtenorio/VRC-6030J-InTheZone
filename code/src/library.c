#include "main.h"

int min(int i1, int i2){
  if(i1 >= i2) return i2;
  else return i1;
}
int max(int i1, int i2){
  if(i1 <= i2) return i2;
  else return i1;
}
int error(float current, float target){
  int d = target - current;
  return d;
}
int runTime(int startTime){
  int elapsedTime = 0;
  const int startTime = millis();
  int currTime = millis();
  elapsedTime = currTime - startTime;
  return elapsedTime;
}
