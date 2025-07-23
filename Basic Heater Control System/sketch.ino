#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22

#define HEATER_LED 3
#define STABLE_LED 4
#define BUZZER 5

DHT dht(DHTPIN, DHTTYPE);

float targetTemp = 30.0;
float overheatTemp = 40.0;
float lowerThreshold = 25.0;

enum State {IDLE, HEATING, STABILIZING, TARGET_REACHED, OVERHEAT};
State currentState = IDLE;

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(HEATER_LED, OUTPUT);
  pinMode(STABLE_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  float temp = dht.readTemperature();

  if (isnan(temp)) {
    Serial.println("Failed to read from sensor!");
    delay(2000);
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("°C | State: ");

  switch (currentState) {
    case IDLE:
      if (temp < lowerThreshold) {
        currentState = HEATING;
      }
      digitalWrite(HEATER_LED, LOW);
      digitalWrite(STABLE_LED, LOW);
      digitalWrite(BUZZER, LOW);
      Serial.println("IDLE");
      break;

    case HEATING:
      if (temp >= lowerThreshold && temp < targetTemp) {
        currentState = STABILIZING;
      }
      digitalWrite(HEATER_LED, HIGH);
      digitalWrite(STABLE_LED, LOW);
      digitalWrite(BUZZER, LOW);
      Serial.println("HEATING");
      break;

    case STABILIZING:
      if (temp >= targetTemp && temp < overheatTemp) {
        currentState = TARGET_REACHED;
      }
      digitalWrite(HEATER_LED, HIGH);
      Serial.println("STABILIZING");
      break;

    case TARGET_REACHED:
      if (temp >= overheatTemp) {
        currentState = OVERHEAT;
      } else if (temp < targetTemp) {
        currentState = HEATING;
      }
      digitalWrite(HEATER_LED, LOW);
      digitalWrite(STABLE_LED, HIGH);
      digitalWrite(BUZZER, LOW);
      Serial.println("TARGET_REACHED");
      break;

    case OVERHEAT:
      digitalWrite(HEATER_LED, LOW);
      digitalWrite(STABLE_LED, LOW);
      digitalWrite(BUZZER, HIGH);
      Serial.println("OVERHEAT!");
      break;
  }

  delay(1500); // delay between reads
}