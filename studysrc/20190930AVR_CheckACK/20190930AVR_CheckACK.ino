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
  ////////////////////////////////////////////////////
  TWDR = 0x80;
  TWCR = 0x84;
  while(!(TWCR&0x80));
  if(TWSR & 0x28 == 0x28){
    Serial.println("Memory DATA  Adrress send ACK OK");
  }
  else if(TWSR & 0x30 == 0x30){
    Serial.println("Memory DATA  Adrress send ACK Not OK");
  }
  else{
    Serial.println("Memory DATA  Address state Error");
  }
  ///////////////////////////////////////////////////
  TWCR = 0x94;
}

void loop() {
  // put your main code here, to run repeatedly:

}
