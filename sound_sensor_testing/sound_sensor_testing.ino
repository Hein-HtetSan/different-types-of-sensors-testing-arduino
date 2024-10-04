
const int soundPin = A0;

const int redPin = 4;
const int greenPin = 3;
const int bluePin = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(soundPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(soundPin);
  Serial.println(value);

  if (value > 600){
    color(0,255,255);  // red
    Serial.println("Vol High");
  }else{
    color(255,0,255);  // green
    Serial.println("Vol Low");
  }
  delay(1000);
}


void color(unsigned char red, unsigned char green, unsigned char blue){
  digitalWrite(redPin, red);
  digitalWrite(greenPin, green);
  digitalWrite(bluePin, blue);
}
