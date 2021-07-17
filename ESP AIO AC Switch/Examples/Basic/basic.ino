/*
 * basic code for hardware check 
*/

//* Relay pin
#define RELAY 5

//* Relay state
boolean state = false;

void setup() {
    pinMode(RELAY, OUTPUT);
    Serial.begin(115200);
    Serial.print("");
    delay(1);
}

void loop() {
    digitalWrite(RELAY, state);
    delay(1500);
    state = !state;
}