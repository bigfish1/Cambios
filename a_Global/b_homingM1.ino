//--------------------------------------------------------------------------------------
//---------------------Keypad set up
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};
byte rowPins[ROWS] = {35,37,39,41};
byte colPins[COLS] = {43,45,47,32};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
 
// Accelstepper setup M1 (3200 Steps/Umdrehung)--------------------------------------------
AccelStepper stepperM1(1, M1_STEP_PIN, M1_DIR_PIN); // 1 = Driver

// Stepper Travel Variables
long  TravelX;  // Used to store the X value entered in the Serial Monitor
int   move_finished = 1;  // Used to check if move is completed
long  initial_homing = -1;  // Used to Home Stepper at startup

long  motor_var1 = 1;



//--------------------------------------------------------------------------------------
// Accelstepper setup M2-----------------------------------------------------------------
AccelStepper stepperM2(1, M2_STEP_PIN, M2_DIR_PIN); // 1 = Driver

// Stepper Travel Variables
long  TravelM2;  // Used to store the X value entered in the Serial Monitor
int   move_finished2=1;  // Used to check if move is completed
long  initial_homing2=1;  // Used to Home Stepper at startup
long  motor_var2 = 1;


//--------------------------------------------------------------------------------------
// --------------------------------------------------Accelstepper setup M3 1/8 microsteps
AccelStepper stepperM3(1, M3_STEP_PIN, M3_DIR_PIN); // 1 = Driver

// Stepper Travel Variables
long  TravelM3;  // Used to store the X value entered in the Serial Monitor
int   move_finished3=1;  // Used to check if move is completed
long  initial_homing3=1;  // Used to Home Stepper at startup
long  motor_var3 = 1;

//--------------------------------------------------------------------------------------
void setup() {
//Keypad
Serial.begin(9600);

//--------------------------------------------------------------------------DC Motor
pinMode(DC_OUTPUT, OUTPUT);

homing();
}

// -----------------------Homing function
void homing(){
// ------------------------------------------------------------------------------StepperM1
stepperM1.setEnablePin(M1_ENABLE_PIN); 
stepperM1.setPinsInverted(false, false, true); //invert logic of enable pin
stepperM1.enableOutputs ();

Serial.begin(9600);  // Start the Serial monitor with speed of 9600 Bauds

pinMode(END_S1, INPUT_PULLUP);

delay(5);  // Wait for EasyDriver wake up


//  Set Max Speed and Acceleration of each Steppers at startup for homing
stepperM1.setMaxSpeed(10000.0);      // Set Max Speed of Stepper (Slower to get better accuracy)
stepperM1.setAcceleration(10000.0);  // Set Acceleration of Stepper
  
// Start Homing procedure of Stepper Motor at startup
Serial.print("Stepper M1 is Homing . . . . . . . . . . . ");

// M1 Move towards the switch S1
while (!digitalRead(END_S1)) {  // Make the Stepper move CCW until the switch is activated
    stepperM1.moveTo(initial_homing);  // Set the position to move to
    initial_homing--;  // Decrease by 1 for next move if needed
    stepperM1.run();  // Start moving the stepper
    
}
stepperM1.stop(); 

stepperM1.setCurrentPosition(0);  // Set the current position as zero for now(Max speed and Accel have to defined again because its set to zero by default)
stepperM1.setMaxSpeed(10000.0);      // Set Max Speed of Stepper (Slower to get better accuracy)
stepperM1.setAcceleration(10000.0);  // Set Acceleration of Stepper
initial_homing=1;                 // Set to 1 because we wanna move ClockWise



//Move away from the swich
while (digitalRead(END_S1)) { // Make the Stepper move CW until the switch is deactivated
    stepperM1.moveTo(initial_homing);  
    stepperM1.run();
    initial_homing++;
  
  }
stepperM1.stop(); //-----------------------------
  
//Homing completed
stepperM1.setCurrentPosition(0);
Serial.println("Homing M1 Completed");
Serial.println(stepperM1.currentPosition ());
stepperM1.setMaxSpeed(10000.0);      // Set Max Speed of Stepper (Faster for regular movements)
stepperM1.setAcceleration(10000.0);  // Set Acceleration of Stepper

//----------------------------------------------------------------------------------Stepper M2
stepperM2.setEnablePin(M2_ENABLE_PIN); 
stepperM2.setPinsInverted(false, false, true); //invert logic of enable pin
stepperM2.enableOutputs();

Serial.begin(9600);  // Start the Serial monitor with speed of 9600 Bauds

pinMode(END_S2, INPUT_PULLUP);

delay(5);  // Wait for EasyDriver wake up

//  Set Max Speed and Acceleration of each Steppers at startup for homing
stepperM2.setMaxSpeed(10000.0);      // Set Max Speed of Stepper (Slower to get better accuracy)
stepperM2.setAcceleration(10000.0);  // Set Acceleration of Stepper
  
// Start Homing procedure of Stepper Motor at startup

Serial.print("Stepper M2 is Homing . . . . . . . . . . . ");

//Move towards the switch
while (!digitalRead(END_S2)) {  // Make the Stepper move CCW until the switch is activated
    stepperM2.moveTo(initial_homing2);  // Set the position to move to
    initial_homing2++;  // Decrease by 1 for next move if needed
    stepperM2.run();  // Start moving the stepper
   
}
stepperM2.setCurrentPosition(0);  // Set the current position as zero for now(Max speed and Accel have to defined again because its set to zero by default)
stepperM2.setMaxSpeed(10000.0);      // Set Max Speed of Stepper (Slower to get better accuracy)
stepperM2.setAcceleration(10000.0);  // Set Acceleration of Stepper
initial_homing2=1;                 // Set to 1 because we wanna move ClockWise

//Move away from the swich
while (digitalRead(END_S2)) { // Make the Stepper move CW until the switch is deactivated
    stepperM2.moveTo(initial_homing2);  
    stepperM2.run();
    initial_homing2--;
   
  }
  
//Homing M2 completed
stepperM2.setCurrentPosition(0);
Serial.println("Homing M2 Completed");
Serial.println("");
stepperM2.setMaxSpeed(10000.0);      // Set Max Speed of Stepper (Faster for regular movements)
stepperM2.setAcceleration(10000.0);  // Set Acceleration of Stepper
 
//----------------------------------------------------------------------------------------------Stepper M3

stepperM3.setEnablePin(M3_ENABLE_PIN); 
stepperM3.setPinsInverted(false, false, true); //invert logic of enable pin
stepperM3.enableOutputs();

Serial.begin(9600);  // Start the Serial monitor with speed of 9600 Bauds

pinMode(END_S3, INPUT_PULLUP);

delay(5);  // Wait for EasyDriver wake up

//  Set Max Speed and Acceleration of each Steppers at startup for homing
stepperM3.setMaxSpeed(10000.0);      // Set Max Speed of Stepper (Slower to get better accuracy)
stepperM3.setAcceleration(10000.0);  // Set Acceleration of Stepper
  
// Start Homing procedure of Stepper Motor at startup
Serial.print("Stepper M3 is Homing . . . . . . . . . . . ");

//Move towards the switch
while (!digitalRead(END_S3)) {  // Make the Stepper move CCW until the switch is activated
    stepperM3.moveTo(initial_homing3);  // Set the position to move to
    initial_homing3--;  // Decrease by 1 for next move if needed
    stepperM3.run();  // Start moving the stepper
    
}
stepperM3.setCurrentPosition(0);  // Set the current position as zero for now(Max speed and Accel have to defined again because its set to zero by default)
stepperM3.setMaxSpeed(10000.0);      // Set Max Speed of Stepper (Slower to get better accuracy)
stepperM3.setAcceleration(10000.0);  // Set Acceleration of Stepper
initial_homing3=1;                 // Set to 1 because we wanna move ClockWise

//Move away from the swich
while (digitalRead(END_S3)) { // Make the Stepper move CW until the switch is deactivated
    stepperM3.moveTo(initial_homing3);  
    stepperM3.run();
    initial_homing3++;
    
  }
  
//Homing M3 completed
stepperM3.setCurrentPosition(0);
Serial.println("Homing M3 Completed");
Serial.println("");
stepperM3.setMaxSpeed(10000.0);      // Set Max Speed of Stepper (Faster for regular movements)
stepperM3.setAcceleration(100000.0);  // Set Acceleration of Stepper  

}
