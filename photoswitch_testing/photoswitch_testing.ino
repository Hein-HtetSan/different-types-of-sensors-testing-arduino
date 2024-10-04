const int photocellPin = A0;
// const int ledPin = 13;

const int redPin = 4;
const int greenPin = 3;
const int bluePin = 2;

const int relayPin = 8;
int outputValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(relayPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  outputValue = analogRead(photocellPin); // read value of photoresitor
  Serial.println(outputValue);
  if(outputValue >= 400)
  {
    color(0,255,255);
    digitalWrite(relayPin, LOW);
  }else{
    color(255,0,255);
    digitalWrite(relayPin, HIGH);
  }
  delay(1000);
}

void color(unsigned char red, unsigned char green, unsigned char blue){
  digitalWrite(redPin, red);
  digitalWrite(greenPin, green);
  digitalWrite(bluePin, blue);
}

