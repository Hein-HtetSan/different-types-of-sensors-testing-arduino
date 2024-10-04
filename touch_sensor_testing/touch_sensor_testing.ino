const int SensorPin = 7;
// const int ledPin = 13;
// for rgb
const int redPin = 4;
const int greenPin = 3;
const int bluePin = 2;

const int buzzerPin = 8;

int SensorStat = 0 ;

void setup() {
  // put your setup code here, to run once:
  pinMode(SensorPin, INPUT);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = digitalRead(SensorPin);
  Serial.print("State : ");
  Serial.println(value);
  if(value){
    color(255,0,255); // green
    alarm(1000, 1500); // Different frequencies for "pi" and "po"
  }else{
    color(0,255,255); // red
    noTone(buzzerPin);
  }
  delay(1000);
}

// 
void color(unsigned char red, unsigned char green, unsigned char blue){
  digitalWrite(redPin, red);
  digitalWrite(greenPin, green);
  digitalWrite(bluePin, blue);
}

void alarm(int fz1, int fz2) {
  for (int i = 0; i < 3; i++) {
    tone(buzzerPin, fz1); // First tone "pi"
    delay(500); // Short duration for the first tone
    noTone(buzzerPin);
    delay(100); // Short pause between tones

    tone(buzzerPin, fz2); // Second tone "po"
    delay(500); // Short duration for the second tone
    noTone(buzzerPin);
    delay(100); // Short pause between tones
  }
}

