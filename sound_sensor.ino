int R0 = 176;
int R2 = 1000;
float RS;
float PPM_acetone;
const int sampleWindow = 50;
unsigned int sample;
#define SENSOR_PIN A0
void setup() {
  Serial.begin(9600);
  pinMode(SENSOR_PIN, INPUT);
}
void loop() {
  unsigned long starMillis = millis();
  float peakToPeak = 0;
  unsigned int signalMax = 0;
  unsigned int signalMin = 1024;
  while (millis() - starMillis < sampleWindow)
  {
    sample = analogRead(SENSOR_PIN);
    if (sample < 1024)
    {
      if (sample > signalMax)
      {
        signalMax = sample;

      }
      else if (sample < signalMin)
      {
        signalMin = sample;
      }
    }
  }
  peakToPeak = signalMax - signalMin;
  int db = map(peakToPeak, 20, 900, 49.5, 90);
  Serial.print(" SOUND:");
  Serial.print(db);
  Serial.println("dB");
  delay(2000);

}
