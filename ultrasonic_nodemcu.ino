int trig = 0;
int echopin = 12;
float duration,Distanceincm,Distanceininch;
int led = 16;
void setup()
{
  Serial.begin(115200);
  pinMode(trig,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(led,OUTPUT);
}
void loop()
{
  digitalWrite(trig,HIGH);
  delay(15);
  digitalWrite(trig,LOW);
  duration = pulseIn(echopin,HIGH);
  Distanceincm = duration / 58;
  Distanceininch =  duration / 148;
  Serial.print("Distance in cm = ");
  Serial.print(Distanceincm);
  Serial.print(" Distance in inches = ");
  Serial.println(Distanceininch);
  delay(500);
  if(Distanceincm <=10)
  {
   digitalWrite(led,HIGH);
  }
  else
  {
    digitalWrite(led,LOW);
  }
  
}
