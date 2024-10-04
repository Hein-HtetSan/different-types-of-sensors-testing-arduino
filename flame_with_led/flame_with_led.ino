

const int buzzerPin = 3; // buzzer pin
const int flame_a0 = A0; // flame sensor anaalog pin
const int flame_d0 = 2; // flame sensor digital pin

// led pin
const int bluePin = 5;
const int redPin = 6;
const int greenPin = 7;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(flame_d0, INPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int analogVal = analogRead(flame_a0);
  boolean stat = digitalRead(flame_d0);

  Serial.print("A0: ");
  Serial.println(analogVal);
  Serial.print("D0: ");
  Serial.println(stat);

  if(stat == HIGH){
    digitalWrite(greenPin, HIGH);
    delay(200);
    digitalWrite(greenPin, LOW);
    delay(200);
    digitalWrite(bluePin, HIGH);
    delay(200);
    digitalWrite(bluePin, LOW);
    delay(200);
    noTone(buzzerPin);
  }

  if(stat == LOW)
  {
    digitalWrite(redPin, HIGH);
    delay(100);
    digitalWrite(redPin, LOW);
    delay(100);
    tone(buzzerPin, 520, 500);
  }
  delay(500);
}
