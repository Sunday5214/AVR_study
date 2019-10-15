unsigned char num[10][8] = {
  {0xFF, 0x38, 0x44, 0x4c, 0x54, 0x64, 0x44, 0x38},
  {0xFF, 0x10, 0x30, 0x50, 0x10, 0x10, 0x10, 0x7c},
  {0xFF, 0x38, 0x44, 0x04, 0x08, 0x10, 0x20, 0x7c},
  {0xFF, 0x38, 0x44, 0x04, 0x18, 0x04, 0x44, 0x38},
  {0xFF, 0x08, 0x18, 0x28, 0x48, 0x7c, 0x08, 0x08},
  {0xFF, 0x7c, 0x40, 0x78, 0x04, 0x04, 0x44, 0x38},
  {0xFF, 0x38, 0x40, 0x40, 0x78, 0x44, 0x44, 0x38},
  {0xFF, 0x7c, 0x04, 0x08, 0x10, 0x20, 0x20, 0x20},
  {0xFF, 0x38, 0x44, 0x44, 0x38, 0x44, 0x44, 0x38},
  {0xFF, 0x38, 0x44, 0x44, 0x3c, 0x04, 0x44, 0x38}
};

//한점으로 가변하려면 25us마다
void setup() {
  // put your setup code here, to run once:
  for (int i = 2; i < 18; i++) {
    pinMode(i, OUTPUT);
  }

  // col pin low(0000000)

  for (int i = 2; i < 10; i++) {
    digitalWrite(i, HIGH);
  }
  for (int i = 10; i < 18; i++) {
    digitalWrite(i, LOW);
  }
  TCCR2A = 0x03;
  TCCR2B = 0x02;
  TCNT2 = 156;//50단계*2->100 100*0.5->50
  OCR2A = 206;
  TIMSK2 = 0x01;
  digitalWrite(10, HIGH);
  ////////////////////////////////
  //  TCCR1A = 0x03;
  //  TCCR1B = 0x0B;
  //  TCCR1C = 0x00;
  //  TCNT1 = 399;//1024 - 625
  //  TIMSK1 = 0x03;
  //  OCR1A = 459;//
}
//int i=0, j=0, k=0;
//int num[8] = {0x00, 0x38, 0x44, 0x04, 0x18, 0x04, 0x44, 0x38}
//unsigned long currentMicros = 0;
unsigned long currentMillis = 0;
//unsigned long currentMillis2 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis = 0;
//unsigned long previousMillis[8];
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
int count_timer2 = 0;
int duty = 10;
int duty2 = 10;
int duty_arr[8];
unsigned column_value = 0;
void loop() {
  currentMillis = millis();
  if (currentMillis - previousMillis >= 10) {
    previousMillis = currentMillis;
    duty2++;
    if (duty2 == 99)
      duty2= 10;
  }
  if (currentMillis - previousMillis2 >= 200) {
    previousMillis2= currentMillis;
    k++;
    if (k == 8)
      k= 0;
  }
}

//ISR(TIMER1_OVF_vect){
//  TCNT1 = 399;
//  Lindidx++;
//  if(Lindidx==8)Lindidx=0;
//  for(int i=10; i<18; i++){
//    digitalWrite(i, LOW);
//  }
//  for(int i =0; i<8; i++){
//    if(num[k][Lindidx] & (0x80>>i)){
//      digitalWrite(2+i, LOW);
//    }
//    else{
//      digitalWrite(2+i, HIGH);
//    }
//  }
//  digitalWrite(10+Lindidx, HIGH);
//  OCR1A = 399+(Lindidx+1)*50;
//}
//
//ISR(TIMER1_COMPA_vect){
//  digitalWrite(10+Lindidx, LOW);
//}

ISR(TIMER2_OVF_vect) {
  TCNT2 = 156;
  count_timer2++;

  //--------------------------
  ////////////////////led0
  if (count_timer2 == 50) {
    count_timer2 = 0;
    
    Lindidx++;
    if (Lindidx == 8)Lindidx = 0;
//--------------------------------------
    for (int i = 10; i < 18; i++) {
      digitalWrite(i, LOW);
    }
//--------------------------------------
    column_value = 0xFF;
    num[3][0] = column_value;
    for (int i = 0; i < 8; i++) {
      if (num[k][Lindidx] & (0x80 >> i)) {
        digitalWrite(2 + i, LOW);
      }
      else {
        digitalWrite(2 + i, HIGH);
      }
    }
    //------------------------------------
    digitalWrite(10 + Lindidx, HIGH);
  }
  
  if (count_timer2 == duty2) {
    column_value &= ~(0x80);
    num[3][0] = column_value;
    for (int i = 0; i < 8; i++) {
      if (num[3][Lindidx] & (0x80 >> i)) {
        digitalWrite(2 + i, LOW);
      }
      else {
        digitalWrite(2 + i, HIGH);
      }
    }
  }
}
