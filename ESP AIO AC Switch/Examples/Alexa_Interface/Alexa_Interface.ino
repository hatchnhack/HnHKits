/*
 * HnH AIO AC Switch interface with amazon alexa using Espalexa library
 * Pre-requisites :
 * - Arduino IDE
 * - - ESP8266 board package : http://arduino.esp8266.com/stable/package_esp8266com_index.json
 * - - WiFiManage : https://github.com/tzapu/WiFiManager
 * - - Espalexa library : https://github.com/Aircoookie/Espalexa.git
 * - Amazon Echo device
 * - - Amazon Alexa App
 */ 

#include <ESP8266WiFi.h>
#include <WiFiManager.h>
#include <Espalexa.h>

//* WiFi connection function 
boolean connectWifi();

//* callback functions
void changeDeviceState(EspalexaDevice* dev);

//* Parameters
boolean wifiConnected = false;
#define MY_DEVICE1 "GLEAM"

//* Relay pin
#define RELAY 5

//* espalexa initialization
Espalexa espalexa;

void setup() {
    //* Set the pinmode and start serial
    pinMode(RELAY, OUTPUT);
    Serial.begin(115200);
    Serial.println("");

    //* Initialize WiFi
    wifiConnected = connectWifi();

    if(wifiConnected){
        //* Device definition 
        espalexa.addDevice(MY_DEVICE1, changeDeviceState);
        espalexa.begin();
    } else {
        while (1) {
            Serial.println("Cannot connect to WiFi. Please check data and reset the ESP.");
            delay(2500);
        }
    }
} 
void loop() {
    espalexa.loop();
    delay(1);
}

/* 
* Device callback function
* Will run when you say the commands
* - Alexa turn off the switch
* - Alexa turn off the HnH switch
* - Alexa turn on the switch
* - Alexa turn on the HnH switch
*/
void changeDeviceState(EspalexaDevice* dev) {
    Serial.print("Device state changed to ");
    //* Check the device state
    if (dev->getValue()) {
        Serial.print("ON");
        digitalWrite(RELAY,HIGH);
    } else  {
        Serial.println("OFF");
        digitalWrite(RELAY,LOW);
    }
}

// connect to wifi – returns true if successful or false if not
boolean connectWifi(){
    /*
    * WiFi connection status
    * Returns 
    * True - connected to WiFi
    * False - unable to connect to WiFi
    */
    boolean state = true;

    //* WiFi mode STA+AP
    WiFi.mode(WIFI_STA);
    
    //* Initialize WiFi manager
    WiFiManager wm;
    
    //* Starting the WiFi Manager
    state = wm.autoConnect("HnHSwitch30", "hnh@1234");
    
    if (state) {
        Serial.println("Connected yaay!! ");
        Serial.print("IP address : ");
        Serial.println(WiFi.localIP());
    } else {
        Serial.println("Connection failed.");
    }
    return state;
}
