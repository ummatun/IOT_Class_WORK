#define RELAY_PIN 7  // Relay control pin
#define BUTTON_PIN 4 // Push button pin

bool relayState = false; // Stores relay ON/OFF state
bool lastButtonState = LOW; // Last button state (LOW by default)
unsigned long lastDebounceTime = 0;
const int debounceDelay = 50; // Debounce time in milliseconds

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT); // Button is connected with external pull-down resistor
  
  digitalWrite(RELAY_PIN, LOW); // Ensure relay starts OFF
  Serial.begin(9600);
}

void loop() {
  bool buttonState = digitalRead(BUTTON_PIN);
  Serial.println(int(buttonState));

  if (buttonState == HIGH && lastButtonState == LOW && (millis() - lastDebounceTime) > debounceDelay) {
    relayState = !relayState;  // Toggle relay state
    digitalWrite(RELAY_PIN, relayState); // Update relay output
    lastDebounceTime = millis(); // Reset debounce timer
  }

  lastButtonState = buttonState; // Save last button state
}
