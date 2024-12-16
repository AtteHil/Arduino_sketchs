#include <Servo.h>
Servo myServo; // for using servo motor

int const potPin = A0;
int potVal;
int angle;
void setup() {
  myServo.attach(9);
  Serial.begin(9600);

}

void loop() {
  potVal = analogRead(potPin);
  Serial.print("potVal: ");
  Serial.print(potVal);
  angle = map(potVal, 0, 1023, 0, 179); // scale numbers 0-1023 to scale 0-179 which can be used by servo which turns 180 degrees
  Serial.print(", angle: ");
  Serial.println(angle);
  myServo.write(angle);
  delay(15);

}
