void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);
  pinMode(13, OUTPUT); //CLK pin output
  pinMode(11, OUTPUT); //MOSI pin output
  pinMode(10, OUTPUT); //SS pin output
  SPCR = 0x51;//SPI Enable, MasterMode, Clokc:1MHz
}

void loop() {
  // put your main code here, to run repeatedly:
  SPDR = 0x01;
  delay(1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
 // while(SPSR & 0x80);
  delay(1000);
  SPDR = 0x00;  
  delay(1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  delay(1000);
}
