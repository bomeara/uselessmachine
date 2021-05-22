/******************************************************************************
servo-skatch.ino
Example sketch for connecting a hobby servo to a sparkfun redboard
  (https://www.sparkfun.com/products/9065)
  (https://www.sparkfun.com/products/12757)
Byron Jacquot@ SparkFun Electronics
May 17, 2016

**SparkFun code, firmware, and software is released under the MIT License(http://opensource.org/licenses/MIT).**

Development environment specifics:
Arduino 1.6.5
******************************************************************************/

#include <Servo.h>

Servo lidservo;

// uint32_t next;

void setup()
{
  // the 1000 & 2000 set the pulse width 
  // min & max limits, in microseconds.
  // Be careful with shorter or longer pulses.
  lidservo.attach(9, 1000, 2000);
  delay(5000);

}

void loop()
{
  static bool rising = true;
  //if(int(millis()) % 300 == 0)
// {
    if(rising)
    {
      lidservo.write(20);
      rising = false;
    }
    else
    {
      lidservo.write(0);
      rising = true;
    }
    delay(4000);
 // }

}
