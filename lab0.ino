int incomingByte = 0; // for incoming serial data

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);// opens serial port, sets data rate to 9600 bps
}

void loop() {
  // reply only when you receive data: 
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    if(incomingByte==49){
    digitalWrite(LED_BUILTIN, HIGH);
    }
    else if(incomingByte==48){
      digitalWrite(LED_BUILTIN, LOW);
      }
      else{
        Serial.write(incomingByte);
        
        }
  }
  
}
