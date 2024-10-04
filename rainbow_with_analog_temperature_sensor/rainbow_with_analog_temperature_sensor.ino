#include <LiquidCrystal_I2C.h>

const int digitalPin = 9;
int analogPin = A0;

int Astate = 0;
boolean Dstate = 0;

// Rainbow led Pins
const int r = 5;
const int g = 6;
const int b = 7;

void setup()
{ 
  pinMode(digitalPin, INPUT); // temperature input

  // output rainbow led
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);

  Serial.begin(9600);
}


void loop()  // run over and over again  
{    
  Astate = analogRead(analogPin);
  Dstate = digitalRead(digitalPin);

  Serial.print("D0 :");
  Serial.println(Dstate);
  Serial.print("A0 : ");
  Serial.println(Astate);

  if(Dstate == HIGH){
    Serial.println("High state");
    color(255,0,255); // green color;
  }else{
    Serial.println("Low state");
    color(0, 255, 255); // red
  }

  delay(1000);
}     
/***************************************************************************/
void color (unsigned char red, unsigned char green, unsigned char blue){
  analogWrite(r, red);
  analogWrite(g, green);
  analogWrite(b, blue);
}





