#include "thingProperties.h"
#include "RadiationWatch.h"
#include "Arduino.h"
#include "heltec.h"
#include "oled/OLEDDisplayUi.h"


RadiationWatch radiationWatch;
extern Heltec_ESP32 Heltec;
OLEDDisplayUi ui( Heltec.display );
float sen;
float er;

void onRadiation()
{
  sen = radiationWatch.uSvh();
  er = radiationWatch.uSvhError();
  Serial.println("A wild gamma ray appeared");
  Serial.print(sen);
  Serial.print(" uSv/h +/- ");
  Serial.println(er);
}

void onNoise()
{
  Serial.println("Argh, noise, please stop moving");
}

void setup() {
  // Inicialize Heltec
  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Disable*/, true /*Serial Enable*/);
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1000);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  radiationWatch.setup();
  // Register the callbacks.
  radiationWatch.registerRadiationCallback(&onRadiation);
  radiationWatch.registerNoiseCallback(&onNoise);
}

void loop() {
  ArduinoCloud.update();
  radiationWatch.loop();
  Heltec.display->clear();
  Heltec.display->drawString(0, 20, String(sen) + ' uSv/h +/- ' + String(er));
  Heltec.display->display();
}



