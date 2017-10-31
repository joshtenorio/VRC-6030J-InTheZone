#pragma once

////////////////////
//Controller Ports//
////////////////////
#define VEXNET_JOY         1
#define PARTNER_JOY        2
#define JOY_L_X_AXIS       4
#define JOY_L_Y_AXIS       3
#define JOY_R_X_AXIS       1
#define JOY_R_Y_AXIS       2
#define JOY_L_BUMPER       5
#define JOY_R_BUMPER       6
#define JOY_L_BUTTONGROUP  7
#define JOY_R_BUTTONGROUP  8


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
#define SHAFTDRIVE_CHAINB      6,7
#define SHAFTDRIVE_CONEG       8,9
//any shaft encoder cannot go in port 10

#define SHAFT_CHAINB 
#define POT_CONEG

void tankDrive();
void mobileGoal();
void linearGear();
void chainBar();
void coneGrabber();


