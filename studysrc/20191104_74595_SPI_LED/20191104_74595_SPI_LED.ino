#define CS 10//output
#define MOSI 11
#define CLK 13
#define LATCH 4

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(CS, OUTPUT);
  pinMode(MOSI, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(LATCH, OUTPUT);

  SPCR = 0x53; //SPi Enable, MSB First, Master, 128 분주
}

void loop() {
  // put your main code here, to run repeatedly:
  //shiftOut(DATA, CLOCK, MSBFIRST, 0x01);
  SPDR = 0x01;//SPDR에 값을 쓰면 자동으로 
  while(!(SPSR & 0x80));
  latch();
  delay(1000);

  SPDR = 0x00;//SPDR에 값을 쓰면 자동으로 
  while(!(SPSR & 0x80));
  latch();
  delay(1000);
}

void latch(){
  digitalWrite(LATCH, HIGH);
  
  digitalWrite(LATCH, LOW);
}
