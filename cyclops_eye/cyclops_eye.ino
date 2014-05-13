int out;
int counter;
int val;
int up;
void setup() {
  
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  counter = 0;
  up = 1;
  Serial.begin(9600);
}

void loop() {

  digitalWrite(5, out & 1);
  digitalWrite(6, out & 2);
  digitalWrite(7, out & 4);
  digitalWrite(8, out & 8);
  if(up) 
    counter = counter + 1;
  else 
    counter = counter - 1;
  if(counter == 4) {
    up = 0;
  }
  if(counter == 0) {
    up = 1;
  }
  out = 1 << counter;
  delay(500);

}

