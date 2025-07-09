const int segmentPins[7] = {2, 3, 4, 5, 6, 7, 8};
const int buttonPin = 10;

const byte digits[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};

void setup() {
  for (int i = 0; i < 7; i++) pinMode(segmentPins[i], OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int rawValue = analogRead(A0);
  int volumeLevel = map(rawValue, 0, 1023, 0, 9);

  bool isPressed = digitalRead(buttonPin) == LOW;

  if (isPressed) {
    Serial.println("KILL"); 
  } else {
    Serial.println(rawValue); 
  }

  displayDigit(volumeLevel);
  delay(100);
}

void displayDigit(int digit) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digits[digit][i]);
  }
}
