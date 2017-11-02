#pragma once

////////////////
//Sensor Ports//
////////////////
#define SHAFTDRIVE_LB          2,3
#define SHAFTDRIVE_RB          4,5
#define SHAFTDRIVE_CHAINB      6,7
#define SHAFTDRIVE_CONEG       8,9
//any shaft encoder cannot go in port 10
//declaring encoders...
Encoder leftdriveshaft;
Encoder rightdriveshaft;
Encoder shaftchainb;
Encoder shaftconeg;