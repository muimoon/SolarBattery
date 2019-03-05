#include <Servo.h>
Servo myservo;
int solarValue;
int batteryValue;
int controlPin = 4;
int servoPin = 8;
int m, n;

void setup() {
  pinMode(controlPin, OUTPUT);
  analogReference(INTERNAL);
  myservo.attach(servoPin);

}

void loop() {
  solarValue = analogRead(A0);
  batteryValue = analogRead(A1);
  if (batteryValue < 835 && solarValue > 676)

    digitalWrite(controlPin, HIGH);
  else if (batteryValue > 894 && solarValue < 592)
    digitalWrite(controlPin, LOW);
  if (solarValue < 338)
  {
    delay(1000);
    if (solarValue < 338)
    {
      myservo.write(15);
      n = 0;
      m = 0;
    }
  }
  else
    myservo.write(15 + 15 * n);
  delay(1000);
  m++;
  if (m == 3600)
  {
    m = 0;
    n++;
    if (n > 10)
      n = 10;
  }
}
