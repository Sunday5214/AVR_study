unsigned long previousMicros = 0;
unsigned long currentMicros = 0;
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
int count = 0;
int duty = 10;
void setup() {
  // put your setup code here, to run once:
  DDRB = 0x20;
  
  TCCR1A = 0x03;
  TCCR2B = 0x0B;
  TCNT1 = 524;
  OCR1A = 574;
  TIMSK1 = 0x03;
  // DDRA &= ~0x20;//clear
}

void loop() {
  // put your main code here, to run repeatedly:
  currentMillis = millis();
  
  if(currentMillis - previousMillis >= 10)
  {
    previousMillis = currentMillis;
    if(duty == 1023)
    {           
      duty = 0;
    }
    duty+=5;
  }
}
SIGNAL(TIMER1_COMPA_vect)
{
  PORTB = 0x00;
}
SIGNAL(TIMER1_OVF_vect)
{
  TCNT1 = 524;
  PORTB = 0x20;

  OCR1A = duty;
}
