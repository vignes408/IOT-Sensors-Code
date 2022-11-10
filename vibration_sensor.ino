int led = 13;
int sensor = A0;
void setup() 
{
 pinMode(led,OUTPUT);
 pinMode(sensor,INPUT);
 Serial.begin(9600);
}

void loop() {
  int sens = analogRead(sensor);
  Serial.print(" vibration is ");
  Serial.println(sens);
   delay(70);
   if(sens>1000)
   {
    digitalWrite(led,HIGH);
    delay(2000);
   
   }
else if(sens==0)
{
      digitalWrite(led,LOW);

}
else
{
  
}
}
