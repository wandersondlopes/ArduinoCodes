/*
Controlling movements of two servos using a Joystick
Joystick's x- and y- axes are connected to A0 and A1 analog pins of Arduino.
Servos are connectd to PWM Pins 9 and 10.

Crieted 01/05/2016
By Explore Labs 
Modified Set 2022
by Wanderson D. Lopes 
*/

#include <Servo.h>

Servo tilt, pan; // create servo object to control a servo 

int joyX = A0; // analog pin used to connect the X - axis of Joystick
int joyY = A1; // analog pin used to connect the Y - axis of Joystick
int x, y; // variables to read the values from the analog pins 

void setup()
{ 
  tilt.attach(9); // attaches the tilt servo on pin 9 to the servo object 
  pan.attach(10); // attaches the pan servo on pin 10 to the servo object 
} 

void loop()
{ 
  x = joyX;    // reads the value of the Joystick's X - axis (value between 0 and 1023) 
  y = joyY;    // reads the value of the Joystick's Y - axis (value between 0 and 1023) 
  x = map(analogRead(joyX), 0, 1023, 900, 2100); // scale it to use with the servo b/w 900 usec to 2100 usec
  y = map(analogRead(joyY), 0, 1023, 900, 2100);
  tilt.write(x); // sets the servo position according to the scaled value 
  pan.write(y);
  delay(15); // waits for the servos to get there 
}