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

const int nInputs = 4;
int pins[nInputs] = {1, 2, 3, 4}; // pins for up, dn, lt, rt
int lastState[nInputs] = {LOW, LOW, LOW, LOW};
int pinKey[nInputs] = {KEY_UP, KEY_DOWN, KEY_RIGHT, KEY_LEFT};

void setup() {
  // initialize all pins as inputs
  for (int i = 0; i < nInputs; i++) {
    pinMode(pins[i], INPUT);
  }
}

void loop() {
  // iterate throught all pins and send their respective keyboard events
  for (int i = 0; i < nInputs; i++) {
    int val = digitalRead(pins[i]);

    if (val != lastState[i]) {
      if (val == HIGH) {
        Keyboard.press(pinKey[i]);
      } else {
        Keyboard.release(pinKey[i]);
      }
    }
    lastState[i] = val;
  }

  Keyboard.send_now();
}
