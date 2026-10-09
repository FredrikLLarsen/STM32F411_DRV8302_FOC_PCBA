// Blink a pin on Arduino
// Change pin number if needed
const int EN_GATE = 8;
const int M_PWM = 9;
const int INL_C = 10;
const int INH_C = 11;

void setup() {
  pinMode(EN_GATE, OUTPUT);   // Set pin as output
  pinMode(M_PWM, OUTPUT);   // Set pin as output
  pinMode(INL_C, OUTPUT);   // Set pin as output
  pinMode(INH_C, OUTPUT);   // Set pin as output
}

void loop() {
  digitalWrite(EN_GATE, HIGH);  // Turn pin ON
  digitalWrite(M_PWM, LOW);  // Turn pin LOW
  digitalWrite(INL_C, LOW);  // Turn pin LOW
  digitalWrite(INH_C, HIGH);  // Turn pin LOW

}
