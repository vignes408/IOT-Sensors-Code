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
  Serial.print(" rain value  is ");
  Serial.println(sens);
   delay(70);
   if(sens>1000)
   {
    digitalWrite(led,LOW);
    delay(2000);
   
   }
else if(sens<1000)
{
      digitalWrite(led,HIGH);

}
else
{
  
}
}
