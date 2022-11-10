
int PIRpin = 5;
int led = 4;


int val;

void setup() {
 Serial.begin(9600);
 pinMode(PIRpin,INPUT);
 pinMode(led,OUTPUT);

}

void loop() {
  val = digitalRead(PIRpin);
  Serial.print("PIR value");
  if(val==1)
  {
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }
  Serial.println(val);
  delay(500);
}
