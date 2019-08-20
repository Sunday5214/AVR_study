unsigned long previousMicros = 0;
unsigned long currentMicros = 0;
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
int count = 0;
int duty = 10;
void setup() {
  // put your setup code here, to run once:
  DDRB = 0x20;
  
  TCCR2A = 0x03;
  TCCR2B = 0x05;
  TCNT2 = 6;
  OCR2A = duty + 6;
  TIMSK2 = 0x03;
  // DDRA &= ~0x20;//clear
}

void loop() {
  // put your main code here, to run repeatedly:
  currentMillis = millis();
  
  if(currentMillis - previousMillis >= 10)
  {
    previousMillis = currentMillis;
    if(duty == 255)
    {           
      duty = 0;
    }
    duty+=2;
  }
}
SIGNAL(TIMER2_COMPA_vect)
{
  PORTB = 0x00;
}
SIGNAL(TIMER2_OVF_vect)
{
  TCNT2 = 6;
  PORTB = 0x20;

  OCR2A = duty;
}
