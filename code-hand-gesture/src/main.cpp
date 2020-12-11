#include <Arduino.h>

#define led_onboard 2

void setup() {
  // put your setup code here, to run once:
  pinMode(led_onboard, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int estado_led = !digitalRead(led_onboard);
  digitalWrite(led_onboard, estado_led);
  printf("Estado do led atual: %d\n", estado_led);
  delay(1000);
}