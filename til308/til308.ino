#define LS 7
#define OA 8
#define OB 9
#define OC 10
#define OD 11
#define ODP 12

#include "TIl308Driver.h"

int latches[] = {7, 6, 5, 4};
TIL308Driver display(OA, OB, OC, OD, ODP, latches, 4, 3);

void setup() {
  pinMode(13, OUTPUT);
  
  display.begin();
  Serial.begin(115200);
}

void loop() {
  glyph_t str[4];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 4; j++) {
      str[j] = i;
    }
    display.setOutput(str, 4);
    delay(200);
  }

  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  
  
  for (int i = 0; i < 10000; i++) {
    Serial.println(i);
    str[3] = i % 10;
    Serial.print(str[0]);
    str[2] = (i / 10) % 10;
    Serial.print(str[1]);
    str[1] = (i / 100) % 10;
    Serial.print(str[2]);
    str[0] = i / 1000;
    Serial.print(str[3]);
    Serial.println();
    // for (int j = 0; j < 4; j++) {
    //   str[3-j] = (int)(i / pow(10.0, j-1)) % 10;
    // }
    display.setOutput(str, 4);
    delay(200);
  }
}