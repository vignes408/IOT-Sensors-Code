int led1 = 10;
int buzzer = 13;
void setup() {
  pinMode(led1,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(4,INPUT);

}

void loop() {
  if(digitalRead(4)==1)
  { 
    digitalWrite(led1,LOW);
  }
  else
  {
   digitalWrite(led1,HIGH);
   tone(buzzer,900,500);
  }
}
  
