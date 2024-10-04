#include <SFE_BMP180.h>
#include <Wire.h>
#include <Ds1302.h>

SFE_BMP180 pressure;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("REBOOT");

  if(pressure.begin()){
    Serial.println("BMP180 init success");
  }else{
    Serial.println("BMP180 init fail");
    while(1); // pasue forever
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
