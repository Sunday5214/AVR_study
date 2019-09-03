void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  pinMode(1, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("1");
  digitalWrite(1, HIGH);
  delay(1000);
  digitalWrite(1, LOW);//start
  delayMicroseconds(102);//start 00110001 stop
  digitalWrite(1, HIGH);//1
  delayMicroseconds(102);
  digitalWrite(1, LOW);//0
  delayMicroseconds(102);
  digitalWrite(1, LOW);//0
  delayMicroseconds(102);
  digitalWrite(1, LOW);//0
  delayMicroseconds(102);
  digitalWrite(1, HIGH);//1
  delayMicroseconds(102);
  digitalWrite(1, HIGH);//1
  delayMicroseconds(102);
  digitalWrite(1, LOW);//0
  delayMicroseconds(102);
  digitalWrite(1, LOW);//0
  delayMicroseconds(102);
  digitalWrite(1, HIGH);//Finish
  delayMicroseconds(102);
  delay(1000);
}
