#define RS 2
#define RW 3
#define EN 4

#define DB0 5
#define DB1 6
#define DB2 7
#define DB3 8
#define DB4 9
#define DB5 10
#define DB6 11
#define DB7 12

char LCD_Data;

void setup() {
  // put your setup code here, to run once:

  for(int i = 2; i<13; i++){
    pinMode(i, OUTPUT);
  }
  CharLCD_INST(0x30);
  CharLCD_INST(0x30);
  CharLCD_INST(0x30);

  CharLCD_INST(0x38);
  CharLCD_INST(0x06);
  CharLCD_INST(0x0C);
  CharLCD_INST(0x80);

  CharLCD_INST(0x01);

//  LCD_Clear();
  delay(2);
}

void loop() {
  // put your main code here, to run repeatedly:
  LCD_Clear();
  for(int i = 0; i<8; i++){
    GraphicLCD_Data(i, 3, 0xaaaa);
    delay(1000);
  }

  delay(1000);
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
