void setup() {
  // put your setup code here, to run once:
  for(int i = 1; i<18; i++){
    pinMode(i, OUTPUT);
  }

// col pin low(0000000)
  for(int i = 2; i<10; i++){
    digitalWrite(i, LOW);
  }
  for(int i = 10; i<18; i++){
    digitalWrite(i, HIGH);  
  }
 //row pin off
//  for(int i = 10; i<=17; i++){
//    digitalWrite(i, LOW);
//  }
  //---------------------------------
}

void loop() {
//      for(int j = 0; j<8; j++){
//      for(int i=10; i<18; i++){
//        digitalWrite(i, LOW);
//      }
//  //-------------------------------
//  //2.col value
//  for(int i=0; i<8; i++){
//        if(num[j] & (0x80>>i)){
//          digitalWrite(2+i, LOW);
//        }
//       else{
//          digitalWrite(2+i, HIGH);
//        }
//      }
//      digitalWrite(10, HIGH);
//      delayMicroseconds(2500);
//  //
//      //1. 8개 row pin off
//      for(int i=10; i<18; i++){
//        digitalWrite(i, LOW);
//      }
//    }
  // put your main code here, to run repeatedly:
    //1. 8개 row pin off
//  for(int i=10; i<18; i++){
//    digitalWrite(i, LOW);
//  }
//  //-------------------------------
//  //2.col value
//  for(int i=0; i<8; i++){
//    if(0x23 & (0x80>>i)){
//      digitalWrite(2+i, LOW);
//    }
//    else{
//      digitalWrite(2+i, HIGH);
//    }
//  }
//  digitalWrite(10, HIGH);
//  delayMicroseconds(2500);
//  //
//      //1. 8개 row pin off
//  for(int i=10; i<18; i++){
//    digitalWrite(i, LOW);
//  }
//  //-------------------------------
//  //2.col value
//  for(int i=0; i<8; i++){
//    if(0x38 & (0x80>>i)){
//      digitalWrite(2+i, LOW);
//    }
//    else{
//      digitalWrite(2+i, HIGH);
//    }
//  }
//  digitalWrite(11, HIGH);
//  delayMicroseconds(2500);
//    //
//      //1. 8개 row pin off
//  for(int i=10; i<18; i++){
//    digitalWrite(i, LOW);
//  }
//  //-------------------------------
//  //2.col value
//  for(int i=0; i<8; i++){
//    if(0x44 & (0x80>>i)){
//      digitalWrite(2+i, LOW);
//    }
//    else{
//      digitalWrite(2+i, HIGH);
//    }
//  }
//  digitalWrite(12, HIGH);
//  delayMicroseconds(2500);
}
