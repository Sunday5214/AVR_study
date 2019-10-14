void setup() {
  // put your setup code here, to run once:
  pinMode(A5, OUTPUT);
}
unsigned long currentMicros = 0;
unsigned long previousMicros = 0;
int count = 0;
void loop() {
  // put your main code here, to run repeatedly:
  currentMicros = micros();
  if(currentMicros - previousMicros > 100){
    count++;
    if(count == 100){
      digitalWrite(A5, HIGH);
      count = 0;
    }
    else if(count == 10){
      digitalWrite(A5, LOW);
    }
  }
}
