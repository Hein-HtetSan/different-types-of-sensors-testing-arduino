
const int analogPin = A0;
const int digitalPin = 8;
const int ledPin = 13;
const int buzzerPin = 7;


void setup() {
  // put your setup code here, to run  once:
  pinMode(digitalPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int analogVal = analogRead(analogPin);
  Serial.print("A0: ");
  Serial.println(analogVal); // print to serial monitor
  boolean stat = digitalRead(digitalPin);
  Serial.print("D0: ");
  Serial.println(stat);
  Serial.print(" ");
  
  if(stat == HIGH)
  {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }
  if(stat == LOW)
  {
    digitalWrite(ledPin, HIGH);
    tone(7,320,200);
  }
  delay(500);
}
