#pragma once

                    // ID, kP, kI, kD
#define PID_DRIVETRAIN  0, 0.2, 0, 0
#define PID_LINEARGEAR  2, 0.5, 0, 0

#define PID_CHAINBAR 0.4, 0.7 


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
int PID(float current, float target, int mechanismIdentifier, float kP, float kI, float kD);

/**
 * Uses a specific P controller to calculate motor speed for chainbar to
 * achieve/maintain a target chainbar encoder reading
 * @param current The current reading from the chainbar encoder
 * @param target The desired reading from the chainbar encoder
 * @param wgkP The constant for the P term when chainbar is going down
 * @param agkP The constant for the P term when chainbar is going up
 * @return The motor speed at which to run the chainbar
 */
int chainbarPID(int current, int target, float wgkP, float agkP);