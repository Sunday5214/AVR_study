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
  digitalWrite(2, LOW);
  //digitalWrite(3, LOW);
  Serial.begin(9600);
}
//int i=0, j=0, k=0;
//int num[8] = {0x00, 0x38, 0x44, 0x04, 0x18, 0x04, 0x44, 0x38}
//unsigned long currentMicros = 0;
unsigned long currentMillis = 0;
unsigned long currentMillis2 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis = 0;
//unsigned long previousMillis2 = 0;
unsigned long currentMicros = 0;
unsigned long previousMicros = 0;
int count = 0;
int count2 = 0;
int count3 = 0;
int duty = 0;
int duty2 = 0;
int duty3 = 0;
int data = 0;
int k = 0;
int dutyarr[8];
int countarr[8];
void loop() {
//  if(Serial.available()){
//    data = Serial.read();
//    dutyarr[data - 0x31] = 99;
//  }
 currentMicros = micros();
 currentMillis = millis();

  if(currentMicros - previousMicros > 100){
    previousMicros = currentMicros;
    for(int i=0; i<8; i++){
      countarr[i]++;
      if(countarr[i] == 100){
        countarr[i] = 0;
        if(dutyarr[i]!=0){
          digitalWrite(10+i, HIGH);
        }
      }
      else if(countarr[i] == dutyarr[i]){
        digitalWrite(10+i, LOW);
      }
    } 
  if(currentMillis - previousMillis2 >300){
     previousMillis2 = currentMillis;
     dutyarr[k] = 99;
     k++;
     if(k==8)k=0;
  }
//    count++;
//    if(count == 100){
//      count = 0;
//      if(duty!=0){
//          digitalWrite(10, HIGH);
//      }
//    }
//    else if(count == duty){
//      digitalWrite(10, LOW);
//    }
//    count2++;
//    if(count2==100){
//       count2=0;
//      if(duty2!=0){
//          digitalWrite(11, HIGH);
//      }
//    }
//    else if(count2==duty2){
//      digitalWrite(11, LOW);
//    }
//    count3++;
//    if(count3==100){
//      
//    }
  }
 if(currentMillis - previousMillis > 10){
    previousMillis = currentMillis;
    for(int i =0; i<8; i++){
      if(dutyarr[i]>0){
        dutyarr[i]--;
      }
    }
  }
// if(currentMillis - previousMillis2 > 10){
//    previousMillis2 = currentMillis;
//    if(duty2>0)duty2--;
//  }
//  if(currentMillis - previousMillis > 100){
//    previousMillis = currentMillis;
//    if(duty==90)duty=0;
//    if(point==9)point = 2;
//    duty++;
//  }
  

  // put your main code here, to run repeatedly:
//  currentMicros = micros();
//  currentMillis = millis();
//
//  if(currentMicros - previousMicros > 2500){
//    previousMicros = currentMicros;
//    for(i)
//    digitalWrite(10+j, HIGH);
//    j++;
//    if(j==8)j=0;
//  }
//
//  if(currentMillis2 - previousMillis2 > 1000){
//    previousMillis2 = currentMillis2;
//
//    k++;
//    if(k==2)k=0;
//  }
}
