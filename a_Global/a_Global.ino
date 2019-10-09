
//----------------------------------Included libraries
#include <AccelStepper.h>
#include <Keypad.h>
#include <Key.h>

//------------------------------------------------Pin definition For RAMPS 1.4

//stepperM1 Pin definition

#define M1_DIR_PIN          55
#define M1_STEP_PIN         54
#define M1_ENABLE_PIN       38
#define END_S1               2

long SoftEndM1 =95000; //---Softend M1 Cw  (movement DOWN)
int m11 = 4000;  //--------------------------------------------------------------------------(Pulverzustellung in Steps)

//stepperM2 Pin definition

#define M2_DIR_PIN          61
#define M2_STEP_PIN         60
#define M2_ENABLE_PIN       56
#define END_S2              15

long SoftEndM2 = -100000; //Softend M2 CCW (movement platform DOWN)
int m22 = 3000; //------------------------------------------------------------------------------(Schichthöhe in Steps)

//stepperM3 Pin definition

#define M3_DIR_PIN          48
#define M3_STEP_PIN         46
#define M3_ENABLE_PIN       62
#define END_S3              19

long SoftEndM3 = 36000;
int m33 = 33500; //---------------Spreedingdistanz (obere Grenze)

//DC motor Pin definition

#define DC_OUTPUT           10
