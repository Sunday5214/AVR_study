#define RS 2
#define E 3

#define DB0 4
#define DB1 5
#define DB2 6
#define DB3 7

#define DB4 8
#define DB5 9
#define DB6 10
#define DB7 11

void setup() {
  // put your setup code here, to run once:
    for(int i=2; i<12; i++) {
     pinMode(i, OUTPUT);
  }
  digitalWrite(RS, LOW);
  
  digitalWrite(DB7, LOW);
  digitalWrite(DB6, LOW);
  digitalWrite(DB5, HIGH);
  digitalWrite(DB4, HIGH);

  digitalWrite(E, HIGH);
  digitalWrite(E, LOW);

  digitalWrite(RS, HIGH);

  delayMicroseconds(50);

  digitalWrite(RS, LOW);
  
  digitalWrite(DB7, LOW);
  digitalWrite(DB6, LOW);
  digitalWrite(DB5, HIGH);
  digitalWrite(DB4, HIGH);

  digitalWrite(E, HIGH);
  digitalWrite(E, LOW);

  digitalWrite(RS, HIGH);

  delayMicroseconds(50);

  digitalWrite(RS, LOW);
  
  digitalWrite(DB7, LOW);
  digitalWrite(DB6, LOW);
  digitalWrite(DB5, HIGH);
  digitalWrite(DB4, HIGH);

  digitalWrite(E, HIGH);
  digitalWrite(E, LOW);

  digitalWrite(RS, HIGH);

  delayMicroseconds(50);
  //-------------------------------0x28
  digitalWrite(RS, LOW);
  
  digitalWrite(DB7, LOW);
  digitalWrite(DB6, LOW);
  digitalWrite(DB5, HIGH);
  digitalWrite(DB4, LOW);

  digitalWrite(E, HIGH);
  digitalWrite(E, LOW);

  digitalWrite(RS, HIGH);

  delayMicroseconds(50);
  //--------------------------------0x28다시
  digitalWrite(RS, LOW);
  
  digitalWrite(DB7, LOW);
  digitalWrite(DB6, LOW);
  digitalWrite(DB5, HIGH);
  digitalWrite(DB4, LOW);

  digitalWrite(E, HIGH);
  digitalWrite(E, LOW);

  digitalWrite(RS, HIGH);

  delayMicroseconds(50);
  digitalWrite(RS, LOW);
  
  digitalWrite(DB7, HIGH);
  digitalWrite(DB6, LOW);
  digitalWrite(DB5, LOW);
  digitalWrite(DB4, LOW);

  digitalWrite(E, HIGH);
  digitalWrite(E, LOW);

  digitalWrite(RS, HIGH);

  delayMicroseconds(50);
  //-----------------------------------0x06
  digitalWrite(RS, LOW);
  
  digitalWrite(DB7, LOW);
  digitalWrite(DB6, LOW);
  digitalWrite(DB5, LOW);
  digitalWrite(DB4, LOW);

  digitalWrite(E, HIGH);
  digitalWrite(E, LOW);

  digitalWrite(RS, HIGH);

  delayMicroseconds(50);

  digitalWrite(RS, LOW);
  
  digitalWrite(DB7, LOW);
  digitalWrite(DB6, HIGH);
  digitalWrite(DB5, HIGH);
  digitalWrite(DB4, LOW);

  digitalWrite(E, HIGH);
  digitalWrite(E, LOW);

  digitalWrite(RS, HIGH);

  delayMicroseconds(50);
  //-----------------------------------------------0x0C
  digitalWrite(RS, LOW);
  
  digitalWrite(DB7, LOW);
  digitalWrite(DB6, LOW);
  digitalWrite(DB5, LOW);
  digitalWrite(DB4, LOW);

  digitalWrite(E, HIGH);
  digitalWrite(E, LOW);

  digitalWrite(RS, HIGH);

  delayMicroseconds(50);

  digitalWrite(RS, LOW);
  
  digitalWrite(DB7, HIGH);
  digitalWrite(DB6, HIGH);
  digitalWrite(DB5, LOW);
  digitalWrite(DB4, LOW);

  digitalWrite(E, HIGH);
  digitalWrite(E, LOW);

  digitalWrite(RS, HIGH);

  delayMicroseconds(50);
  //--------------------------------------------------0x80
  digitalWrite(RS, LOW);
  
  digitalWrite(DB7, HIGH);
  digitalWrite(DB6, LOW);
  digitalWrite(DB5, LOW);
  digitalWrite(DB4, LOW);

  digitalWrite(E, HIGH);
  digitalWrite(E, LOW);

  digitalWrite(RS, HIGH);

  delayMicroseconds(50);

  digitalWrite(RS, LOW);
  
  digitalWrite(DB7, LOW);
  digitalWrite(DB6, LOW);
  digitalWrite(DB5, LOW);
  digitalWrite(DB4, LOW);

  digitalWrite(E, HIGH);
  digitalWrite(E, LOW);

  digitalWrite(RS, HIGH);

  delayMicroseconds(50);
  //-----------------------------------------------------0x01
  digitalWrite(RS, LOW);
  
  digitalWrite(DB7, LOW);
  digitalWrite(DB6, LOW);
  digitalWrite(DB5, LOW);
  digitalWrite(DB4, LOW);

  digitalWrite(E, HIGH);
  digitalWrite(E, LOW);

  digitalWrite(RS, HIGH);

  delayMicroseconds(50);

  digitalWrite(RS, LOW);
  
  digitalWrite(DB7, LOW);
  digitalWrite(DB6, LOW);
  digitalWrite(DB5, LOW);
  digitalWrite(DB4, HIGH);

  digitalWrite(E, HIGH);
  digitalWrite(E, LOW);

  digitalWrite(RS, HIGH);

  delay(2);

    digitalWrite(RS, HIGH);
  
  digitalWrite(DB7, LOW);
  digitalWrite(DB6, LOW);
  digitalWrite(DB5, HIGH);
  digitalWrite(DB4, HIGH);

  digitalWrite(E, HIGH);
  digitalWrite(E, LOW);

  //digitalWrite(RS, HIGH);

  delayMicroseconds(50);

 // digitalWrite(RS, LOW);
  
  digitalWrite(DB7, LOW);
  digitalWrite(DB6, LOW);
  digitalWrite(DB5, LOW);
  digitalWrite(DB4, HIGH);

  digitalWrite(E, HIGH);
  digitalWrite(E, LOW);

  //digitalWrite(RS, HIGH);

  delayMicroseconds(50);
}

void loop() {
  // put your main code here, to run repeatedly:

}
