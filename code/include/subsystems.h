#pragma once

////////////////////
//Controller Ports//
////////////////////
#define VEXNET_JOY  1
#define PARTNER_JOY 2
#define JOY_X_AXIS 
#define JOY_Y_AXIS


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
#define SHAFTDRIVE_LB_TOP //WARNING SHAFT ENCODERS (ANY PORT, TOP OR BOT) CAN NOT GO ON
#define SHAFTDRIVE_LB_BOT //PORT 10!!!!!!!!!!
#define SHAFTDRIVE_RB_TOP
#define SHAFTDRIVE_RB_BOT

#define SHAFT_CHAINB_TOP
#define SHAFT_CHAINB_BOT
#define POT_CONEG

//Declaring encoders
Encoder DriveEncoderR
Encoder DriveEncoderL
Encoder ChainEncoder


////////////////////////////////////////////////
//Subsystems called in opcontrol.c and auto.c //
////////////////////////////////////////////////
void tankDrive();
void mobileGoal();
void linearGear();
void chainBar();
void coneGrabber();
void goForwardAuto();




