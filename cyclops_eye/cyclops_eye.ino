
int intensity0[] = {1, 5, 10, 100, 250};
int intensity1[] = {5, 10, 100, 250, 100};
int intensity2[] = {10, 100, 250, 100, 10};
int intensity3[] = {100, 250, 100, 10, 5};
int intensity4[] = {250, 100, 10, 5, 1};
int counter;
int up;

void setup() {
  
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  counter = 0;
  up = 1;
}

void loop() {
  analogWrite(5, intensity0[counter]);
  analogWrite(6, intensity1[counter]);
  analogWrite(9, intensity2[counter]);
  analogWrite(10, intensity3[counter]);
  analogWrite(11, intensity4[counter]);
  
  delay(200);
  if(counter == 0) up = 1;
  if(counter == 4) up = 0;
  if(up)
    counter ++;
  else 
    counter --;
}

