#include "TIL308Driver.h"

TIL308Driver::TIL308Driver(
  int outputA, int outputB, int outputC, int outputD,
  int outputDP,
  int *latchPins, size_t numDigits,
  int blankPin) 
{
  oa = outputA;
  ob = outputB;
  oc = outputC;
  od = outputD;
  odp = outputDP;

  this->numDigits = numDigits;
  this->latchPins = latchPins;

  this->blankPin = blankPin;
}

void initPin(uint8_t pinNum) {
  digitalWrite(pinNum, LOW);
  pinMode(pinNum, OUTPUT);
}

void TIL308Driver::begin() {
  initPin(oa);
  initPin(ob);
  initPin(oc);
  initPin(od);
  initPin(odp);
  initPin(blankPin);

  // latch is active low, so we want to set it to high state to start with
  for (int i = 0; i < numDigits; i++) {
    pinMode(latchPins[i], OUTPUT);
    digitalWrite(latchPins[i], HIGH);
  }
}

void TIL308Driver::pulseLatch(size_t digit) {
  // pulse low, then return to high
  digitalWrite(latchPins[digit], LOW);
  digitalWrite(latchPins[digit], HIGH); 
}

void TIL308Driver::setOutputPins(glyph_t g) {
  digitalWrite(oa, (g & 1) ? HIGH : LOW);
  digitalWrite(ob, (g & 2) ? HIGH : LOW);
  digitalWrite(oc, (g & 4) ? HIGH : LOW);
  digitalWrite(od, (g & 8) ? HIGH : LOW);
}

void TIL308Driver::setOutput(glyph_t *glyphs, size_t nGlyphs) {
  for (size_t i = 0; i < nGlyphs; i++) {
    setOutputPins(glyphs[i]);
    pulseLatch(i);
  }
}