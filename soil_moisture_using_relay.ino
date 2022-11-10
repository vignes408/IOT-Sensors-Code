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
  Serial.print(" soil moisture is ");
  Serial.println(sens);
   delay(1000);
   if(sens<500)
   {
    digitalWrite(led,HIGH);
   
   }
else if(sens>1000)
{
      digitalWrite(led,LOW);

}
else
{
  
}
}
