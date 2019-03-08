#include <Servo.h>
// defining Servos
Servo servohori;
int servoh = 0;
int servohLimitHigh = 160;
int servohLimitLow = 20;
Servo servoverti;
int servov = 0;
int servovLimitHigh = 160;
int servovLimitLow = 20;
// Assigning LDRs
int ldrtopl = 4; // top left LDR green
int ldrtopr = 3; // top right LDR yellow
int ldrbotl = 5; // bottom left LDR blue
int ldrbotr = 2; // bottom right LDR orange
// Servo myservo;
int solarValue;
int batteryValue;
int controlPin = 4;
int servoPin = 8;
//int m, n;
void setup()
{
	servohori.attach(10);
	servohori.write(0);
	servoverti.attach(9);
	servoverti.write(0);
	// myservo.attach(servoPin);
	pinMode(controlPin, OUTPUT);
	analogReference(INTERNAL);
	delay(500);
}

void loop()
{
	servoh = servohori.read();
	servov = servoverti.read();
	// capturing analog values of each LDR
	int topl = analogRead(ldrtopl);
	int topr = analogRead(ldrtopr);
	int botl = analogRead(ldrbotl);
	int botr = analogRead(ldrbotr);
	// calculating average
	int avgtop = (topl + topr) / 2; // average of top LDRs
	int avgbot = (botl + botr) / 2; // average of bottom LDRs
	int avgleft = (topl + botl) / 2; // average of left LDRs
	int avgright = (topr + botr) / 2; // average of right LDRs
	solarValue = analogRead(A0);
	batteryValue = analogRead(A1);
	if (batteryValue < 835 && solarValue > 676)
		digitalWrite(controlPin, HIGH);
	else
		if (batteryValue > 894 && solarValue < 592)
			digitalWrite(controlPin, LOW);
	if (solarValue < 338)
	{
		delay(1000);
		if (solarValue < 338)
		{
			myservo.write(15);
			// n = 0;
			// m = 0;
		}
	}
	else
	{
		if (avgtop < avgbot)
		{
			servoverti.write(servov + 1);
			if (servov > servovLimitHigh)
			{
				servov = servovLimitHigh;
			}
			delay(10);
		}
		else
			if (avgbot < avgtop)
			{
				servoverti.write(servov - 1);
				if (servov < servovLimitLow)
				{
					servov = servovLimitLow;
				}
				delay(10);
			}
		else
		{
			servoverti.write(servov);
		}
		if (avgleft > avgright)
		{
			servohori.write(servoh + 1);
			if (servoh > servohLimitHigh)
			{
				servoh = servohLimitHigh;
			}
			delay(10);
		}
		else
			if (avgright > avgleft)
			{
				servohori.write(servoh - 1);
				if (servoh < servohLimitLow)
				{
					servoh = servohLimitLow;
				}
				delay(10);
			}
		else
		{
			servohori.write(servoh);
		}
		delay(50);
	}
	// myservo.write(15 + 15 * n);
	delay(1000);
	// m++;
	// if (m == 3600)
	// {
	// m = 0;
	// n++;
	// if (n > 10)
	// n = 10;
	// }
}
