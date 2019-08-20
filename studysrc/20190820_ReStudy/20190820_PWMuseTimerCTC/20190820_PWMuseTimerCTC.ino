unsigned long previousMicros = 0;
unsigned long currentMicros = 0;
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
int count = 0;
int duty = 10;
void setup() {
  // put your setup code here, to run once:
  DDRB = 0x20;
  
  TCCR2A = 0x02;
  TCCR2B = 0x02;
  TCNT2 = 0;
  OCR2A = 200;
  TIMSK2 = 0x02;
  // DDRA &= ~0x20;//clear
}

void loop() {
  // put your main code here, to run repeatedly:
  currentMillis = millis();
  
  if(currentMillis - previousMillis >= 100)
  {
    previousMillis = currentMillis;
    if(duty == 90)
    {           
      duty = 0;
    }
    duty+=10;
  }
}
SIGNAL(TIMER2_COMPA_vect)
{
      count++;
    if(count == 100)
    {
      PORTB = 0x20;
      count = 0;
    }
    else if(count == duty)
    {
      PORTB = 0x00;
    }
}
