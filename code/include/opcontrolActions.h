#pragma once

/**
* Controls the drivetrain motors by mapping joystick analog values to motor speeds
* @param leftSpeed The speed for the left set of drivetrain motors, mapped from the left analog stick on the vexnet joystick
* @param rightSpeed The speed for the right set of drivetrain motors, mapped from the right analog stick on the vexnet joystick
*/
void opcontrolTankDrive();

/**
* Controls the mobile goal motors from four buttons on the vexnet joystick (two directions at two different speeds)
* @param speed The speed for the mobile goal motors to run at
*/
void opcontrolMobileGoal();

/**
* Controls the linear gear motors from two buttons on the partner joystick (two directions up and down)
* @param speed The speed at which to run the linear gear motors at
*/
void opcontrolLinearGear();
void opcontrolConeGrabber();

/**
* Controls the chainbar motors from two buttons on the partner joystick (two directions). The chainbar is also the most problematic
* subsystem we have so uhh yeah
* @param speed The speed at which to run the chainbar motors at
*/
void opcontrolChainBar();
void opcontrolDebug();
void opcontrolStack();

int cbTarget; 