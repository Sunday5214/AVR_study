void setup() {
  // put your setup code here, to run once:
  DDRC = 0x30; // 4 SDA /5 SCL
  PORTC = 0x10; //SDA
  PORTC |= 0x20; //SCL
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //start
  PORTC &= ~0x10;
  //standby
  PORTC &= ~0x20;
  
  //Device adress
  for(int i = 0; i<8; i++){
    if(0xA0 & (0x80>>i)){
      PORTC |= 0x10;
    }
    else{
      PORTC &= ~0x10;
    }
    PORTC |= 0x20; // clock high
    PORTC &=  ~0x20; // clock low
  }
  //ACK
  DDRC &= ~(0x10);
  PORTC |= 0x20; // clock high
  PORTC &=  ~0x20; // clock low
  Serial.println(PINC & 0x10);
  //Memroy
  DDRC |= 0x10;
  for(int i = 0; i<8; i++){
    if(0x00 & (0x80>>i)){
      PORTC |= 0x10;
    }
    else{
      PORTC &= ~0x10;
    }
    PORTC |= 0x20; // clock high
    PORTC &=  ~0x20; // clock low
  }

  //ACK
  DDRC &= ~(0x10);
  PORTC |= 0x20; // clock high
  PORTC &=  ~0x20; // clock low
  Serial.println(PINC & 0x10);

//data
  DDRC |= 0x10;
  for(int i = 0; i<8; i++){
    if(0x35 & (0x80>>i)){
      PORTC |= 0x10;
    }
    else{
      PORTC &= ~0x10;
    }
    PORTC |= 0x20; // clock high
    PORTC &=  ~0x20; // clock low
  }

  //ACK
  DDRC &= ~(0x10);
  PORTC |= 0x20; // clock high
  PORTC &=  ~0x20; // clock low
 Serial.println(PINC & 0x10);
  //stop

  PORTC &= ~0x10; //SDA LOW
  PORTC |= 0x20; // SCL HIGH
  PORTC |= 0x10; //SDA HIGH
 // DDRC |= 0x10;
  delay(5000);
}
