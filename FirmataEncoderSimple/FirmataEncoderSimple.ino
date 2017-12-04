#include <Boards.h>
#include <Firmata.h>

#include <Encoder.h>

// Für beste Performance sollten beide Pins `interrupt` fähig sein.
// Siehe auch: http://playground.arduino.cc/Code/Interrupts
// Und Hinweise auf https://www.pjrc.com/teensy/td_libs_Encoder.html
Encoder dreher(2,3);

void setup() {
  Firmata.begin();
}

long oldPosition = -999;

void loop() {
  long position = dreher.read();
  if (position != oldPosition) {
    oldPosition = position;
    Firmata.sendAnalog(0, position);
  }
}

