void setup() {
  // put your setup code here, to run once:
  DDRD &= 0x01; //uart RX
  DDRD |= 0x02; //uzrt TX

  UBRR0 = 103; //9600 baudrate;
  UCSR0A = 0x00; //U2X = 0;
  UCSR0B = 0x98; //TXRX Enable&intrrupt enable
  UCSR0C = 0x06; // Async, No Parity, 1 stop, 8bit

 // UDR0 = 0x31;
}
unsigned char data[10]={0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39};
char aa = 0;
void loop() {
  
//  if(UCSR0A & 0x80){ //Serial.available();
//
//  }
//  delay(10);
  // put your main code here, to run repeatedly:
//  for(int i = 0; i<10; i++){
//    while(!(UCSR0A & 0x20));//UCSR0A의 UDRE UART DATA REGISTER EMPTY 비트는 UDR이 비면 1로변한다.
//    UDR0 = data[i];
//  }
  //delay(1000);
}
ISR(USART_RX_vect){
    aa = UDR0;
    
    while(!(UCSR0A & 0x20));
    UDR0 = aa;
}
