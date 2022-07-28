// Code generated by Arduino IoT Cloud, DO NOT EDIT.

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char DEVICE_LOGIN_NAME[]  = "73533fa5-1e05-46c5-8fdf-ff463e049daa";

const char SSID[]               = "HOUSE";    // Network SSID (name)
const char PASS[]               = "wifiwifiwifi1992";    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]  = "KeyW0IQNQL0TGSBIAHUNRQ4";    // Secret device password



void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);