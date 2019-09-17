void setup() {
  // put your setup code here, to run once:
  DDRB  = 0x03; // 0번 bit는 Servo 0 1번 bit는 Servo 1
  PORTB = 0x00;
  
  TCCR1B = 0x0A;
  TCCR1A = 0x03;
  TCCR1C = 0x00;
  TCNT1 = 960;//8분주 2Mhz 이고 주기는 0.5us이므로 0.5us * x = 32us
  //64여야 32개의 카운트를 쌓아 인터럽트 발생가능
  TIMSK1 = 0x01;
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
int count = 0;
SIGNAL(TIMER1_OVF_vect){
  TCNT1 = 960;
  count++;
  if(count == 625){
    count = 0;
    PORTB | 0x01;
  }
  else if(count == 22){//22왼쪽 72오른쪽
    PORTB &= ~0x01;
  }
}
