
int led = 13;
int sensor =2;
int count = 0;
int count1 = 0;
int count2=10;
void setup() {
  pinMode(led,OUTPUT);
  pinMode(sensor,INPUT);
  Serial.begin(9600);
}

void loop() {
    int sens = digitalRead(sensor);

delay(100);
if(sens==0)
{
  count1 = 1;
}
if(sens==1&&count1==1)
{
  Serial.println(" Total no seats = 10");
  digitalWrite(led,HIGH);
  count ++;
  count1 = 0;
   count2 --;
  Serial.print(" person number");
  Serial.println(count);
  
  Serial.print(" balance");
  Serial.println(count2);

 if(count==10){
    Serial.println(" Total no seats = 10");
 Serial.println(" occupied ");
 
 
 
}
}
else
{
  digitalWrite(led,LOW);
}

}
