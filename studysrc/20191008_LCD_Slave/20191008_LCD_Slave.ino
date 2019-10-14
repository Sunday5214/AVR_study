#include<Wire.h>

#define INST 0
#define DATA 1

void setup() {
  // put your setup code here, to run once:
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(13, OUTPUT); //CLK pin output
  pinMode(11, OUTPUT); //MOSI pin output
  pinMode(10, OUTPUT); //SS pin output
  SPCR = 0x51;//SPI Enable, MasterMode, Clokc:1MHz
    //----------------------------------8비트모드
  char_lcd_set_8(0x30, INST);//0x30
  char_lcd_set_8(0x30, INST);//0x30
  char_lcd_set_8(0x30, INST);//0x30

  char_lcd_set_8(0x28, INST);//0x28
  //-----------------------------------4비트모드
  char_lcd_set_4(0x02, INST);//0x28
  char_lcd_set_4(0x08, INST);//0x28
  char_lcd_set_4(0x00, INST);//0x06
  char_lcd_set_4(0x06, INST);//0x06
  char_lcd_set_4(0x00, INST);//0x0C
  char_lcd_set_4(0x0C, INST);//0x0C
  char_lcd_set_4(0x08, INST);//0x80
  char_lcd_set_4(0x00, INST);//0x80
  char_lcd_set_4(0x00, INST);//0x01
  char_lcd_set_4(0x01, INST);//0x01
}

void loop() {
  // put your main code here, to run repeatedly:

  delay(1000);
}
void receiveEvent(int howmany){
  unsigned char data = 0;
  unsigned char highbit = 0;
  unsigned char lowbit = 0;
  while(1 < Wire.available()){
    data = Wire.read();
    Serial.println(data, 16);
  }
  highbit = data>>4;
  lowbit = (data|0xF0)&0x0F;
  char_lcd_set_4(highbit, DATA);
  char_lcd_set_4(lowbit, DATA);
}
void char_lcd_set_4(char data, char flag){
  data = data << 4;
  SPDR = 0x00 | flag;
  while(!(SPSR & 0x80));
  latch();
  SPDR = data | flag;
  while(!(SPSR & 0x80));
  latch();
  SPDR = data | flag | 0x04;
  while(!(SPSR & 0x80));
  latch();
  SPDR = data | flag & (~0x04);
  while(!(SPSR & 0x80));
  latch();
  SPDR = data | 0x01;
  while(!(SPSR & 0x80));
  latch();
  delayMicroseconds(50);
}
void char_lcd_set_8(char data, char flag){
  SPDR = 0x00 | flag;
  while(!(SPSR & 0x80));
  latch();
  SPDR = data | flag;
  while(!(SPSR & 0x80));
  latch();
  SPDR = data | flag | 0x04;
  while(!(SPSR & 0x80));
  latch();
  SPDR = data | flag & (~0x04);
  while(!(SPSR & 0x80));
  latch();
  SPDR = data | 0x01;
  while(!(SPSR & 0x80));
  latch();
  delayMicroseconds(50);
}
void latch(){
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
}
