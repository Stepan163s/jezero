#include <GyverPower.h>
#define MOSFET 2  
#define BUT 4

void setup() {
  pinMode(MOSFET, OUTPUT);
  pinMode(BUT, OUTPUT);
  digitalWrite(MOSFET, LOW); 
  digitalWrite(BUT, LOW);
  power.autoCalibrate();  
  power.hardwareDisable(PWR_ADC | PWR_TIMER1);
  power.setSleepMode(STANDBY_SLEEP);  
  power.bodInSleep(false);  
}

void loop() {
  digitalWrite(MOSFET, HIGH);
  delay(2000);
  digitalWrite(BUT, HIGH);
  delay(5000);
  digitalWrite(BUT, LOW);
  delay(210000);
  digitalWrite(MOSFET, LOW);
  deepSleepForHours(6);
}
void deepSleepForHours(uint8_t hours) {
  power.setSleepMode(POWERDOWN_SLEEP);  
  uint32_t sleepTime = hours * 3600UL * 1000UL;  
  while (sleepTime >= 8192) {
    power.sleep(SLEEP_8192MS); 
    sleepTime -= 8192;
  }
  power.sleepDelay(sleepTime);
}
