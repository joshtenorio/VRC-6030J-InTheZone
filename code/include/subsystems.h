#pragma once

///////////////
//Motor Ports//
///////////////
#define MOTOR_DRIVE_LF   2
#define MOTOR_DRIVE_LB   7
#define MOTOR_DRIVE_RF   3
#define MOTOR_DRIVE_RB   6
#define MOTORS_LINEAR    4  // Y-cabled to L&R motors (R is wiring-reversed)
#define MOTORS_MOGO      8  // Y-cabled to L&R motors (R is wiring-reversed)
#define MOTOR_CONEG      5  // Connected through Power Expander A
#define MOTORS_CHAINB    9  // Y-cabled through Power Expander B&C to L&R motors, respectively (R is wiring-reversed)



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

///////////////////////
//PrOtOtYpE fUnCtIoNs//
///////////////////////
void tankDrive(int leftSpeed, int rightSpeed);
void mobileGoal(int speed);
void linearGear(int speed);
void chainBar(int speed);
void coneGrabber(int speed);
void conceptChainBar();
/*purpose of this autoReset is to bring chainbar on opposite
side of the mobile goal lifter. To do this, bring linear gear to highest
position and bring chainbar over, then lower linear gear. This means that
it'll be easier to get more cones since this function resets the linear gear
and chainbar position to the "get cones" position
*/
//void autoReset();


