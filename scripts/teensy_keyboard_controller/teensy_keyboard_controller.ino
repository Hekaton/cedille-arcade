/**
 * Teensy Keyboard Controller script for Cedille Arcade
 * 
 * Keyboard keys are mapped to pins by index; e.g. pins[0] refers to pin 1,
 * whose last known state is stored in lastState[9] and whose associated
 * keyboard key is stored in pinKey[0].
 * 
 * Pins refer to the teensy's physical pins
 * lastKeys refer to the last known state of each pin
 * pinKeys maps pins to keyboard keys
 * 
 * This code assumes the use of pulldown resistors for buttons
 * 
 * @author=Dmitri Kolytchev
 */

const int nInputs = 12;
int pins[nInputs] = {
  0, 1, 2, 3,  // pins for up, dn, lt, rt
  5, 6, 7, 8, 9, 10, // a, b, c, x, y, z
  11, 12 // start, select
};


bool lastState[nInputs];

int pinKey[nInputs] = {
  KEY_UP, KEY_DOWN, KEY_RIGHT, KEY_LEFT,
  KEY_A, KEY_B, KEY_C, KEY_X, KEY_Y, KEY_Z,
  KEY_ENTER, KEY_SPACE
};


void setup() {
  pinMode(13, OUTPUT);
  
  // initialize all pins as inputs
  for (int i = 0; i < nInputs; i++) {
    pinMode(pins[i], INPUT_PULLUP);
  }
  
  // blink to make sure we're working
  digitalWrite(13, HIGH);
  delay(66);
  digitalWrite(13, LOW);
  
  // initialize all pins as inputs
  for (int i = 0; i < nInputs; i++) {
    lastState[i] = digitalRead(pins[i]);
  }
}


void loop() {
  // iterate throught all pins and send their respective keyboard events
  
  bool led = false;
  
  for (int i = 0; i < nInputs; i++) {
    bool val = digitalRead(pins[i]);
    led = led || !val;
    if (val != lastState[i]) {
      if (val == LOW) {
        Keyboard.press(pinKey[i]);
      } else {
        Keyboard.release(pinKey[i]);
      }
    }
    lastState[i] = val;
  }
  
  Keyboard.send_now();
  digitalWrite(13, led);
}
