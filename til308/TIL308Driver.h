#ifndef __TIL308_DRIVER_H__
#define __TIL308_DRIVER_H__

#include "Arduino.h"

class TIL308Driver {
public:
  TIL308Driver(
    int outputA, int outputB, int outputC, int outputD,
    int outputDP,
    int[] latchPins, size_t numDigits,
    int blankPin);

  void begin();

  void setValue(int64_t val);

  void setValue(uint8_t *digitValues);

  void setNegative(bool val);

private:
  
};

#endif