/*
 * Connection
 * VCC   --- Vin
 * GND   --- GND
 * LOAD  --- LOAD (Any AC Load, upto 5A)
 * INPUT --- AC In
 * TRIG  --- D5
 * ZCD   --- D2
 */
#define TRIG 5
#define ZCD 2

/*
 * Dimming Levels 128
 */
uint8_t level = 128;
bool up_mode = false;
bool triac_cycle = false;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ZCD, INPUT);
  /*
   * Zero Crossing Interrupt
   * 50Hz AC signal -> 20ms Time Period
   * Each cycle -> 10ms
   * The ZCD signal is _|~|_|~|_.....
   * Each rising and falling edge comes after 10ms
   */
  attachInterrupt(digitalPinToInterrupt(ZCD), zero_detect, CHANGE);
}

void loop() {
  // if interrupt then trigger the triac
  if(triac_cycle) {
    /*
     * Triac firing angle -> step = (time available to turn on)/(dim levels)
     * Triac turn on delay = 10us
     * Step time = (10ms - 10us)/(128) = 78 (for 50Hz)
     * firing angle -> level x step time
     */
    int dim = (78*level);
    // Wait till turning on the triac
    delayMicroseconds(dim);
    digitalWrite(TRIG, HIGH);
    // triac turned on, wait for triac turn on delay
    delay(10);
    // turn the trig off, triac will turn off when crossing the next zero level
    digitalWrite(TRIG, LOW);
    triac_cycle = false;
    // Change dimming level
    if(up_mode){
      level += 1;
    } else {
      level -= 1;
    }
  }
  // Change dimming up or down
  if(level == 4){
    up_mode = true;
  }
  if(level == 128){
    up_mode = false;
  }
}

// interrupt on every edge
void zero_detect() {
  triac_cycle = true;
}
