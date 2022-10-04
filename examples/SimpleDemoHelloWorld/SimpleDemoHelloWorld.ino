
// This example just provide basic function test;
// For more informations, please vist www.heltec.cn or mail to support@heltec.cn

#include "Arduino.h"
#include "heltec.h"



void setup() {
  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Disable*/, true /*Serial Enable*/);
  Heltec.display->flipScreenVertically();
  Heltec.display->setFont(ArialMT_Plain_10);

}

void loop() {
  // clear the display
  Heltec.display->clear();
  Heltec.display->drawString(10, 128, String(millis()));
  Heltec.display->drawString(0, 10, "Hello world");
  Heltec.display->display();
}
