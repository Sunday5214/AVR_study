void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  DDRB  = 0x03; // 0번 bit는 Servo 0 1번 bit는 Servo 1
  PORTB = 0x00;
  
  TCCR2B = 0x0A;
  TCCR2A = 0x03;
  //TCCR2C = 0x00;
  
  TCCR1B = 0x0A;
  TCCR1A = 0x03;
  TCCR1C = 0x00;

  TCNT1 = 960; //8분주 2Mhz 이고 주기는 0.5us이므로 0.5us * x = 32us
  //64여야 32개의 카운트를 쌓아 인터럽트 발생가능
  TCNT2 = 192;
  TIMSK1 = 0x01;
  TIMSK2 = 0x01;
}
bool flag_R = false;
bool flag_L = false;
bool flag_U = false;
bool flag_D = false;
int adc_value_X = 0;
int adc_value_Y = 0;
int servo_var = 22;
int servo_var2 = 22;
int count = 0;
int count2 = 0;

void loop() {
  // put your main code here, to run repeatedly:
  adc_value_X = MyAnalogRead(A0);
  adc_value_Y = MyAnalogRead(A1);

   if(adc_value_X < 1023 && adc_value_X > 700){
      if(flag_L){
       //Serial.println("L");
       flag_L  = false;
       servo_var++;;
       }
    }
    else if(adc_value_X > 0 && adc_value_X < 400){
    if(flag_R){
      //Serial.println("R");
      flag_R  = false;
      servo_var ++;
    }
   }

  if(adc_value_Y < 1023 && adc_value_Y > 700){
    if(flag_U){
      //Serial.println("U");
      flag_U = false;
      servo_var2++;
    }
  }
  else if(adc_value_Y > 0 && adc_value_Y < 400){
    if(flag_D){
      //Serial.println("D");
      flag_D = false;
      servo_var2++;
    }
  }
  
  if(adc_value_X < 600 && adc_value_X > 400 && adc_value_Y < 600 && adc_value_Y > 400){
    flag_U = true;
    flag_D = true;
    flag_R = true;
    flag_L = true;
  }
//  //  Serial.println(adc_value_Y);
  delay(10);
}
int MyAnalogRead(int bitPin){
  int value = 0;
  ADMUX = 0x40 | (bitPin - A0);
  ADCSRA = 0x87;
  ADCSRA |= 0x40;
  value = ADC;

  while(ADCSRA & 0x40);

  return value;
}
SIGNAL(TIMER1_OVF_vect){
  TCNT1 = 960;
  count++;
  if(count == 625){
    count = 0;
    PORTB |= 0x01;
  }
  else if(count == servo_var){//22왼쪽 72오른쪽
    PORTB &= ~0x01;
  }
}
SIGNAL(TIMER2_OVF_vect){
  TCNT2 = 192;
  count2++;
  if(count2 == 625){
    count2 = 0;
    PORTB |= 0x02;
  }
  else if(count2 == servo_var2){//22왼쪽 72오른쪽
    PORTB &= ~0x02;
  }
}
