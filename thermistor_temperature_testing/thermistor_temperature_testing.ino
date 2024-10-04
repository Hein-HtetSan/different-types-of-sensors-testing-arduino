#include <Wire.h>

#define analogPin A0
#define beta 3950
#define resistance 10

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // read the analog temperature
  long a =1023 - analogRead(analogPin);
  Serial.print("Raw reading : ");
  Serial.println(a);

  // calculate the formula of temperature
  float tempC = beta / (log( (1025.0 *  10 / a - 10 ) / 10) + beta  /  298.0) - 273.0;
  float tempF = 1.8*tempC + 32.0;

  Serial.print("Centigrade : ");
  Serial.print(tempC);
  Serial.println(" C");

  delay(2000);

  Serial.print("Fahrenheit: " );
  Serial.print(tempF);
  Serial.println(" F");

  delay(2000);
}