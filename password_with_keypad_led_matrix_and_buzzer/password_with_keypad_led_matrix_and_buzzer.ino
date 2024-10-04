//Written By Nikodem Bartnik - nikodembartnik.pl
#include <LedControl.h>
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

int step_number = 0;
int DIN = 16;
int CS = 15;
int CLK = 14;
int greenPin = 2;
int redPin = 3;
int buzzer = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {6,7,8,9}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {10,11,12,13}; //connect to the column pinouts of the keypad

char code[4] = {'1', '1', '1', '1'};
char input[4];

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
LedControl lC = LedControl(DIN, CLK, CS, 0);
int input_state = 0;
int i = 0;

void setup() {

  lC.shutdown(0, false);
  lC.setIntensity(0, 15);
  lC.clearDisplay(0);

  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(buzzer, OUTPUT);

}

void loop() {

  char key = keypad.getKey();// Read the key

  byte err[8] = {0x00,0x00,0xEF,0x89,0xEF,0x8A,0xE9,0x00};
  byte ok[8] = {0x00,0x00,0xE9,0xAA,0xAC,0xAA,0xE9,0x00};
  byte loading_1[8] = {0x00,0x00,0x00,0x00,0x55,0x00,0x00,0x00};
  byte loading_2[8] = {0x00,0x00,0x00,0x00,0x15,0x00,0x00,0x00};
  byte loading_3[8] = {0x00,0x00,0x00,0x00,0x05,0x00,0x00,0x00};
  byte loading_4[8] = {0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00};

  
  if(input_state == 0 || input_state == 1){
    printByte(loading_1);
    delay(100);
    printByte(loading_2);
    delay(100);
    printByte(loading_3);
    delay(100);
    printByte(loading_4);
    delay(100);
  }
  
  // Print if key pressed
  if (key && i <= 4){
    Serial.print("Key Pressed : ");
    Serial.println(key);
    input[i] = key;
    i++;
    input_state = 1;
  }

  if(key == 'A'){
    input_state = 2;
    if(check(input)){
      printByte(ok);
      digitalWrite(greenPin, HIGH);
    }else{
      printByte(err);
      digitalWrite(redPin, HIGH);
      tone(buzzer, 1000, 100);
    }
  }

  if(key == 'C'){
    input_state = 0;
    i=0;
    *input = {};
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, LOW);
    noTone(buzzer);
  }
}

int check(char input[]){
  for(int j=0; j<4; j++){
    if(input[j] != code[j]){
      return 0;
    }
  }
  return 1;
}


void printByte(byte character []) {
  int i = 0;
  for(i=0;i<8;i++)
  {
    lC.setRow(0,i,character[i]);
  }
}

