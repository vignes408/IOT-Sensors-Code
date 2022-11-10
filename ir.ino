int led = 13;
int sensor =2;
int count = 0;
void setup() {
  pinMode(led,OUTPUT);
  pinMode(sensor,INPUT);
  Serial.begin(9600);

}

void loop() {
  int sens = digitalRead(sensor);
  delay(20);
if(sens==0)
{
  digitalWrite(led,HIGH);
  count = count+1;
  Serial.print(" person number");
  Serial.println(count);
}
else
{
   digitalWrite(led,LOW);
}
}
