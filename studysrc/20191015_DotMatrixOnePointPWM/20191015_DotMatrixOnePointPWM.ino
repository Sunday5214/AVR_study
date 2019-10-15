unsigned char num[10][8] ={
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
  TCCR2A = 0x00;
  TCCR2B = 0x02;
  TCNT2 = 206;//256-50,, 50*0.5->25->25*100->250
  TIMSK2 = 0x01;
  digitalWrite(10, HIGH);
  ////////////////////////////////
//  TCCR1A = 0x03;
//  TCCR1B = 0x0B;
//  TCCR1C = 0x00;
//  TCNT1 = 399;//1024 - 625
//  TIMSK1 = 0x03;
//  OCR1A = 459;//
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
unsigned long previousMillis[8];
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
  
// currentMicros = micros();
 currentMillis = millis();
 if(currentMillis - previousMillis[0] >= 10){
  previousMillis[0] = currentMillis;
  duty_arr[0]++;
  if(duty_arr[0]==99)duty_arr[0]= 10;
 }
 if(currentMillis - previousMillis[1] >= 20){
  previousMillis[1] = currentMillis;
  duty_arr[1]++;
  if(duty_arr[1]==99)duty_arr[1]= 10;
 }
  if(currentMillis - previousMillis[2] >= 30){
  previousMillis[2] = currentMillis;
  duty_arr[2]++;
  if(duty_arr[2]==99)duty_arr[2]= 10;
 }
 if(currentMillis - previousMillis[3] >= 40){
  previousMillis[3] = currentMillis;
  duty_arr[3]++;
  if(duty_arr[3]==99)duty_arr[3]= 10;
 }
 if(currentMillis - previousMillis[4] >= 50){
  previousMillis[4] = currentMillis;
  duty_arr[4]++;
  if(duty_arr[4]==99)duty_arr[4]= 10;
 }
  if(currentMillis - previousMillis[5] >= 60){
  previousMillis[5] = currentMillis;
  duty_arr[5]++;
  if(duty_arr[5]==99)duty_arr[5]= 10;
 }
  if(currentMillis - previousMillis[6] >= 70){
  previousMillis[6] = currentMillis;
  duty_arr[6]++;
  if(duty_arr[6]==99)duty_arr[6]= 10;
 }
  if(currentMillis - previousMillis[7] >= 80){
  previousMillis[7] = currentMillis;
  duty_arr[7]++;
  if(duty_arr[7]==99)duty_arr[7]= 10;
 }
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
// }1MHz->1us, 1KHz->1ms
//따끄고 -> 값넣고 ->넣은 줄 한줄키고
//16MHz/8 2Hz-> 0.5us
// if(currentMillis - previousMillis2 >300){
//     previousMillis2 = currentMillis;
//     //dutyarr[k] = 99;
//     k++;
//     if(k==8)k=0;
// }
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
  OCR1A = 399+(Lindidx+1)*50;
}

ISR(TIMER1_COMPA_vect){
  digitalWrite(10+Lindidx, LOW);
}

ISR(TIMER2_OVF_vect){
  TCNT2 = 206;
  count_timer2++;

  //--------------------------
    ////////////////////led0
  if(count_timer2 == 100){
    column_value = 0xFF;
    count_timer2 = 0;
    for(int i =0; i<8; i++){
     if(column_value & (0x80>>i)){
      digitalWrite(2+i, LOW);
     }
     else{
      digitalWrite(2+i, HIGH);
     }
    }
  }
  for(int j = 0; j<8; j++){
    if(count_timer2==duty_arr[j]){
      column_value &= ~(0x80>>j);
      for(int i = 0; i<8; i++){
        if(column_value & (0x80>>i)){
          digitalWrite(2+i, LOW);
        }
        else{
          digitalWrite(2+i, HIGH);
        }
      }
    }
  }
  /////
//  if(count_timer2 == duty){
//     column_value &= ~0x80;
//     for(int i =0; i<8; i++){
//      if(column_value & (0x80>>i)){
//        digitalWrite(2+i, LOW);
//      }
//      else{
//        digitalWrite(2+i, HIGH);
//      }
//    }
//  }
//  ////////////////////////////////////////////////led1
//  if(count_timer2 == duty2){
//    column_value &= ~0x40;
//     for(int i =0; i<8; i++){
//      if(column_value & (0x80>>i)){
//        digitalWrite(2+i, LOW);
//      }
//      else{
//        digitalWrite(2+i, HIGH);
//      }
//    }
//  }
//  ////////////////////////////////////////////////led2
//    if(count_timer2 == duty3){
//    column_value &= ~0x20;
//     for(int i =0; i<8; i++){
//      if(column_value & (0x80>>i)){
//        digitalWrite(2+i, LOW);
//      }
//      else{
//        digitalWrite(2+i, HIGH);
//      }
//    }
//  }
}
