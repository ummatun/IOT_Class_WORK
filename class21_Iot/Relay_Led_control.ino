#define RELAY_PIN 7  // Connect IN pin of relay to D7
#define switch_pin 4
void setup() {
  pinMode(RELAY_PIN, OUTPUT); // Set relay pin as output
  pinMode(switch_pin,INPUT);
  //pinmode
}

void loop() {
  int switch_value = digitalRead(switch_pin);
  if(switch_value == HIGH)
{
    digitalWrite(RELAY_PIN, HIGH); // Turn relay ON
}
  delay(2000); // Wait 2 seconds
  //digitalWrite(RELAY_PIN, LOW); // Turn relay OFF
  //delay(2000); // Wait 2 seconds
}


