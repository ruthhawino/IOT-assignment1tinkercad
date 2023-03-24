// C++ code
//
#include <Servo.h>

int servo = 0;

Servo servo_4;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  servo_4.attach(4, 500, 2500);
}

void loop()
{
  servo = (-40 + 0.488155 * (analogRead(A0) - 20));
  Serial.println(servo);
  if (servo >= 30) {
    servo_4.write(90);
  }

  servo;
  delay(10); // Delay a little bit to improve simulation performance
}