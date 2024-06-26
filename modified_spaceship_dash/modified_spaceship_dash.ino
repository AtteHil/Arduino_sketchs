int switchState;
int previous = LOW;
unsigned long time = 0;
unsigned long debounce = 200UL;
bool toggleState = false;

void setup() {
  
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
  // initializing pins from 2 to 5
  digitalWrite(3, 1);
}

void loop() {
  // put your main code here, to run repeatedly:
    switchState = digitalRead(2); // Read the state of the button

  if (switchState == HIGH && previous == LOW && (millis() - time) > debounce) {
    toggleState = !toggleState; // Toggle the state
    time = millis(); // Reset the debounce timer
  }

  if (toggleState) {
    // If toggled on, blink red LEDs
    if ((millis() % 500) < 250) {
      digitalWrite(4, HIGH); // Red LED 1 on
      digitalWrite(5, LOW);  // Red LED 2 off
    } else {
      digitalWrite(4, LOW);  // Red LED 1 off
      digitalWrite(5, HIGH); // Red LED 2 on
    }
    digitalWrite(3, LOW); // Turn off the green LED
  } else {
    // If toggled off, turn on the green LED and turn off the red LEDs
    digitalWrite(3, HIGH); // Turn on the green LED
    digitalWrite(4, LOW);  // Turn off Red LED 1
    digitalWrite(5, LOW);  // Turn off Red LED 2
  }

  previous = switchState; // Save the current state as previous state
}
