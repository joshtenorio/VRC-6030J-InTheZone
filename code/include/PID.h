#pragma once

/**
 * Uses a P controller to calculate the motor speed to
 * achieve/maintain a target sensor reading
 * @param current The current reading from a sensor
 * @param target The desired reading from the same sensor
 * @param kP The constant for the P term
 * @return The motor speed at which to run the mechanism
 */
int P(float current, float target, float kP);


/**
 * Uses a PI controller to calculate the motor speed to
 * achieve/maintain a target sensor reading
 * @param current The current reading from a sensor
 * @param target The desired reading from the same sensor
 * @param kP The constant for the P term
 * @param kI The constant for the I term
 * @return The motor speed at which to run the mechanism
 */
int PI(float current, float target, float kP, float kI);


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
int PID(float current, float target, float kP, float kI, float kD);