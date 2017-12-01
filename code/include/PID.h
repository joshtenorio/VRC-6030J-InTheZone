#pragma once

                    // ID,   kP,   kI,   kD
#define PID_DRIVETRAIN  0,    0,    0,    0
#define PID_CHAINBAR    1,  0.7,    0,    0
#define PID_LINEARGEAR  2,    0,    0,    0


/**
 * Uses a PID controller to calculate the motor speed to
 * achieve/maintain a target sensor reading
 * @param current The current reading from a sensor
 * @param target The desired reading from the same sensor
 * @param kP The constant for the P term
 * @param kI The constant for the I term
 * @param kD The constant for the D term
 * @return The motor speed at which to run the mechanism
 */
int PID(float current, float target, unsigned short mechanismIdentifier, float kP, float kI, float kD);