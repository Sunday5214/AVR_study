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

#define DATAMAX 10
unsigned char number = 0x80;//->00000001->00000011
unsigned char ALLnumber[DATAMAX]= {  
                      B00110000, //0 
                      B00110001, //1
                      B00110010,//2
                      B00110011,//3
                      B00110100,//4
                      B00110101,//5
                      B00110110,//6
                      B00110111,//7
                      B00111000,//8
                      B00111001 //9
                      };
void setup() {
  // put your setup code here, to run once:
  initLCD();
    char_data_insert(0);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void char_data_insert(unsigned char Wnum){
  int res[8];
  for(int i=0; i<8; i++){
    res[i] =ALLnumber[Wnum]&(number>>i);
  }
  digitalWrite(RS, HIGH);
//0100 1010
  digitalWrite(DB7, res[0]);
  digitalWrite(DB6, res[1]);
  digitalWrite(DB5, res[2]);
  digitalWrite(DB4, res[3]);

  digitalWrite(E, HIGH);
  digitalWrite(E, LOW);

  delayMicroseconds(50);

  digitalWrite(DB7, res[4]);
  digitalWrite(DB6, res[5]);
  digitalWrite(DB5, res[6]);
  digitalWrite(DB4, res[7]);

  digitalWrite(E, HIGH);
  digitalWrite(E, LOW);

  delayMicroseconds(50);
}

void initLCD(){
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
}
