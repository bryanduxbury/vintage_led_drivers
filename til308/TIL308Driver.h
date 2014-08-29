#ifndef __TIL308_DRIVER_H__
#define __TIL308_DRIVER_H__

#include "Arduino.h"

typedef uint8_t glyph_t;

#define GLYPH_A     10
#define GLYPH_MINUS 11
#define GLYPH_C     12
#define GLYPH_BLANK 13
#define GLYPH_E     14
#define GLYPH_F     15


class TIL308Driver {
public:
  TIL308Driver(
    int outputA, int outputB, int outputC, int outputD,
    int outputDP,
    int *latchPins, size_t numDigits,
    int blankPin);

  void begin();

  void setOutput(glyph_t *glyphs, size_t nGlyphs);

private:
  uint8_t oa, ob, oc, od, odp;
  int *latchPins;
  uint8_t blankPin;
  size_t numDigits;

  void setOutputPins(glyph_t g);
  void pulseLatch(size_t digit);
};

#endif