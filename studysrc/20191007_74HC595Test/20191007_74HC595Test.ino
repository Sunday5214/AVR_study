#define data 2
#define shiftclock 3
#define latch 4
unsigned char inputdata = 0x00;
void setup() {
  // put your setup code here, to run once:
  pinMode(data, OUTPUT);
  pinMode(shiftclock, OUTPUT);
  pinMode(latch, OUTPUT);

  CharInsertCommand(0x30);
  CharInsertCommand(0x30);
  CharInsertCommand(0x30);
  CharInsertCommand(0x20);
  
  CharInsertCommand(0x28);
  CharInsertCommand(0x06);
  CharInsertCommand(0x0C);
  CharInsertCommand(0x80);
  CharInsertCommand(0x01);
   CharInsertData(0x31);

}
//DB7 DB6 DB5 DB4 ㅡ E ㅡ RS
//   0      0      0     0      0  0  0   0
void loop() {
  // put your main code here, to run repeatedly:
   //------------------------------------------0x30*3

     CharInsertData(0x31);
     delay(1000);
  
}
void CharInsertCommand(unsigned char WByte){
  unsigned char Front = (WByte&0xF0)>>4;//1111 0000
  unsigned char Back = WByte&0x0F;
  //RS LOW
  inputdata = 0x00;
  BitInsert(inputdata);
  //MSB Data
  inputdata |= (Front<<4);
  BitInsert(inputdata);
  //Enable HIGH
  inputdata |= 0x04;
  BitInsert(inputdata);
  //Enable LOW
  inputdata &= ~(0x04);
  BitInsert(inputdata);
  //RS HIGH
  inputdata |= 0x01;
  BitInsert(inputdata);
  delayMicroseconds(50);
  
  if(WByte != 0x30 && WByte !=0x20){
  //RS LOW
  inputdata = 0x00;
  BitInsert(inputdata);
  //LSB Data
  inputdata |= (Back<<4);
  BitInsert(inputdata);
  //Enable HIGH
  inputdata |= 0x04;
  BitInsert(inputdata);
  //Enable LOW
  inputdata &= ~(0x04);
  BitInsert(inputdata);
  //RS HIGH
  inputdata |= 0x01;
  BitInsert(inputdata);
  delayMicroseconds(50);
  }
  if(WByte==0x01){
    delay(2);
  }
  else{
    delayMicroseconds(50);
  }
}
void CharInsertData(unsigned char WByte){//0x31
  unsigned char Front = (WByte&0xF0)>>4;//0000 0011
  unsigned char Back = WByte&0x0F;//0000 0001
  //RS HIGH
  inputdata = 0x01;
  BitInsert(inputdata);
  //MSB Data
  inputdata |= (Front<<4);
  BitInsert(inputdata);
  //Enable HIGH
  inputdata |= 0x04;
  BitInsert(inputdata);
  //Enable LOW
  inputdata &= ~(0x04);
  BitInsert(inputdata);
  //RS HIGH
  inputdata |= 0x01;
  BitInsert(inputdata);
  delayMicroseconds(50);
  //RS HIGH
  inputdata = 0x01;
  BitInsert(inputdata);
  //LSB Data
  inputdata |= (Back<<4);//0000 0000 
  BitInsert(inputdata);
  //Enable HIGH
  inputdata |= 0x04;
  BitInsert(inputdata);
  //Enable LOW
  inputdata &= ~(0x04);
  BitInsert(inputdata);
  //RS HIGH
  inputdata |= 0x01;
  BitInsert(inputdata);
  delayMicroseconds(50);
}
void BitInsert(unsigned char WBit){
  for(int i = 0; i<8; i++){
    if(WBit & 0x80>>i){
      digitalWrite(data, HIGH);
    }
    else{
      digitalWrite(data, LOW);
    }
    digitalWrite(shiftclock, HIGH);
    digitalWrite(shiftclock, LOW);

  }
  //data HIGH->1->SHCK HIGHLOW->1010 0000->latch->8비트가
  digitalWrite(latch, HIGH);
  digitalWrite(latch, LOW);

  delayMicroseconds(100);
}
