// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>
#define INST 0
#define DATA 1

void setup() {
  Serial.begin(9600);
  i2c_begin();
  


  //----8bit mode---------------------
  charLCD_set_8(0x30, INST);  //0x30
  charLCD_set_8(0x30, INST);  //0x30
  charLCD_set_8(0x30, INST);  //0x30
  charLCD_set_8(0x28, INST);  //0x28
  //----4bit mode---------------------
  charLCD_set_4(0x02, INST);  //0x28
  charLCD_set_4(0x08, INST);  //0x28
  charLCD_set_4(0x00, INST);  //0x06
  charLCD_set_4(0x06, INST);  //0x06
  charLCD_set_4(0x00, INST);  //0x0C
  charLCD_set_4(0x0C, INST);  //0x0C
  charLCD_set_4(0x08, INST);  //0x80
  charLCD_set_4(0x00, INST);  //0x80
  charLCD_set_4(0x01, INST);  //0x10
  charLCD_set_4(0x00, INST);  //0x10

  delay(5);
}

byte x = 0;

void loop() {
  charLCD_set_4(0x03, DATA);  //0x31
  charLCD_set_4(0x01, DATA);  //0x31

}

void charLCD_set_8(char data, char flag) {
  Serial.println("Reached char_8_f");
  i2c_set(0x00);                //RS LOW
  i2c_set(data | flag);         //DATA
  i2c_set(data | flag | 0x04);  //ENABLE HIGH
  i2c_set(data | flag);         //ENABLE LOW
  i2c_set(data | 0x01);         //RS HIGH

  delayMicroseconds(100);
}

void charLCD_set_4(char data, char flag) {
  Serial.println("Reached char_4_f");
  data <<= 4;

  i2c_set(0x00);                //RS LOW
  i2c_set(data | flag);         //DATA
  i2c_set(data | flag | 0x04);  //ENABLE HIGH
  i2c_set(data | flag);         //ENABLE LOW
  i2c_set(data | 0x01);         //RS HIGH

  delayMicroseconds(100);
}
/*
void i2c_set(char data) {
  Wire.beginTransmission(0x27); // transmit to device #8
  Wire.write(data);        // sends five bytes
  Wire.endTransmission();    // stop transmitting
}
*/
void i2c_begin() {
  Serial.println("Reached begin_f");
  DDRC = 0x30;
  TWBR = 18;
  TWSR = 0x01;
  TWCR = 0x04;
}

void i2c_set(char data) {
  Serial.println("Reached set_f");
  TWCR = 0xA4;
  
  while (!(TWCR & 0x80));
  if (TWSR & 0x08 == 0x08)
    Serial.println("Start OK!");
  else
    Serial.println("Start Error!");
  /*************************************************************/
  //8574 Device Address
  TWDR = 0x27 << 1;  //8574 device id : 0x27
  TWCR = 0x84;

  while (!(TWCR & 0x80));
  if (TWSR & 0x18 == 0x18)
    Serial.println("8574 Device Address send/Ack OK!");
  else if (TWSR & 0x20 == 0x20)
    Serial.println("8574 Device Address send/Not Ack!");
  else
    Serial.println("8574 Device Address state Error!");
  /*************************************************************/
  //8574 Address State
  TWDR = data;
  TWCR = 0x84;

  while (!(TWCR & 0x80));
  if (TWSR & 0x28 == 0x28)
    Serial.println("8574 Address send/Ack OK!");
  else if (TWSR & 0x30 == 0x30)
    Serial.println("8574 Address send/Not Ack!");
  else
    Serial.println("8574 Address state Error!");
  /*************************************************************/
  //8574 Data Address
  TWDR = data;
  TWCR = 0x84;

  while (!(TWCR & 0x80));
  if (TWSR & 0x28 == 0x28)
    Serial.println("8574 Data send/Ack OK!");
  else if (TWSR & 0x30 == 0x30)
    Serial.println("8574 Data send/Not Ack!");
  else
    Serial.println("8574 Data state Error!");
  /*************************************************************/
  //Stop
  TWCR = 0x94;
}
