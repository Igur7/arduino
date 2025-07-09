const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

const int buttonRed = 2;
const int buttonGreen = 3;
const int buttonBlue = 4;

const int maxSequenceLength = 100;
int sequence[maxSequenceLength];
int level = 1;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  pinMode(buttonRed, INPUT_PULLUP);
  pinMode(buttonGreen, INPUT_PULLUP);
  pinMode(buttonBlue, INPUT_PULLUP);

  Serial.begin(9600);
  randomSeed(analogRead(A0));
}

void loop() {
  Serial.print("Poziom: ");
  Serial.println(level);

  sequence[level - 1] = random(0, 3);  // Dodaj losowy kolor do sekwencji

  // Pokaż sekwencję
  for (int i = 0; i < level; i++) {
    showColor(sequence[i]);
    delay(400);
    turnOffAll();
    delay(300);
  }

  // Odczytaj dane od gracza
  for (int i = 0; i < level; i++) {
    int userInput = waitForButtonPress();

    if (userInput == sequence[i]) {
      Serial.println("OK");
    } else {
      Serial.println("ŹLE! RESET.");

      // Efekt błędu
      for (int j = 0; j < 3; j++) {
        digitalWrite(redPin, HIGH);
        delay(200);
        digitalWrite(redPin, LOW);
        delay(200);
      }

      level = 1;
      delay(1000);
      return;
    }
  }

  // Jeśli gracz poprawnie powtórzył sekwencję
  level++;
  delay(1500);
}

void showColor(int color) {
  if (color == 0) {
    digitalWrite(redPin, HIGH);
  } else if (color == 1) {
    digitalWrite(greenPin, HIGH);
  } else if (color == 2) {
    digitalWrite(bluePin, HIGH);
  }
}

void turnOffAll() {
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
}

int waitForButtonPress() {
  while (true) {
    if (digitalRead(buttonRed) == LOW) {
      flashColor(0);
      return 0;
    }
    if (digitalRead(buttonGreen) == LOW) {
      flashColor(1);
      return 1;
    }
    if (digitalRead(buttonBlue) == LOW) {
      flashColor(2);
      return 2;
    }
  }
}

void flashColor(int color) {
  showColor(color);
  delay(300);
  turnOffAll();
}
