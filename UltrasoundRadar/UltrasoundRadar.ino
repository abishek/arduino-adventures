#include <NewPing.h>
#include <Servo.h>

#define TRIG_PIN 12
#define ECHO_PIN 11
#define MAX_DIST 200
#define SERVO 9

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DIST);
Servo motor;

void setup() {
  Serial.begin(9600);
  motor.attach(SERVO);
  motor.write(95);
}

void loop() {
  Serial.println(sonar.ping_cm());
  delay(50);
}
