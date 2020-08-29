#include <AltSoftSerial.h>

//Left Motor
const int LEFTM_1 = 12;  // Pin 14 of L293
const int LEFTM_2 = 13;  // Pin 10 of L293
//Right Motor
const int RIGHTM_1 = 5;  // Pin  7 of L293
const int RIGHTM_2 = 6;  // Pin  2 of L293

const int BTTX = 9;
const int BTRX = 9;

AltSoftSerial BTSerial;

char cmd;
char c = ' ';
boolean NL = true;

void forward(int duration) {
  analogWrite(LEFTM_1, 180);
  analogWrite(LEFTM_2, 0);
  analogWrite(RIGHTM_1, 180);
  analogWrite(RIGHTM_2, 0);
  delay(duration);
}

void reverse(int duration) {
  analogWrite(LEFTM_1, 0);
  analogWrite(LEFTM_2, 180);
  analogWrite(RIGHTM_1, 0);
  analogWrite(RIGHTM_2, 180);
  delay(duration);
}

void pause() {
  analogWrite(LEFTM_1, 0);
  analogWrite(LEFTM_2, 0);
  analogWrite(RIGHTM_1, 0);
  analogWrite(RIGHTM_2, 0);
}

void right(int duration) {
  analogWrite(LEFTM_1, 0);
  analogWrite(LEFTM_2, 180);
  analogWrite(RIGHTM_1, 180);
  analogWrite(RIGHTM_2, 0);
  delay(duration);
}

void left(int duration) {
  analogWrite(LEFTM_1, 180);
  analogWrite(LEFTM_2, 0);
  analogWrite(RIGHTM_1, 0);
  analogWrite(RIGHTM_2, 180);
  delay(duration);
}

void setup() {

  // enable serial port
  Serial.begin(9600);
  BTSerial.begin(9600);

  //Set pins as outputs
  pinMode(LEFTM_1, OUTPUT);
  pinMode(LEFTM_2, OUTPUT);
  pinMode(RIGHTM_1, OUTPUT);
  pinMode(RIGHTM_2, OUTPUT);

  Serial.println("READY.");
}

void loop() {
  if (BTSerial.available()) {
    char cmd = BTSerial.read();
    switch (cmd) {
      case 'f':
      case 'F': forward(100); break;
      case 'b':
      case 'B': reverse(100); break;
      case 'r':
      case 'R': right(10); break;
      case 'l':
      case 'L': left(10); break;
      case 'p':
      case 'P': pause(); break;
    }
    Serial.write(cmd);
  }
}
