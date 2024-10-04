const int redPin = 4;
const int greenPin = 3;
const int bluePin = 2;

const int pushPin = 8;
const int buzzerPin = 9;
int first_state = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pushPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int stat = digitalRead(pushPin);
  Serial.print("State ");
  Serial.println(stat);

  if(stat){
    color(0,255,255);
    noTone(buzzerPin);
  }else{
    color(255,0,255);
    tone(buzzerPin, 950, 1000);
    delay(500);
  }
  delay(1000);
}

void color(unsigned char red, unsigned char green, unsigned char blue){
  digitalWrite(redPin, red);
  digitalWrite(greenPin, green);
  digitalWrite(bluePin, blue);
}
