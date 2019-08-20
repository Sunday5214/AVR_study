unsigned long previousMicros = 0;
unsigned long currentMicros = 0;
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
int count = 0;
int duty = 22;
void setup() {
  // put your setup code here, to run once:
  DDRB = 0x20;
  //574 399 575 974 574 974  
  TCCR1A = 0x03;
  TCCR1B = 0x0B;
  TCNT1 = 399;
  OCR1A = 574;
  TIMSK1 = 0x03;
  // DDRA &= ~0x20;//clear
}

void loop() {
  // put your main code here, to run repeatedly:
  currentMillis = millis();
  
  if(currentMillis - previousMillis >= 20)
  {
    previousMillis = currentMillis;
    if(duty == 72)
    {           
      duty = 22;
    }
    duty++;
  }
}
SIGNAL(TIMER1_COMPA_vect)
{
  if(count == 0){
    PORTB &= ~0x00;
  }
  else if(count == 1)
  //count = 0
  //PORTB = 0x00;
}
SIGNAL(TIMER1_OVF_vect)
{
  TCNT2 = 399;
  count++;
  if(count == 8){
    count = 0;
  }
  if(count == 0){
    PORTB = 0x20;
    OCR1A = 22;
  }
  else if(count == 1){
    PORTB = 0x10;
  }
  else if(count == 7){
    OCR1A = duty;
  }
//  if(count == 625){
//    count = 0;
//    PORTB = 0x20;
//  }
//  else if(count == duty){
//    PORTB = 0x00;
//  }
}//0.7 2.3
