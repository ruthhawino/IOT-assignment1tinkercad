// C++ code
//
#include <Adafruit_LiquidCrystal.h>

int val = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  lcd_1.begin(16, 2);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  val = 0;

  0.01723 * readUltrasonicDistance(6, 5);

  lcd_1.print(val);
  if (val <= 30) {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
    if (val <= 90) {
      digitalWrite(9, HIGH);
    } else {
      digitalWrite(9, LOW);
    }
    if (val == 90) {
      digitalWrite(10, HIGH);
    } else {
      digitalWrite(10, LOW);
    }
  }

  val;
  delay(10); // Delay a little bit to improve simulation performance
}