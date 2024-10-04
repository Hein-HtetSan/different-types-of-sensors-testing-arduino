#include <Servo.h>

#define FRONT_LEFT_HORIZONTAL_PIN 2
#define FRONT_LEFT_VERTICAL_PIN 3
#define FRONT_RIGHT_HORIZONTAL_PIN 4
#define FRONT_RIGHT_VERTICAL_PIN 5
#define BACK_LEFT_HORIZONTAL_PIN 6
#define BACK_LEFT_VERTICAL_PIN 7
#define BACK_RIGHT_HORIZONTAL_PIN 8
#define BACK_RIGHT_VERTICAL_PIN 9

Servo frontLeftHorizontal;
Servo frontLeftVertical;
Servo frontRightHorizontal;
Servo frontRightVertical;
Servo backLeftHorizontal;
Servo backLeftVertical;
Servo backRightHorizontal;
Servo backRightVertical;

#define SERVO_CENTER 90

#define STEP_DELAY 20
#define NUM_STEPS 4

void setup() {
  frontLeftHorizontal.attach(FRONT_LEFT_HORIZONTAL_PIN);
  frontLeftVertical.attach(FRONT_LEFT_VERTICAL_PIN);
  frontRightHorizontal.attach(FRONT_RIGHT_HORIZONTAL_PIN);
  frontRightVertical.attach(FRONT_RIGHT_VERTICAL_PIN);
  backLeftHorizontal.attach(BACK_LEFT_HORIZONTAL_PIN);
  backLeftVertical.attach(BACK_LEFT_VERTICAL_PIN);
  backRightHorizontal.attach(BACK_RIGHT_HORIZONTAL_PIN);
  backRightVertical.attach(BACK_RIGHT_VERTICAL_PIN);
}

void loop() {
  moveForward();
  delay(1000); // Wait for 1 second before the next movement
}

void moveLeg(Servo horizontalServo, Servo verticalServo, int liftAngle, int forwardAngle, int originalHorizontalAngle) {
  verticalServo.write(liftAngle);
  delay(20);
  horizontalServo.write(forwardAngle);
  delay(20);
  verticalServo.write(SERVO_CENTER);
  delay(20);
  horizontalServo.write(originalHorizontalAngle);
  delay(20);
}

void moveForward() {
  for (int stepCount = 0; stepCount < NUM_STEPS; stepCount++) {
    // Move front left leg
    moveLeg(frontLeftHorizontal, frontLeftVertical, 90, 100, 100);
    moveLeg(frontLeftHorizontal, frontLeftVertical, 65, 65, 65);
    delay(STEP_DELAY);

    // Move back right leg
    moveLeg(backRightHorizontal, backRightVertical, 90, 80, 80);
    moveLeg(backRightHorizontal, backRightVertical, 65, 115, 115);
    delay(STEP_DELAY);

    // Move back left leg
    moveLeg(backLeftHorizontal, backLeftVertical, 90, 100, 100);
    moveLeg(backLeftHorizontal, backLeftVertical, 65, 65, 65);
    delay(STEP_DELAY);

    // Move front right leg
    moveLeg(frontRightHorizontal, frontRightVertical, 90, 80, 80);
    moveLeg(frontRightHorizontal, frontRightVertical, 65, 125, 125);
    delay(STEP_DELAY);
  }
}
