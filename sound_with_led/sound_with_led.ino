const int soundPin = A0; // sound sensor pin
const int redPin = 2;
const int bluePin = 3;
const int greenPin = 4;

void flash_led(int);

void setup() {
  // put your setup code here, to run once:
  pinMode(soundPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  int value = analogRead(soundPin);
  Serial.print("value : ");
  Serial.println(value);
  flash_led(value);
}

void flash_led(int value){
  digitalWrite(redPin, HIGH);
  delay(value);
  digitalWrite(redPin, LOW);
  delay(value);
  digitalWrite(bluePin, HIGH);
  delay(value);
  digitalWrite(bluePin, LOW);
  delay(value);
  digitalWrite(greenPin, HIGH);
  delay(value);
  digitalWrite(greenPin, LOW);
  delay(value);
}
