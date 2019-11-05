#define SCL 21
#define SDA 20
#define DEV_ID_PCF8574 0x27<<1
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(SCL, OUTPUT);
  pinMode(SDA, OUTPUT);

 
}
int count = 0;
int duty = 0;
unsigned long pre_micros = 0;
unsigned long current_micros = 0;

unsigned long pre_millis = 0;
unsigned long current_millis = 0;
void loop() {
  // put your main code here, to run repeatedly:
  current_micros = micros();
  current_millis = millis();
  if(current_micros - pre_micros >= 100){
    pre_micros = current_micros;

    count++;
    if(count==100){
      InsertData_I2C(0x08);

      count = 0;
    }
    else if(count==duty){
      InsertData_I2C(0x00);
    }
  }
  if(current_millis - pre_millis >= 10){
    pre_millis = current_millis;
    duty++;
    if(duty==100){
      duty=1;
    }
  }
}

void I2C_Start(){
  digitalWrite(SCL, HIGH);
  digitalWrite(SDA, HIGH);
  
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
