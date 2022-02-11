#include<LiquidCrystal.h>
LiquidCrystal lcd(13, 12,3, 4, 5,6);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(9, INPUT); // helmet
  pinMode(11, INPUT);
  pinMode(10, INPUT);
  pinMode(8, INPUT); // IR Sensor 

  //pinMode(5,INPUT);  // smoke Sensor

  //pinMode(7,INPUT);  // Alcohol Sensor

 pinMode(7, OUTPUT); // buzzer
 pinMode(A1, OUTPUT); // motor.
 pinMode(A2, OUTPUT); // motor.

  lcd.println("Hello");
  delay(1000);
}

void loop() {

  if (analogRead(7) <= 700) {       //alcohol detection
    
    while (analogRead(7) <= 700)
    {
      
      while ((digitalRead(11) == 0 ) && (digitalRead(10) == 0) && (digitalRead(8) == 0 ))
      { // two passengers
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Seat 1 or 2 only");
        
        digitalWrite(A0, 0);
        digitalWrite(A1, 0);
        delay(1000);
      }
      if ((digitalRead(11) == 0 ) && ((digitalRead(10) == 0) ||  (digitalRead(10) == 1)) && (digitalRead(8) == 1)) 
      {
        while ((digitalRead(11) == 0 ) && ((digitalRead(10) == 0) || (digitalRead(10) == 1)) && (digitalRead(8) == 1)) 
        {
          if(digitalRead(9)==0)
          {
            
            digitalWrite(A0, 1);
            digitalWrite(A1, 0);
            delay(2000);
            digitalWrite(A0, 0);
            digitalWrite(A1, 0);
            delay(2000);
            lcd.clear();
            lcd.setCursor(0,1);
            lcd.print("You can Go");
            
            
            
          }
          else
          {
            lcd.clear();
            lcd.setCursor(0,1);
            lcd.println("Wear Helmet");
            
            
            digitalWrite(7,1);
            delay(1000);
            digitalWrite(7,0);
            digitalWrite(0, 0);
            delay(1000);
           
          }
         
          while ((digitalRead(11) == 0 ) && (digitalRead(10) == 0) && (digitalRead(8) == 0 )) 
          {   //two passengers
            digitalWrite(A0, 0);
            digitalWrite(A1, 0);
            lcd.setCursor(0, 0);
            lcd.setCursor(0, 0);
            lcd.print("Seat 1 or 2 only");
            
          }
          
          if (analogRead(5) > 310) 
          {    //smoke
            lcd.print(analogRead(5));
            digitalWrite(7,1);
            delay(1000);
            digitalWrite(7,0);
            delay(1000);
            //pollution buzzer
          }

          
        }
      }
    }
  } 
  else
  {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("You Are Drunk");
    delay(1000);
  }
}

