unsigned long previousMicros = 0;
unsigned long currentMicros = 0;
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
int count = 0;
int duty = 10;
void setup() {
  // put your setup code here, to run once:
  DDRB = 0x20;
  // DDRA &= ~0x20;//clear
}

void loop() {
  // put your main code here, to run repeatedly:
  currentMicros = micros();
  currentMillis = millis();
  if(currentMicros - previousMicros >= 100)
  {
    previousMicros = currentMicros;
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
