int led = 13;
int sensor =2;
void setup() {
 pinMode(led,OUTPUT);
  pinMode(sensor,INPUT);
  Serial.begin(9600);

}

void loop() {
    int sens = digitalRead(sensor);
Serial.print(" Sensor value is ");
Serial.print(sens);

if(sens==0)
{
  digitalWrite(led,HIGH);
}
else
{
  digitalWrite(led,LOW);
}
}
