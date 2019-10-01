void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
  //////////////////////////////start
  DDRC = 0x30; //0011 0000
  TWBR = 18;
  TWSR = 0x01; //0000 0001
  TWCR = 0xA4; //0010 0100 start condition TWI enable

  while(!(TWCR&0x80));
  if(TWSR & 0x08 == 0x08){
    Serial.println("Start OK");
  }
  else{
    Serial.println("Start Error");
  }

  /////////////////////////////////////////////
//deviceaddress
  TWDR = 0xA0;
  TWCR = 0x84;
  while(!(TWCR&0x80));
  if(TWSR & 0x18 == 0x18){
    Serial.println("Device Adrress send ACK OK");
  }
  else if(TWSR & 0x20 == 0x20){
    Serial.println("Device Adrress send ACK Not OK");
  }
  else{
    Serial.println("Device Address state Error");
  }
    ///////////////////////////////////////////////////
  //memory address
  TWDR = 0x50;
  TWCR = 0x84;
  while(!(TWCR&0x80));
  if(TWSR & 0x28 == 0x28){
    Serial.println("Memory Adrress send ACK OK");
  }
  else if(TWSR & 0x30 == 0x30){
    Serial.println("Memory Adrress send ACK Not OK");
  }
  else{
    Serial.println("Memory Address state Error");
  }
    //////////////////////////////restart
  TWCR = 0xA4; //1010 0100 clear start condition TWI enable

  while(!(TWCR&0x80));
  if(TWSR & 0x10 == 0x10){
    Serial.println("reStart OK");
  }
  else{
    Serial.println("reStart Error");
  }
    /////////////////////////////////////////////
//deviceaddress
  TWDR = 0xA1;//readmode
  TWCR = 0x84;
  while(!(TWCR&0x80));
  if(TWSR & 0x40 == 0x40){
    Serial.println("readDevice Adrress send ACK OK");
  }
  else if(TWSR & 0x48 == 0x48){
    Serial.println("readDevice Adrress send ACK Not OK");
  }
  else{
    Serial.println("readDevice Address state Error");
  }

  //TWCR = 0x84;
  TWCR =0xC4;
  while(!(TWCR & 0x80))
    if(TWSR & 0x50 == 0x50){
    Serial.println("read data/ack 0(ACK) send ACK OK");
  }
  else if(TWSR & 0x58 == 0x58){
    Serial.println("read data/ack 1(notACK) send ACK OK");
  }
  else{
    Serial.println("readDevice Address state Error");
  }
  char eeprom_data = TWDR;
  Serial.println(TWDR,2);
  TWCR = 0x94;
}

void loop() {
  // put your main code here, to run repeatedly:

}
