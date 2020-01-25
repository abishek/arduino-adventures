# define STRAIGHT 1
# define LEFT 2
# define RIGHT 3
# define STOP 0

// Line Follower Sensors
const int leftSensor = 2;
const int middleSensor = 3;
const int rightSensor = 4;

//Left Motor
const int motorPin1  = 9;  // Pin 14 of L293
const int motorPin2  = 10;  // Pin 10 of L293
//Right Motor
const int motorPin3  = 5; // Pin  7 of L293
const int motorPin4  = 6;  // Pin  2 of L293

void goForward(int duration) {
    analogWrite(motorPin1, 180);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 180);
    analogWrite(motorPin4, 0);
    delay(duration);
}

void goReverse(int duration) {
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 180);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 180);
    delay(duration);
}

void pauseMotors() {
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 0);
}

void turnRight(int duration) {
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 180);
    analogWrite(motorPin3, 180);
    analogWrite(motorPin4, 0);
    delay(duration);
}

void turnLeft(int duration) {
    analogWrite(motorPin1, 180);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 180);
    delay(duration);
}

void setup(){
 
    //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    
    //Set sensor pins as inputs
    pinMode(leftSensor, INPUT);
    pinMode(middleSensor, INPUT);
    pinMode(rightSensor, INPUT);
}

int readSensors() {
  // if mid sensor is off and the rest are on, go straight
  // if left sensor is off and rest are on, go left
  // if right sensor is off and rest are on, go right
  // otherwise, just halt
  int lft = digitalRead(leftSensor);
  int mid = digitalRead(middleSensor);
  int rgt = digitalRead(rightSensor);
  if(lft == 1 && rgt == 1 && mid == 0) {
    return STRAIGHT;
  }
  if(lft == 0 && mid == 1 && rgt == 1) {
    return LEFT;
  }
  if(rgt == 0 && mid == 1 && lft == 1) {
    return RIGHT;
  }
  return STOP;
}

void loop(){
  // read the three sensors
  int cmd = readSensors();
  switch(cmd) {
    case STRAIGHT: goForward(500); break;
    case LEFT: turnLeft(100); break;
    case RIGHT: turnRight(100); break;
    default: pauseMotors(); break;
  }
}
