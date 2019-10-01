void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 Start_I2C(18);
}

void loop() {
  // put your main code here, to run repeatedly:
  DataSend(0x50, 0);
  DataSend(0x50, 1);
  DataSend(0x00, 2);
  Stop_I2C();
  delay(1000);
}
unsigned char Read_I2C(int twbr, unsigned char deviceadress, unsigned char memoryadress, unsigned char readdeviceadress){
  unsigned char data;
  Start_I2C(twbr);
  DataSend(deviceadress, 0);
  DataSend(memoryadress, 1);
  ReStart_I2C();
  DataSend(readdeviceadress, 3);
  data = ReciveData();
  Stop_I2C();

  return data;
}
void Write_I2C(int twbr, unsigned char deviceadress, unsigned char memoryadress, unsigned char data ){
  Start_I2C(twbr);
  DataSend(deviceadress, 0);
  DataSend(memoryadress, 1);
  DataSend(data, 2);
  Stop_I2C();
}
void Start_I2C(int twbr){
  DDRC = 0x30; //0011 0000
  TWBR = twbr;
  TWSR = 0x01; //0000 0001
  TWCR = 0xA4; //0010 0100 start condition TWI enable

  while(!(TWCR&0x80));
  if(TWSR & 0x08 == 0x08){
    Serial.println("Start OK");
  }
  else{
    Serial.println("Start Error");
  }
}
void ReStart_I2C(){
  TWCR = 0xA4; //1010 0100 clear start condition TWI enable
  while(!(TWCR&0x80));
  if(TWSR & 0x10 == 0x10){
    Serial.println("reStart OK");
  }
  else{
    Serial.println("reStart Error");
  }
}
unsigned char ReciveData(){
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
  //Serial.println(TWDR,2);
  return eeprom_data;
}
void Stop_I2C(){
  TWCR = 0x94;
}
void DataSend(unsigned char data, int type){//0:device 1:memory address 2:data address3:readDeviceAdress
  TWDR = data;
  TWCR = 0x84;
  switch(type){
    case 0:
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
      break;
    case 1:
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
      break;
  case 2:
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
      break;
    case 3:
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
      break;
  }
}
