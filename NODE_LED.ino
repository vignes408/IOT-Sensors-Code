void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
}


void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(2000);
  Serial.println("HIGH");
  digitalWrite(LED_BUILTIN, LOW);    
  
 delay(2000);                       
Serial.println("LOW");
}
