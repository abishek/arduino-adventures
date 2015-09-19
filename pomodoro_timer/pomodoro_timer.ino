#include <Bounce2.h>

// Arduino Based Pomodoro Timer
// Abishek Goda < goda dot abishek at gmail >
// v0.1

// This is the very first version of the application.
// There are two LEDs and a push button.
// One LED (Red) indicates work. Other LED (Green) indicates break.
// System is idle to start. When you push the button, it enters work. After
// 25 minutes, it enters break. After 5 mins,  it goes back to idle. You need 
// to push start again to continue.
// In the work state, Red LED is lighted and in the break state, Green LED is.
// There is an optional Yellow LED to indicate Power-On/Idle condition.
// Simpler hardware also implies slightly sub optimal solution. But atleast, you won't need a RTC chip.

// The PINs to use
const int workLED     = 8 ;
const int breakLED    = 13;
const int idleLED     = 9 ;
const int startButton = 2 ;

// Status Constants
const int IDLE = 0;
const int WORK = 1;
const int BREAK = 2;

// Timer Constants
const long workInterval = 20*60*1000; // 20 minutes
const long breakInterval = 5*60*1000; // 5 minutes

// Global Variables
int status;
unsigned long prevMillis = 0;
unsigned long currMillis;
unsigned long diffMillis;

// Switch Debouncer
Bounce inpDebounce = Bounce();

void setup() {
  // there are four pins : three LEDs and one button
  // The three LED indicates whether we are in IDLE, WORK or BREAK modes
  // The button is just a START button.
  pinMode(idleLED, OUTPUT);
  pinMode(workLED, OUTPUT);
  pinMode(breakLED, OUTPUT);
  pinMode(startButton, INPUT);
  // We start at IDLE.
  digitalWrite(idleLED, HIGH);
  digitalWrite(workLED, LOW);
  digitalWrite(breakLED, LOW);
  status = IDLE;
  // Initialize the switch debouncer.
  inpDebounce.attach(startButton);
  inpDebounce.interval(5);
}

void loop() {
  if(inpDebounce.update()) {
    // We need to wait for the start button
    if(inpDebounce.read() == 1) {
      // Enter work mode.
      status = WORK;
    }
  }
 
  switch(status) {
    case WORK:
      if(diffMillis >= workInterval) {
        status = BREAK;
        digitalWrite(idleLED, LOW);
        digitalWrite(workLED, LOW);
        digitalWrite(breakLED, HIGH);
      } else {
        status = WORK;
        digitalWrite(idleLED, LOW);
        digitalWrite(workLED, HIGH);
        digitalWrite(breakLED, LOW);
      }
      break;
    
    case BREAK:
      if(diffMillis >= breakInterval) {
        status = IDLE;
        digitalWrite(idleLED, HIGH);
        digitalWrite(workLED, LOW);
        digitalWrite(breakLED, LOW);
      } else {
        status = BREAK;
        digitalWrite(idleLED, LOW);
        digitalWrite(workLED, LOW);
        digitalWrite(breakLED, HIGH);
      }
      break;

    case IDLE:
      digitalWrite(idleLED, HIGH);
      digitalWrite(workLED, LOW);
      digitalWrite(breakLED, LOW);  
      break;
  }
}
