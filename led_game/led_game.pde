int out;
int counter;
int val;
void setup() {
  
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  attachInterrupt(1, pressed, RISING);
  counter = 0;
  Serial.begin(9600);
}

void pressed() {
  if (out & 2) {
    digitalWrite(10, 1);
    delayMicroseconds(10000000);
    digitalWrite(10, 0);
  }
}

void loop() {

  val = analogRead(5);
  digitalWrite(5, out & 1);
  digitalWrite(6, out & 2);
  digitalWrite(7, out & 4);
  digitalWrite(8, out & 8);
  counter = counter + 1;
  if(counter == 4) counter = 0;
  out = 1 << counter;
  delay(val/2);

}

