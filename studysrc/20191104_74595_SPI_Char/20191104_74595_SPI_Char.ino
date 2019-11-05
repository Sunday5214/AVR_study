#define CS 10//output
#define MOSI 11
#define CLK 13
#define LATCH 4



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //30 30 30 28 20 80 06 0c 
  pinMode(CS, OUTPUT);
  pinMode(MOSI, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(LATCH, OUTPUT);

  SPCR = 0x53; //SPi Enable, MSB First, Master, 128 분주

  CharLCD_74595_INST(0x30);
  CharLCD_74595_INST(0x30);
  CharLCD_74595_INST(0x30);
  CharLCD_74595_INST(0x28);
  //-------------------------4bit 전환
  CharLCD_74595_INST(0x20);
  CharLCD_74595_INST(0x80);
  //------------------------0x28
  CharLCD_74595_INST(0x00);
  CharLCD_74595_INST(0x60);
  //------------------------0x06
  CharLCD_74595_INST(0x00);
  CharLCD_74595_INST(0xC0);
  //------------------------0x0C
  CharLCD_74595_INST(0x80);
  CharLCD_74595_INST(0x00);
  //---------------------------0x80
  CharLCD_74595_INST(0x00);
  CharLCD_74595_INST(0x10);
  delay(2);
  //------------------------------0x01
}

void loop() {
  // put your main code here, to run repeatedly:

  CharLCD_74595_DATA(0x30);
  CharLCD_74595_DATA(0x10);
  delay(1000);
}

void CharLCD_74595_INST(char inst_data){
  char SPi_Data = 0x00;

  //RS LOW
  SPi_Data = 0x00;
  SPDR = SPi_Data; 
  while(!(SPSR & 0x80));
  latch();

  //Data
  SPi_Data = inst_data;
  SPDR = SPi_Data;//SPDR에 값을 쓰면 자동으로 
  while(!(SPSR & 0x80));
  latch();

  //enable High
  SPi_Data |= 0x04;
  SPDR = SPi_Data;//SPDR에 값을 쓰면 자동으로 
  while(!(SPSR & 0x80));
  latch();

  //enable Low
  SPi_Data &= ~0x04;
  SPDR = SPi_Data;//SPDR에 값을 쓰면 자동으로 
  while(!(SPSR & 0x80));
  latch();

  // RS HIGH;
  SPi_Data |= 0x01; 
  SPDR = SPi_Data;//SPDR에 값을 쓰면 자동으로 
  while(!(SPSR & 0x80));
  latch();

  delayMicroseconds(50);
}
void CharLCD_74595_DATA(char data){
  char SPi_Data = 0x01;
  
  //Data
  SPi_Data |= data;
  SPDR = SPi_Data;//SPDR에 값을 쓰면 자동으로 
  while(!(SPSR & 0x80));
  latch();

  //enable High
  SPi_Data |= 0x04;
  SPDR = SPi_Data;//SPDR에 값을 쓰면 자동으로 
  while(!(SPSR & 0x80));
  latch();

  //enable Low
  SPi_Data &= ~0x04;
  SPDR = SPi_Data;//SPDR에 값을 쓰면 자동으로 
  while(!(SPSR & 0x80));
  latch();
  
  delayMicroseconds(50);
}
void latch(){
  digitalWrite(LATCH, HIGH);
  digitalWrite(LATCH, LOW);
}
