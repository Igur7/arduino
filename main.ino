const int potPin = A0;

const int buttonRed = 2;
const int redPin = 9;

const int buttonGreen = 3;
const int greenPin = 10;

const int buttonBlue = 4;
const int bluePin = 11;

int lastSelected = -1;

int redBrightness = 0;
int greenBrightness = 0;
int blueBrightness = 0;

int lastRed = -1;
int lastGreen = -1;
int lastBlue = -1;

void setup() {
  Serial.begin(9600);

  pinMode(buttonRed, INPUT_PULLUP);
  pinMode(redPin, OUTPUT);

  pinMode(buttonGreen, INPUT_PULLUP);
  pinMode(greenPin, OUTPUT);

  pinMode(buttonBlue, INPUT_PULLUP);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Obsługa przycisków
  if (digitalRead(buttonRed) == LOW) {
    lastSelected = redPin;
    Serial.println("Wybrano czerwony");
    delay(200);
  } 
  else if (digitalRead(buttonGreen) == LOW) {
    lastSelected = greenPin;
    Serial.println("Wybrano zielony");
    delay(200);
  }
  else if (digitalRead(buttonBlue) == LOW) {
    lastSelected = bluePin;
    Serial.println("Wybrano niebieski");
    delay(200);
  }

  // Odczyt potencjometru
  int potValue = analogRead(potPin);
  int brightness = potValue / 4;

  // Aktualizacja jasności tylko wybranego koloru
  if (lastSelected == redPin) {
    redBrightness = brightness;
  } else if (lastSelected == greenPin) {
    greenBrightness = brightness;
  } else if (lastSelected == bluePin) {
    blueBrightness = brightness;
  }

  // Ustawienie PWM
  analogWrite(redPin, redBrightness);
  analogWrite(greenPin, greenBrightness);
  analogWrite(bluePin, blueBrightness);

  if (abs(redBrightness - lastRed) >= 2 ||
      abs(greenBrightness - lastGreen) >= 2 ||
      abs(blueBrightness - lastBlue) >= 2) {

    Serial.print("R: "); Serial.print(redBrightness);
    Serial.print(" G: "); Serial.print(greenBrightness);
    Serial.print(" B: "); Serial.println(blueBrightness);

    lastRed = redBrightness;
    lastGreen = greenBrightness;
    lastBlue = blueBrightness;
  }
}
