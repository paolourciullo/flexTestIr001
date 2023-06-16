int IRSensor = 9;
int LED = 13;

int OnTrig;
int OffTrig;
int Limit = 1000;


void setup() {
  Serial.begin(921600);
  Serial.println("Serial Working");
  pinMode(IRSensor, INPUT);
  pinMode(LED, OUTPUT);

}

void loop() {
  int sensorStatus = digitalRead(IRSensor);
  if (sensorStatus == 1){
    OnTrig++;
    OffTrig = 0;
  } else {
    OffTrig++;
    OnTrig = 0;
  }

  if (OffTrig >= Limit) {
    Serial.println("Stopped Moving");
    digitalWrite(LED, HIGH);
  } else if (OnTrig >= Limit) {
    Serial.println("Stopped Moving");
    digitalWrite(LED, HIGH);
  }
  else {
    Serial.println("Moving");
    digitalWrite(LED, LOW);
  }

}
