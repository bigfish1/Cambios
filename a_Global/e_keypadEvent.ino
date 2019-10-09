//  --------------------------------------Void loop

void loop(){

char key = keypad.getKey();


//-------------------------------------Keypad

switch (keypad.getState()){
    case PRESSED:
      
      switch (key)
      {

  case '1' :
        runMotorM1Cw('u');
    

  break;

  case '7':
        runMotorM1Ccw('d');

  break;

  case '3':
        runMotorM2Cw('u');

  break;

  case '9':
        runMotorM2Ccw('d');
      
  break;
  
  case '6':
         runMotorM3Cw('u');

  break;

  case '4':
        runMotorM3Ccw('d');
      
  break;

  case 'A':
        runSpreading();
        Serial.print("Spreading started");
  break;

  case 'D':
        homing();
        Serial.print("Homing started");

  break;
        
      }
  
}

}
  
