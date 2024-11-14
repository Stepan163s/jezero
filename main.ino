#include <GyverPower.h>
#define MOSFET 2  
#define BUT 4
#define PHOTO_PIN A0  // Пин для фоторезистора
#define LIGHT_THRESHOLD_MIN 200  // Минимальное значение освещенности
#define LIGHT_THRESHOLD_MAX 800  // Максимальное значение освещенности

void setup() {
  pinMode(MOSFET, OUTPUT);
  pinMode(BUT, OUTPUT);
  digitalWrite(MOSFET, LOW); 
  digitalWrite(BUT, LOW);
  power.autoCalibrate();  
  power.hardwareDisable(PWR_ADC | PWR_TIMER1);  
  power.bodInSleep(false);  
}

void loop() {
  int lightLevel = analogRead(PHOTO_PIN);
  
  if (lightLevel >= LIGHT_THRESHOLD_MIN && lightLevel <= LIGHT_THRESHOLD_MAX) {
    digitalWrite(MOSFET, HIGH);
    delay(2000);
    digitalWrite(BUT, HIGH);
    delay(5000);
    digitalWrite(BUT, LOW);
    delay(210000);
    digitalWrite(MOSFET, LOW);
  }
  
  power.setSleepMode(POWERDOWN_SLEEP);
  power.sleepDelay(7200000);
}
