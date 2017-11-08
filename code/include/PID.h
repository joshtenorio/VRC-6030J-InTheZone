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