#define LS 7
#define OA 8
#define OB 9
#define OC 10
#define OD 11
#define ODP 12

void setup() {
  digitalWrite(LS, HIGH);
  pinMode(LS, OUTPUT);

  digitalWrite(OA, LOW);
  pinMode(OA, OUTPUT);

  digitalWrite(OB, LOW);
  pinMode(OB, OUTPUT);

  digitalWrite(OC, LOW);
  pinMode(OC, OUTPUT);

  digitalWrite(OD, LOW);
  pinMode(OD, OUTPUT);

  digitalWrite(ODP, LOW);
  pinMode(ODP, OUTPUT);
  
  pinMode(13, OUTPUT);
}

void latch() {
  digitalWrite(LS, LOW);
  delay(1);
  digitalWrite(LS, HIGH);
}

void loop() {
  for (int i = 0; i < 16; i++) {
    digitalWrite(OA, (i & 1) ? HIGH : LOW);
    digitalWrite(OB, (i & 2) ? HIGH : LOW);
    digitalWrite(OC, (i & 4) ? HIGH : LOW);
    digitalWrite(OD, (i & 8) ? HIGH : LOW);
    latch();
    delay(1000);
  }

  digitalWrite(OA, LOW);
  digitalWrite(OB, LOW);
  digitalWrite(OC, LOW);
  digitalWrite(OD, LOW);
  
  for (int i = 0; i < 4; i++) {
    digitalWrite(ODP, LOW);
    latch();
    delay(250);
    digitalWrite(ODP, HIGH);
    latch();
    delay(250);
  }
  
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
}