#define SCL 21
#define SDA 20
#define DEV_ID_PCF8574 0x27<<1
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(SCL, OUTPUT);
  pinMode(SDA, OUTPUT);

  digitalWrite(SCL, HIGH);
  digitalWrite(SDA, HIGH);

  Graphic_LCD_INST(0x30);
  Graphic_LCD_INST(0x30);
  Graphic_LCD_INST(0x30);
  Graphic_LCD_INST(0x28);

  Graphic_LCD_INST(0x20);
  Graphic_LCD_INST(0x80);
  Graphic_LCD_INST(0x00);
  Graphic_LCD_INST(0x60);
  Graphic_LCD_INST(0x00);
  Graphic_LCD_INST(0xC0);
  Graphic_LCD_INST(0x80);
  Graphic_LCD_INST(0x00);
  Graphic_LCD_INST(0x00);
  Graphic_LCD_INST(0x10);
}
int count = 0;
int duty = 0;
unsigned long pre_micros = 0;
unsigned long current_micros = 0;

unsigned long pre_millis = 0;
unsigned long current_millis = 0;
void loop() {
  // put your main code here, to run repeatedly:
  Graphic_LCD_DATA(0x30);
  Graphic_LCD_DATA(0x10);
  delay(1000);
}

void Graphic_LCD_INST(char instdata){
  char data=0x00;

  InsertData_I2C(data);
  
  data |= instdata;
  InsertData_I2C(data);

  data |= 0x04;
  InsertData_I2C(data);
  
  data &= ~0x04;
  InsertData_I2C(data);

  data |= 0x01;
  InsertData_I2C(data);
}

void Graphic_LCD_DATA(char data){
  char Lcddata=0x01;

  Lcddata |= data;
  InsertData_I2C(Lcddata);

  Lcddata |= 0x04;
  InsertData_I2C(Lcddata);

  Lcddata &= ~0x04;
  InsertData_I2C(Lcddata);
}

void I2C_Start(){
  digitalWrite(SDA, LOW);
  digitalWrite(SCL, LOW);
}

void I2C_Stop(){
  digitalWrite(SDA, LOW);
  digitalWrite(SCL, HIGH);
  digitalWrite(SDA, HIGH);
}

void I2C_ACK(){
  pinMode(SDA, INPUT);
  digitalWrite(SCL, HIGH);
  digitalWrite(SCL, LOW);
  pinMode(SDA, OUTPUT);
}
void I2C_Data(char data){
  for(int i = 0; i<8; i++){
    if(data & (0x80>>i)){
      digitalWrite(SDA, HIGH);
    }
    else{
      digitalWrite(SDA, LOW);
    }
    digitalWrite(SCL, HIGH);
    digitalWrite(SCL, LOW);
  }
}
void I2C_Device(char deviceid){
  for(int i = 0; i<8; i++){
    if(deviceid & (0x80>>i)){
      digitalWrite(SDA, HIGH);
    }
    else{
      digitalWrite(SDA, LOW);
    }
    digitalWrite(SCL, HIGH);
    digitalWrite(SCL, LOW);
  }
}

void InsertData_I2C(char data){
  //start
  I2C_Start();

  //device ID
  I2C_Device(DEV_ID_PCF8574);

  //ACK
  I2C_ACK();

  //data
  I2C_Data(data);

  //ACK
  I2C_ACK();

  //stop
  I2C_Stop();
}
