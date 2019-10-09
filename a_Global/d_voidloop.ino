
// ----------------------------------------M1 function CW

void runMotorM1Cw(char sens)
{
  char rkey;
  
  if(sens=='u')
  {
    rkey='E';
    
    while(rkey!='1' && stepperM1.currentPosition() != SoftEndM1)
    {
      rkey='E';
      stepperM1.moveTo(stepperM1.currentPosition()+1); 
      //motor_var1++;
      stepperM1.setMaxSpeed(100000.0);      // Set Max Speed of Stepper (Faster for regular movements)
      stepperM1.setAcceleration(100000000000.0);  // Set Acceleration of Stepper
      stepperM1.run();
      rkey = keypad.getKey();
    }
    Serial.println("m1 pos");
    Serial.println(stepperM1.currentPosition());
      

        stepperM1.stop();
   
  }
}

//-----------------------------------M1 function CCW
void runMotorM1Ccw(char sens)
{
  char rkey;
  
  if(sens=='d')
  {
   rkey='E';
   
   while(rkey!='7' && !digitalRead(END_S1))
    {
      rkey='E';
      stepperM1.moveTo(stepperM1.currentPosition()-1); 
      stepperM1.setMaxSpeed(100000.0);      // Set Max Speed of Stepper (Faster for regular movements)
      stepperM1.setAcceleration(100000000000.0);  // Set Acceleration of Stepper
      stepperM1.run();
      rkey = keypad.getKey();      
    }

        stepperM1.stop();
        
    }
  }

//-------------------------------------------M2 function CW
void runMotorM2Cw(char sens)
{
  char rkey2;
  
  if(sens=='u')
  {
    rkey2='E';
    while(rkey2!='3' && !digitalRead(END_S2))
    {
      rkey2='E';
      stepperM2.moveTo(stepperM2.currentPosition()+1); 
      stepperM2.setMaxSpeed(1000000.0);      // Set Max Speed of Stepper (Faster for regular movements)
      stepperM2.setAcceleration(100000000000.0);  // Set Acceleration of Stepper
      stepperM2.run();
      rkey2 = keypad.getKey();
    }
    
    Serial.println(stepperM2.currentPosition());

        stepperM2.stop();
       
    
  }
}
//-----------------------------------------M2 function CCW
void runMotorM2Ccw(char sens)
{
  char rkey2;
 
  
  if(sens=='d')
  {
   rkey2='E';
   while(rkey2!='9' && stepperM2.currentPosition() != SoftEndM2)
    {
      rkey2='E';
      stepperM2.moveTo(stepperM2.currentPosition()-1); 
      stepperM2.setMaxSpeed(1000000.0);      // Set Max Speed of Stepper (Faster for regular movements)
      stepperM2.setAcceleration(100000000000.0);  // Set Acceleration of Stepper
      stepperM2.run();
      rkey2 = keypad.getKey();
    
    }

        stepperM2.stop();
       
 
    }
      Serial.println("M2 Position");
      Serial.println(stepperM2.currentPosition());
  }
//------------------------------------------ M3 function CW
void runMotorM3Cw(char sens)
{
  char rkey3;
    
  if(sens=='u')
  {
    rkey3='E';
    
    while(rkey3!='6' && stepperM3.currentPosition()!= SoftEndM3) 
    {
      rkey3='E';
      stepperM3.moveTo(stepperM3.currentPosition()+1); 
      stepperM3.setMaxSpeed(20000000.0);      // Set Max Speed of Stepper (Faster for regular movements)
      stepperM3.setAcceleration(100000000000.0);  // Set Acceleration of Stepper
      stepperM3.run();
      rkey3 = keypad.getKey();  
    }
    Serial.println(stepperM3.currentPosition());
    
      
        stepperM3.stop();
        
      
  }
}
//-------------------------------------function M3 CCW
void runMotorM3Ccw(char sens)
{
  char rkey3;
  if(sens=='d')
  {
   rkey3='E';
   while(rkey3!='4' && !digitalRead(END_S3) )
    {
      rkey3='E';
      stepperM3.moveTo(stepperM3.currentPosition()-1); 
      stepperM3.setMaxSpeed(20000000.0);      // Set Max Speed of Stepper (Faster for regular movements)
      stepperM3.setAcceleration(100000000000.0);  // Set Acceleration of Stepper
      stepperM3.run();
      rkey3 = keypad.getKey();
      
    }
    Serial.println(stepperM3.currentPosition());
    

        stepperM3.stop();     
        
  
    }
  }
//-----------------------------------------------------------Spreeding function

   void runSpreading(){
    
//    int m2 = -2000;
//    int m3 = 2000;
   
// --------------------Stepper M1 CCW (Platform UP)       

//stepperM1.setCurrentPosition(0);
long M1move = stepperM1.currentPosition() + m11;
//int M1move =  m11;
//int SoftEndM1Spreeding = 

while( stepperM1.currentPosition() != SoftEndM1 && stepperM1.currentPosition() < SoftEndM1 && M1move - stepperM1.currentPosition() != 0 )
    {
           
      stepperM1.move(stepperM1.currentPosition()+1); 
      stepperM1.setMaxSpeed(100000.0);      // Set Max Speed of Stepper (Faster for regular movements)
      stepperM1.setAcceleration(100000000000.0);  // Set Acceleration of Stepper
      stepperM1.run();
      
    }
      stepperM1.stop();
    
    Serial.println("m1 pos");
    Serial.println(stepperM1.currentPosition());
      
     

// -------------------Stepper M2 CCW (Platform DOWN)
        
long M2move= stepperM2.currentPosition() - m22;
      
while( stepperM2.currentPosition() != SoftEndM2 && stepperM2.currentPosition() > SoftEndM2 && M2move - stepperM2.currentPosition() != 0 )
    
    {  
      stepperM2.move(stepperM2.currentPosition()-1); 
      stepperM2.setMaxSpeed(100000.0);      // Set Max Speed of Stepper (Faster for regular movements)
      stepperM2.setAcceleration(100000000000.0);  // Set Acceleration of Stepper
      stepperM2.run();
      
     
    }
      stepperM2.stop();
    
    Serial.println("m2 pos");
    Serial.println(stepperM2.currentPosition());
        
         
// --------------------DC Motor ON + M3 moving CW

     
      Serial.println("M3 Start");

//--------------------------------------------------Stepper M3 homing position
while( !digitalRead(END_S3))
      {
      stepperM3.moveTo(stepperM3.currentPosition()-1);
      stepperM3.setMaxSpeed(20000000.0);      // Set Max Speed of Stepper (Faster for regular movements)
      stepperM3.setAcceleration(100000000000.0);  // Set Acceleration of Stepper
      stepperM3.run();
      }
      stepperM3.setCurrentPosition(0);

//-----------------------------------------------------DC Motor ON
 Serial.println("DC Motor läuft");
      
      analogWrite(DC_OUTPUT, 140);

//---------------------------------------------------stepperM3 Spreading
int M3move= stepperM3.currentPosition() + m33;
      while( stepperM3.currentPosition() != SoftEndM3 && stepperM3.currentPosition() < SoftEndM3 && M3move - stepperM3.currentPosition() != 0)
    {
      stepperM3.moveTo(stepperM3.currentPosition()+1); 
      stepperM3.setMaxSpeed(20000000.0);      // Set Max Speed of Stepper (Faster for regular movements)
      stepperM3.setAcceleration(100000000000.0);  // Set Acceleration of Stepper
      stepperM3.run();
      
    }
    
      
    stepperM3.stop();
    Serial.println("m3 pos");
    Serial.println(stepperM3.currentPosition());
      
      
//------------------ DC Motor OFF
     Serial.println("DC Motor ist OFF");
     analogWrite(DC_OUTPUT, LOW);
    
     delay(2000); //

            
 //----------------------------------------------------M3 zurück   CCW        
          Serial.println("M3 zurück"); 
   
      while( !digitalRead(END_S3))
    {
      stepperM3.moveTo(stepperM3.currentPosition()-1); 
      stepperM3.setMaxSpeed(20000000.0);      // Set Max Speed of Stepper (Faster for regular movements)
      stepperM3.setAcceleration(100000000000.0);  // Set Acceleration of Stepper
      stepperM3.run();
      stepperM3.stop();
    }
    Serial.println("m3 pos");
    Serial.println(stepperM3.currentPosition());
            
  }
  

  
