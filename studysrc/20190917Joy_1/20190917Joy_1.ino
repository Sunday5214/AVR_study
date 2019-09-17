void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
bool flag_R = false;
bool flag_L = false;
void loop() {
  // put your main code here, to run repeatedly:
  int analog_data;
  
  analog_data = analogRead(A0);
  if(analog_data < 1023 && analog_data > 700){
    if(flag_L){
     Serial.println("L");
     flag_L  = false;
    }
  }
  else if(analog_data > 0 && analog_data < 400){
     if(flag_R){
      Serial.println("R");
      flag_R  = false;
    }
  }
  else if(analog_data < 600 && analog_data > 400){
    flag_R = true;
    flag_L = true;
  }
  delay(10);
}
