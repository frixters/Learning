/* 
  RF Blink - Transmit sketch 
     Arduino IDE version 1.0.5
     Website: http://arduinobasics.blogspot.com
     Transmitter: FS1000A/XY-FST
     Transmitter: Tx-118s-4
     Description: A simple sketch used to test RF transmission with tx-118s-4 transmitter module         
 ------------------------------------------------------------- */

 #define rfTransmitPin 4  //RF Transmitter pin = digital pin 4
 #define rfTransmitPin1 5
 #define rfTransmitPin2 6
 #define rfTransmitPin3 7
 #define ledPin 13        //Onboard LED = digital pin 13

 void setup(){
   Serial.begin(9600);
   pinMode(rfTransmitPin, OUTPUT);    
   pinMode(rfTransmitPin1, OUTPUT);  
   pinMode(rfTransmitPin2, OUTPUT);  
   pinMode(rfTransmitPin3, OUTPUT);   
   pinMode(ledPin, OUTPUT);    
 }

 void loop(){

  char reply[50];
  int i = 0;
  if (Serial.available()){
  while (Serial.available()) {
    reply[i] = Serial.read();
    i += 1;
  }
   if(strlen(reply) > 0){
   
  int state=reply[0];
     if (state == '0') {
  digitalWrite(ledPin, LOW); // Turn LED OFF
  Serial.println("LED: On"); // Send back, to the phone, the String "LED: ON"
  state = 0;
  digitalWrite(rfTransmitPin, LOW); 
 }
 else if (state == '1') {
  digitalWrite(ledPin, HIGH);
  Serial.println("LED: Off");
  state = 0;
  digitalWrite(rfTransmitPin, HIGH); 
 }
 else if (state == '2') {
  digitalWrite(ledPin, HIGH);
  Serial.println("LED: On");
  state = 0;
  digitalWrite(rfTransmitPin1, LOW); 
 }
 else if (state == '3') {
  digitalWrite(ledPin, HIGH);
  Serial.println("LED: Off");
  state = 0;
  digitalWrite(rfTransmitPin1, HIGH); 
 }
  else if (state == '4') {
   
  digitalWrite(ledPin, HIGH);
  Serial.println("LED: On");
  state = 0;
  digitalWrite(rfTransmitPin2, LOW); 
 }
 else if (state == '5') {
  digitalWrite(ledPin, HIGH);
  Serial.println("LED: Off");
  state = 0;
  digitalWrite(rfTransmitPin2, HIGH); 
 }
  else if (state == '6') {
  digitalWrite(ledPin, HIGH);
  Serial.println("LED: ON");
  state = 0;
  digitalWrite(rfTransmitPin3,LOW); 
 }
 else if (state == '7') {
  digitalWrite(ledPin, HIGH);
  Serial.println("LED: Off");
  state = 0;
  digitalWrite(rfTransmitPin3, HIGH); 
 }
 
  }

 }
 }
