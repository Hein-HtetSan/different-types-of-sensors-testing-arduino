
#include <Wire.h>
#include <NewPing.h>
#include <TimerFreeTone.h>

#define TRIGGER_PIN 11
#define ECHO_PIN 9
#define MAX_DISTANCE 400
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// first 3 led
const int f_redPin = 2;
const int f_bluePin = 3;
const int f_greenPin = 13;
// second 2 led
const int s_greenPin = 12;
const int s_redPin = 10;
// buzzer pin
const int buzzerPin = 8;
const int timerdelay = 250;
// push button pin
const int pushPin = 4;

int input_state = 0;


void setup() {
  // output of first pins
  pinMode(f_redPin, OUTPUT);
  pinMode(f_bluePin, OUTPUT);
  pinMode(f_greenPin, OUTPUT);
  // output of second pins
  pinMode(s_greenPin, OUTPUT);
  pinMode(s_redPin, OUTPUT);
  // ouput for buzzerpin
  pinMode(buzzerPin, OUTPUT);
  pinMode(pushPin, INPUT);
  Serial.begin(9600);
}

void loop() {

  unsigned int uS = sonar.ping(); // read the sensor
  long dist = uS / US_ROUNDTRIP_CM; // get distance by cm
  // output the distance
  Serial.print("Ping : ");
  Serial.print(dist);
  Serial.println("cm");
  Serial.print("input state: ");
  Serial.println(input_state);
  // 
  if(digitalRead(pushPin) == LOW){
    input_state = 1;
  }

  if(input_state == 1){
    // TimerFreeTone(buzzerPin, noTone);
  }

  if(dist > 100){
    digitalWrite(f_redPin, LOW);
    digitalWrite(f_bluePin, LOW);
    digitalWrite(f_greenPin, LOW);

    digitalWrite(s_greenPin, HIGH);
    delay(100);
    digitalWrite(s_greenPin, LOW);
    delay(100);
  }


  if(dist > 2 && dist <= 25){
    digitalWrite(f_redPin, HIGH);
    digitalWrite(f_bluePin, LOW);
    digitalWrite(f_greenPin, LOW);
    TimerFreeTone(buzzerPin, 1000, 100);

  // flash
    digitalWrite(s_redPin, HIGH);
    delay(100);
    digitalWrite(s_redPin, LOW);
    delay(100);

  }else if(dist > 25 && dist <= 75){
    digitalWrite(f_redPin, LOW);
    digitalWrite(f_bluePin, HIGH);
    digitalWrite(f_greenPin, LOW);
  }else if(dist > 75 && dist <= 100){
    digitalWrite(f_redPin, LOW);
    digitalWrite(f_bluePin, LOW);
    digitalWrite(f_greenPin, HIGH);
  }
  delay(500);
}

// void WaitForIt(char C)
// {
//   while (true)
//   {
//     if (Serial.available() > 0)
//       if (Serial.read() == C){
//         Serial.println("Welcome...");
//         digitalWrite(s_greenPin, HIGH);
//         delay(2000);
//         digitalWrite(s_greenPin, LOW);
//         break;
//       }
//       digitalWrite(s_greenPin, LOW);
//   }
// }

