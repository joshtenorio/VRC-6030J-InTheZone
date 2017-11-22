#pragma once

////////////////
//Sensor Ports//
////////////////
#define SHAFTDRIVE_LB          2,3
#define SHAFTDRIVE_RB          4,5
#define ENCODER_CHAINB         6,7
#define ENCODER_LINEARG        8,9
//any shaft encoder cannot go in port 10
//declaring encoders...
Encoder leftDriveShaft;
Encoder rightDriveShaft;
Encoder encoderChainB;
Encoder shaftLinearGear;

void autoTankDrive(int leftTarget, int rightTarget);
void autoChainBar(int target);
void autoLinearGear(int target);
void autoPloopTest();
void autoTimeTankDrive(int leftSpeed, int rightSpeed, int time);
void autoTimeMobileGoal(int speed, int time);
void autoTimeConeG(int speed, int time);