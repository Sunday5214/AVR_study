#include <Wire.h>

void setup() {
  Serial.begin(9600);
  Wire.begin(); // join i2c bus (address optional for master)
}

//byte x = 0;
char data = 0;
void loop() {
  data =Serial.read();
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write(data);              // sends one byte
  Wire.endTransmission();    // stop transmitting
  delay(500);
}

//void i2c_
//
//void i2c_set(char data){
//  TWCR = 0xA4;
//  while (!(TWCR & 0x80));
//
//  if(TWSR & 0x08 == 0x08){
//    Serial.println("Start OK !");
//  }
//  else{
//    Serial.println("Start Error !");
//  }
//
//  TWDR = 0x27 << 1;
//  TWCR = 0x84;
//  while(!(TWCR & 0x80));
//  if(TWSR & 0x18 == 0x18){
//    Serial.println("8574 Device Address send/ACK OK !");
//  }
//  else if(TWSR & 0x20 == 0x20){
//    Serial.println("8574 Device Address send/Not ACK !");
//  }
//  else{
//    Serial.println("8574 Device Address state Error !");
//  }
//
//  TWDR = data;
//  TWCR = 0x84;
//  while(!(TWCR & 0x80));
//  if(TWSR & 0x28 == 0x28){
//    Serial.println("8574 data send/ACK OK !");
//  }
//  else if(TWSR & 0x30 == 0x30){
//    Serial.println("8574 data send/Not ACK !");
//  }
//  else{
//    Serial.println("8574 data state Error !");
//  }
//}
