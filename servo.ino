#include<Servo.h>
Servo Myservo;
int pos;
int ir=2;
void setup()
{
pinMode(ir,INPUT);
Myservo.attach(3);
}

void loop()
{
  int statuss=digitalRead(ir);
  Serial.print(statuss);
  if(statuss==0)
  {
    
  for(pos=0;pos<=180;pos++){
  Myservo.write(pos);
  delay(10);
  }}
  else if(statuss==1){
  for(pos=180;pos>=0;pos--){
  Myservo.write(pos);
  //delay(15);
}}
  //delay(10);
  
}
