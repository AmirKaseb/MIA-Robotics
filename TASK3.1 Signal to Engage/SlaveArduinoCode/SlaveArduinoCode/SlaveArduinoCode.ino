/*
-----Amir Kasseb-----
-----19/8/2023-----
-----Controlling Led By another Arduino Using I2C Connection-----
*/


//This is the Slave Arduino ( El3bd xD )
int x;
int led11; 
#include <Wire.h>
int led=13;
void setup()
{
  Serial.begin(9600);
  Wire.begin(9); 
  pinMode(11,OUTPUT);
  Wire.onReceive(receiveEvent);
}

  void receiveEvent(int bytes)
{
	x= Wire.read();
}
void loop()
{
  //Here  We have four Integers 0,1,10,11 which is the message sent by the Master Arduino.
  //Each Integer correponds to the required Binary Combination.
  switch(x) {

    case 00:
    Serial.print("No message\n");
    analogWrite(11,0*255);
    //To operate Led with 0% Brightness
    break;
    case 10:
    Serial.print("Vector focused\n");
    analogWrite(11,0.50*255);
    //To operate Led with 50% Brightness
    break;
    case 01:
    Serial.print("Vector distracted\n");
    analogWrite(11,0.75*255);
    //To operate Led with 75% Brightness
    break;
    case 11:
    Serial.print("Glitch\n");
    analogWrite(11,1*255);
    //To operate Led with 100% Brightness
    break;
}
	delay(500);
}