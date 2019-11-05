#define RS 2
#define RW 3
#define EN 4
#define CS RS
#define SCLK EN
#define SID RW
char LCD_Data;

void setup() {
  // put your setup code here, to run once:

  for(int i = 2; i<13; i++){
    pinMode(i, OUTPUT);
  }


  
  GraphicLCD_Serial_INST(0x30);
  GraphicLCD_Serial_INST(0x30);
  GraphicLCD_Serial_INST(0x30);

  GraphicLCD_Serial_INST(0x38);
  GraphicLCD_Serial_INST(0x06);
  GraphicLCD_Serial_INST(0x0C);
  GraphicLCD_Serial_INST(0x80);

  GraphicLCD_Serial_INST(0x01);
  
  delay(2);
}

void loop() {
  // put your main code here, to run repeatedly
  GraphicLCD_Serial_DATA(0x31);
  delay(1000);
  //------------
  
}

void GraphicLCD_Serial_INST(char inst_data){
  digitalWrite(CS, HIGH);
  shiftOut(SID, SCLK, MSBFIRST, 0xF8);
  shiftOut(SID, SCLK, MSBFIRST, inst_data&0xf0);
  shiftOut(SID, SCLK, MSBFIRST, (inst_data & 0x0f)<<4);
  digitalWrite(CS, LOW);
}
void GraphicLCD_Serial_DATA(char data){
  digitalWrite(CS, HIGH);
  shiftOut(SID, SCLK, MSBFIRST, 0xFA);
  shiftOut(SID, SCLK, MSBFIRST, data&0xf0);
  shiftOut(SID, SCLK, MSBFIRST, (data & 0x0f)<<4);
  digitalWrite(CS, LOW);
}
void GraphicLCD_Data(int x, int y, unsigned short data){
  CharLCD_INST(0x36);
  CharLCD_INST(0x80+(y%32));
  CharLCD_INST(0x80+(y/32)*8+x);

  CharLCD_INST(0x30);
  CharLCD_DATA((data & 0xff00)>>8);
  CharLCD_DATA(data & 0xff);
}

void LCD_Clear(){
  for(int j = 0; j<8; j++){
    for(int i = 0; i<64; i++){
      CharLCD_INST(0x36); //Extended mode, Graphic display
      CharLCD_INST(0x80+(i%32)); //y
      CharLCD_INST(0x80+(i/32)*8+j); //x

      CharLCD_INST(0x30);
      CharLCD_DATA(0x00);
      CharLCD_DATA(0x00);
    }
  }
}

void CharLCD_INST(char LCD_INST_Data){
  
  digitalWrite(RS, LOW);
  for(int i=0; i<8; i++){
    if(LCD_INST_Data & (0x80 >> i)){
      digitalWrite(5+(7-i), HIGH);
    }
    else{
      digitalWrite(5+(7-i), LOW);
    }
  }

  digitalWrite(EN, HIGH);
  digitalWrite(EN, LOW);

  digitalWrite(RS, HIGH);

  delayMicroseconds(50);
}
void CharLCD_DATA(char LCD_Data){
  
  for(int i=0; i<8; i++){
    if(LCD_Data & (0x80 >> i)){
      digitalWrite(5+(7-i), HIGH);
    }
    else{
      digitalWrite(5+(7-i), LOW);
    }
  }

  digitalWrite(EN, HIGH);
  digitalWrite(EN, LOW);

  delayMicroseconds(50);
}
