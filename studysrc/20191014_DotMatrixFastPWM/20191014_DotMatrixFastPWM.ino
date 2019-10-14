char num[10][8] ={
  {0x00, 0x38, 0x44, 0x4c, 0x54, 0x64, 0x44, 0x38},
  {0x00, 0x10, 0x30, 0x50, 0x10, 0x10, 0x10, 0x7c},
  {0x00, 0x38, 0x44, 0x04, 0x08, 0x10, 0x20, 0x7c},
  {0x00, 0x38, 0x44, 0x04, 0x18, 0x04, 0x44, 0x38},
  {0x00, 0x08, 0x18, 0x28, 0x48, 0x7c, 0x08, 0x08},
  {0x00, 0x7c, 0x40, 0x78, 0x04, 0x04, 0x44, 0x38},
  {0x00, 0x38, 0x40, 0x40, 0x78, 0x44, 0x44, 0x38},
  {0x00, 0x7c, 0x04, 0x08, 0x10, 0x20, 0x20, 0x20},
  {0x00, 0x38, 0x44, 0x44, 0x38, 0x44, 0x44, 0x38},
  {0x00, 0x38, 0x44, 0x44, 0x3c, 0x04, 0x44, 0x38}
};
void setup() {
  // put your setup code here, to run once:
  for(int i = 2; i<18; i++){
    pinMode(i, OUTPUT);
  }

// col pin low(0000000)

  for(int i = 2; i<10; i++){
    digitalWrite(i, HIGH);
  }
  for(int i = 10; i<18; i++){
    digitalWrite(i, LOW);
  }
  
  TCCR1A = 0x03;
  TCCR1B = 0x0B;
  TCCR1C = 0x00;
  TCNT1 = 399;//1024 - 625
  OCR1A = 399;//399부터 시작하므로 0퍼 듀티만들기위해
  TIMSK1 = 0x03;
  OCR1A = 459;
//  for(int i = 2; i<18; i++){
//    pinMode(i, OUTPUT);
//  }
//
//// col pin low(0000000)
//
//  for(int i = 2; i<10; i++){
//    digitalWrite(i, HIGH);
//  }
//  for(int i = 10; i<18; i++){
//    digitalWrite(i, LOW);
//  }
//  digitalWrite(2, LOW);
//  //digitalWrite(3, LOW);
//  Serial.begin(9600);
}
//int i=0, j=0, k=0;
//int num[8] = {0x00, 0x38, 0x44, 0x04, 0x18, 0x04, 0x44, 0x38}
//unsigned long currentMicros = 0;
unsigned long currentMillis = 0;
//unsigned long currentMillis2 = 0;
//unsigned long previousMillis2 = 0;
//unsigned long previousMillis = 0;
unsigned long previousMillis2 = 0;
//unsigned long currentMicros = 0;
//unsigned long previousMicros = 0;
//int count = 0;
//int count2 = 0;
//int count3 = 0;
//int duty = 0;
//int duty2 = 0;
//int duty3 = 0;
//int data = 0;
int k = 0;
//int dutyarr[8];
//int countarr[8];
int Lindidx = 0;
void loop() {
  
// currentMicros = micros();
 currentMillis = millis();
//
//  if(currentMicros - previousMicros > 100){
//    previousMicros = currentMicros;
//    for(int i=0; i<8; i++){
//      countarr[i]++;
//      if(countarr[i] == 100){
//        countarr[i] = 0;
//        if(dutyarr[i]!=0){
//          digitalWrite(10+i, HIGH);
//        }
//      }
//      else if(countarr[i] == dutyarr[i]){
//        digitalWrite(10+i, LOW);
//      }
//    } 
// }
 if(currentMillis - previousMillis2 >300){
     previousMillis2 = currentMillis;
     //dutyarr[k] = 99;
     k++;
     if(k==8)k=0;
 }
// if(currentMillis - previousMillis > 10){
//    previousMillis = currentMillis;
//    for(int i =0; i<8; i++){
//      if(dutyarr[i]>0){
//        dutyarr[i]--;
//      }
//    }
//  }
}

ISR(TIMER1_OVF_vect){
  TCNT1 = 399;
  Lindidx++;
  if(Lindidx==8)Lindidx=0;
  for(int i=10; i<18; i++){
    digitalWrite(i, LOW);
  }
  for(int i =0; i<8; i++){
    if(num[k][Lindidx] & (0x80>>i)){
      digitalWrite(2+i, LOW);
    }
    else{
      digitalWrite(2+i, HIGH);
    }
  }
  digitalWrite(10+Lindidx, HIGH);

}
ISR(TIMER1_COMPA_vect){
  digitalWrite(10+Lindidx, LOW);
}
