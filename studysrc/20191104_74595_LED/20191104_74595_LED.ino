#define DATA 11
#define CLOCK 13
#define LATCH 4

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(DATA, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  shiftOut(DATA, CLOCK, MSBFIRST, 0x01);
  latch();
  delay(1000);

  shiftOut(DATA, CLOCK, MSBFIRST, 0x00);
  latch();
  delay(1000);
}

void latch(){
  digitalWrite(LATCH, HIGH);
  
  digitalWrite(LATCH, LOW);
}
