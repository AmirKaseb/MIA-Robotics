/*
-----Amir Kasseb-----
-----19/8/2023-----
-----Controlling Led By another Arduino Using I2C Connection-----
*/

//This is The Master Arduino
#include <Wire.h> 
int button1=13;  
int button2=12;  
int result1=0;
int result2=0;
int message=00; //This the variable that will carry the message :)
void setup()
{
  Wire.begin(); 
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  Serial.begin(9600);
}

void loop()
{
  //Reading The state of button 1
  result1=digitalRead(13);
  //Debugging Button 1 Results
  Serial.print("Result1= ");
  Serial.println(result1);
  
  //Reading The state of button 2
  result2=digitalRead(12);
  //Debugging Button 2 Results
  Serial.print("Result2= ");
  Serial.println(result2);
  
  //The Message Variable which is combination of two results.
  message=(10*result1+result2);
  //Debugging The Message Combinations
  Serial.print( " message= ");
  Serial.println(message);

  Wire.beginTransmission(9);
  Wire.write(message);
  Wire.endTransmission();
  delay(500);
}