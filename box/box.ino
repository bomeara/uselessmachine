// Based on code from https://create.arduino.cc/projecthub/viorelracoviteanu/useless-lid-with-arduino-d67b47
#include <Servo.h>

Servo fingerServo;
Servo lidServo;

int switchStatus=0, action=1, vot, randNumber=0;
const int ledPin = 13;
const int frontSwitchPin = 2;
const int fingerServoPin = 5;
const int lidServoPin = 6;
int fingerMinRotation = 180; // when finger fully retracted
int fingerNearlyMaxRotation = 35; // when finger nearly fully extended
int fingerMaxRotation = 26; // when finger fully extended
int lidMaxOpen = 110; // when lid open all the way
int lidMaxClosed = 70; // when lid closed all the way

void setup()
{
  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);
  
  fingerServo.attach(fingerServoPin);
  lidServo.attach(lidServoPin);
  fingerServo.write(fingerMinRotation);
  lidServo.write(lidMaxClosed);

  //randomSeed(analogRead(0));
}


void loop()
{
  switchStatus = digitalRead(frontSwitchPin);
  //action = random(1,16);
  
  if (switchStatus == LOW){
    
    if (action == 1)
    {
      Serial.println("Action 1");
      for (int i = lidMaxClosed; i <= lidMaxOpen; i++)
      {
        lidServo.write(i);
        delay(20);
      }
      for (int i = fingerMinRotation; i >= fingerNearlyMaxRotation; i--)
      {
        fingerServo.write(i);
        delay(20);
      }
      delay(1000);
      fingerServo.write(fingerMaxRotation);
      delay(200);
      for (int i = fingerMaxRotation; i <=fingerMinRotation; i++)
      {
        fingerServo.write(i);
        delay(20);
      }
      for (int i = lidMaxOpen; i >= lidMaxClosed; i--)
      {
        lidServo.write(i);
        delay(20);
      }
      action++;
    }
    
    
    else if (action == 2)
    {
      Serial.println("Action 2");
      for (int i = lidMaxClosed; i <= lidMaxOpen; i++){
        lidServo.write(i);
        delay(6);
      }
      delay(550);
      fingerServo.write(fingerMaxRotation);
      delay(1000);
      fingerServo.write(fingerMinRotation);
      delay(550);
      lidServo.write(lidMaxClosed);
      delay(1500);
      for (int i = lidMaxClosed; i <= lidMaxOpen; i++){
        lidServo.write(i);
        delay(6);
      }
      delay(3000);
      lidServo.write(lidMaxClosed);
      action++;
    }
    
    else if (action == 3)
    {
      Serial.println("Action 3");
      for (int i = lidMaxClosed; i <= lidMaxOpen; i++){
        lidServo.write(i);
        delay(6);
      }
      delay(1000);
      lidServo.write(lidMaxClosed);
      delay(2000);
      for (int i = lidMaxClosed; i <= lidMaxOpen; i++){
        lidServo.write(i);
        delay(6);
      }
      fingerServo.write(fingerMaxRotation);
      delay(650);
      fingerServo.write(fingerMinRotation);
      delay(500);
      lidServo.write(lidMaxClosed);
      action++;
    }
   
    else if (action == 4)
    {
      Serial.println("Action 4");
      for (int i = lidMaxClosed; i <= lidMaxOpen; i++)
      {
        lidServo.write(i);
        delay(20);
      }
      for (int i = fingerMinRotation; i >= fingerNearlyMaxRotation; i--)
      {
        fingerServo.write(i);
        delay(20);
      }
      delay(2000);
      fingerServo.write(fingerMaxRotation);
      delay(200);
      fingerServo.write(fingerMinRotation);
      delay(400);
      lidServo.write(lidMaxClosed);
      action++;
    }
    
    else if (action == 5)
    {
      Serial.println("Action 5");
      for (int i = lidMaxClosed; i <= lidMaxOpen; i++){
        lidServo.write(i);
        delay(6);
      }
      delay(2000);
      fingerServo.write(65);
      delay(550);
      fingerServo.write(40);
      delay(200);
      fingerServo.write(65);
      delay(200);
      fingerServo.write(40);
      delay(200);
      fingerServo.write(65);
      delay(200);
      fingerServo.write(40);
      delay(200);
      fingerServo.write(65);
      delay(200);
      fingerServo.write(40);
      delay(200);
      fingerServo.write(65);
      delay(200);
      fingerServo.write(40);
      delay(200);
      fingerServo.write(65);
      delay(2000);
      fingerServo.write(fingerMaxRotation);
      delay(400);
      fingerServo.write(fingerMinRotation);
      delay(400);
      lidServo.write(lidMaxClosed);
      action++;
    }
    
    else if (action == 6)             
    {
      Serial.println("Action 6");
      for (int i = lidMaxClosed; i <lidMaxOpen; i++)
      {
        lidServo.write(i);
        delay(20);
      }
      delay(1000);
      for (int i = 0; i < 12; i++)
      {
        for (int j = lidMaxClosed; j <= lidMaxOpen; j++){
          lidServo.write(j);
          delay(6);
        }
        delay(200);
      }
      for (int i = fingerMinRotation; i >= fingerNearlyMaxRotation; i--)
      {
        fingerServo.write(i);
        delay(30);
      }
      fingerServo.write(fingerMaxRotation);
      delay(400);
      fingerServo.write(fingerMinRotation);
      delay(400);
      lidServo.write(lidMaxClosed);
      delay(1500);
      for (int i = lidMaxClosed; i <= lidMaxOpen; i++){
        lidServo.write(i);
        delay(6);
      }
      delay(3000);
      lidServo.write(lidMaxClosed);
      action++;
    }
    
    else if (action == 7)
    {
      Serial.println("Action 7");
      for (int i = lidMaxClosed; i <= lidMaxOpen; i++){
        lidServo.write(i);
        delay(6);
      }
      delay(400);
      fingerServo.write(fingerMaxRotation);
      delay(1000);
      for (int i = 0; i < 6; i++)
      {
        for (int j = lidMaxClosed; j <= lidMaxOpen; j++){
          lidServo.write(j);
          delay(6);
        }
        delay(200);
      }
      delay(500);
      fingerServo.write(fingerMinRotation);
      delay(400);
      lidServo.write(lidMaxClosed);
      action++;
    }
    
    else if (action == 8)
    {
      Serial.println("Action 8");
      for (int i = lidMaxClosed; i <= lidMaxOpen; i++){
        lidServo.write(i);
        delay(6);
      }
      fingerServo.write(fingerMaxRotation);
      delay(2000);
      for (int i = 0; i < 7; i++)
      {
        fingerServo.write(75);
        delay(100);
        fingerServo.write(40);
        delay(100);
      }
      delay(500);
      fingerServo.write(fingerMinRotation);
      delay(1000);
      lidServo.write(lidMaxClosed);
      action++;
    }
    
    else if (action == 9)
    {
      Serial.println("Action 9");
      for (int i = lidMaxClosed; i <= 105; i++){
        lidServo.write(i);
        delay(6);
      }
      delay(2000);
      lidServo.write(lidMaxOpen);
      for (int i = fingerMinRotation; i >=fingerNearlyMaxRotation; i--)
      {
        fingerServo.write(i);
        delay(40);
      }
      delay(500);
      fingerServo.write(fingerMaxRotation);
      delay(200);
      for (int i = fingerMaxRotation; i <=fingerMinRotation; i++)
      {
        fingerServo.write(i);
        delay(40);
      }
      lidServo.write(lidMaxClosed);
      delay(2000);
      lidServo.write(100);
      delay(3000);
      lidServo.write(lidMaxClosed);
      action++;
    }
  
    
    else if (action == 10)
    {
      Serial.println("Action 10");
      for (int i = lidMaxClosed; i <= 105; i++)
      {
        lidServo.write(i);
        delay(100);
      }
      delay(1000);
      for (int i = 0; i < 10; i++)
      {
        for (int j = lidMaxClosed; j <= 100; j++){
          lidServo.write(j);
          delay(6);
      }
        delay(100);
      }
      lidServo.write(lidMaxOpen);
      delay(100);
      fingerServo.write(fingerMaxRotation);
      delay(650);
      fingerServo.write(fingerMinRotation);
      delay(400);
      lidServo.write(lidMaxClosed);
      action++;
    }
    
    else if (action == 11)
    {
      Serial.println("Action 11");
      for (int i = lidMaxClosed; i <= lidMaxOpen; i++){
        lidServo.write(i);
        delay(6);
      }
      fingerServo.write(fingerMaxRotation);
      delay(2000);
      for (int i = 0; i < 3; i++)
      {
        fingerServo.write(65);
        delay(200);
        fingerServo.write(40);
        delay(200);
      }
      delay(1500);
      fingerServo.write(fingerMinRotation);
      delay(400);
      lidServo.write(lidMaxClosed);
      delay(1500);
      for (int i = lidMaxClosed; i <= lidMaxOpen; i++){
        lidServo.write(i);
        delay(6);
      }
      fingerServo.write(fingerMaxRotation);
      delay(3000);
      fingerServo.write(fingerMinRotation);
      delay(400);
      lidServo.write(lidMaxClosed);
      action++;
    }
    
    else if (action == 12)
    {
      Serial.println("Action 12");
      for (int i = lidMaxClosed; i <= lidMaxOpen; i++)
      {
        lidServo.write(i);
        delay(50);
      }
      delay(1000);
      for (int i = fingerMinRotation; i >= fingerMaxRotation; i--)
      {
        fingerServo.write(i);
        delay(50);
      }
      delay(2000);
      fingerServo.write(fingerMaxRotation);
      delay(200);
      fingerServo.write(fingerMinRotation);
      delay(400);
      lidServo.write(lidMaxClosed);
      action++;
    }
    
    else if (action == 13)
    {
      Serial.println("Action 13");
      for (int i = lidMaxClosed; i <= lidMaxOpen; i++){
        lidServo.write(i);
        delay(6);
      }
      delay(2000);
      for (int i = fingerMinRotation; i >= 60; i--)
      {
        fingerServo.write(i);
        delay(40);
      }
      for (int i = 0; i < 3; i++)
      {
        fingerServo.write(60);
        delay(200);
        fingerServo.write(40);
        delay(800);
      }
      fingerServo.write(fingerMaxRotation);
      delay(2000);
      fingerServo.write(fingerMinRotation);
      delay(500);
      lidServo.write(lidMaxClosed);
      action++;
    }
    
    else if (action == 14)
    {
      Serial.println("Action 14");
      for (int i = lidMaxClosed; i <= 105; i++){
        lidServo.write(i);
        delay(6);
      }
      delay(4000);
      lidServo.write(lidMaxOpen);
      fingerServo.write(fingerMaxRotation);
      delay(650);
      fingerServo.write(fingerMinRotation);
      delay(500);
      lidServo.write(100);
      delay(4000);
      lidServo.write(lidMaxClosed);
      action++;
    }
    
    else if (action == 15)
    {
      Serial.println("Action 15");
      for (int i = lidMaxClosed; i <= 105; i++){
        lidServo.write(i);
        delay(6);
      }
      delay(1000);
      for (int i = 0; i < 3; i++)
      {      
        for (int j = lidMaxClosed; j <= 105; j++){
          lidServo.write(j);
          delay(50);
        }
        for (int j = 105; j >= lidMaxClosed; j--)
        {
          lidServo.write(j);
          delay(50);
        }
      }
      for (int j = lidMaxClosed; j <= lidMaxOpen; j++){
        lidServo.write(j);
        delay(50);
      }
      for (int i = fingerMinRotation; i >= fingerNearlyMaxRotation; i--)
      {
        fingerServo.write(i);
        delay(40);
      }
      delay(1000);
      fingerServo.write(fingerMaxRotation);
      delay(400);
      fingerServo.write(fingerMinRotation);
      delay(400);
      lidServo.write(lidMaxClosed);
      action = 1;
    }
    
  }
  
}
