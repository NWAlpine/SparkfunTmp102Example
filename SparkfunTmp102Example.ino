
#include "wire.h"

const int tmpAddress = 0x48;

void setup()
{
	Serial.begin(9600);
	Wire.begin();
}

void loop()
{
	float celsius = getTemp();
	Serial.print("Celcius: ");
	Serial.println(celsius);

	float faharenheight = (1.8 * celsius) + 32;
	Serial.print("Faharenheight: ");
	Serial.println(faharenheight);

	delay(1000);
}

float getTemp()
{
	Wire.requestFrom(tmpAddress, 2);

	byte MSB = Wire.read();
	byte LSB = Wire.read();

	// data is a 12bit int using 2's compliment for negative
	int temperatureSum = ((MSB << 8) | LSB) >> 4;

	float celcius = temperatureSum*0.0625;

	return celcius;
}
