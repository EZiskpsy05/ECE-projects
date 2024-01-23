// Declare values arrays
// (0,2) =  east-west   (1,3) = north-south
// Pedestrian = 0,1
// Advance turn signals = 2,3
// Switch 1,2,3,4 == 0,1,2,3
const int swtch[] = {0, 1, 2, 3};
const int pedes[] = {10, 11, 12, 13}; // lights from 4 -> 13
const int normal[] = {6, 5, 4, 4};
const int normal2[] = {7, 7, 9, 8};
const int normalinv[] = {4, 4, 6, 5};
const int normal2inv[] = {9, 8, 7, 7};
int savej = -1;
const int durations[] = {10000, 3000, 10000, 3000}; // delay durations
bool runNormalMode = true;
int switchOrder[4];
int switchIndex = 0;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(normal[i], OUTPUT);
    pinMode(normal2[i], OUTPUT);
    pinMode(pedes[i], OUTPUT);
  }
  for (int i = 0; i < 4; i++) {
    pinMode(i, INPUT);
  }
}

bool normalmode2() {
  digitalWrite(10, HIGH);
  digitalWrite(12, HIGH);
  int i = 0;
  int counter = 0;
  while (runNormalMode) { // function to keep traffic going
    if (savej == 3 || savej == 1) {
      digitalWrite(4, LOW);
      digitalWrite(normal[i], HIGH);
      digitalWrite(normal2[i], HIGH);

      delay(durations[i]);

      digitalWrite(normal[i], LOW);
      digitalWrite(normal2[i], LOW);

      i = (i + 1) % 4;
      counter++;
      if (counter == 3) {
        savej = -1;
        counter = 0, i = 0; // Reset the counter for the next iteration
      }
    } else if (savej == 2 || savej == 0) {
      digitalWrite(7, LOW);
      digitalWrite(normalinv[i], HIGH);
      digitalWrite(normal2inv[i], HIGH);

      delay(durations[i]);

      digitalWrite(normalinv[i], LOW);
      digitalWrite(normal2inv[i], LOW);

      i = (i + 1) % 4;
      counter++;
      if (counter == 3) {
        savej = -1;
        counter = 0, i = 0; // Reset the counter for the next iteration
      }
    } else {
      digitalWrite(normal[i], HIGH);
      digitalWrite(normal2[i], HIGH);

      delay(durations[i]);

      digitalWrite(normal[i], LOW);
      digitalWrite(normal2[i], LOW);

      i = (i + 1) % 4; // Move to the next light (cycling through 0, 1, 2)
      for (int j = 0; j < 4; j++) {
        if (digitalRead(swtch[j]) == HIGH) {
          runNormalMode = false; // Stop calling normalmode()
          break;                  // Exit the loop
        }
      }
    }
  }
}

void loop() {
  int pedes1 = digitalRead(0), pedes2 = digitalRead(1);
  const int pins[] = {5, 6, 8, 9, 11, 13};
  if (runNormalMode)
    runNormalMode = normalmode2();
  else {
    for (int j = 0; j < 4; j++) {
      if (digitalRead(swtch[j]) == HIGH) {
        // Check if the switch is not already in the order array
        bool switchFound = false;
        for (int k = 0; k < 4; k++) {
          if (switchOrder[k] == j) {
            switchFound = true;
            break;
          }
        }

        // If the switch is not in the order array, add it
        if (!switchFound) {
          switchOrder[switchIndex] = j;
          switchIndex = (switchIndex + 1) % 4;
        }
        turnsig(j);
        runNormalMode = true; // Set to false to stop calling normalmode()

        switch (pedes1) {
          case HIGH:
            activatePedestrianLights();
            break;
        }
        switch (pedes2) {
          case HIGH:
            activatePedestrianLights();
            break;
        }
      }
    }
  }
}
void activatePedestrianLights() {
  digitalWrite(4, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(12, HIGH);

  const int pins[] = {5, 6, 8, 9, 11, 13};
  for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); i++)
    digitalWrite(pins[i], LOW);

  delay(3000);
  digitalWrite(4, LOW);
}

void turnsig(int j) {
  switch (j) {
    case 0:
      digitalWrite(4, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
      delay(6000);
      digitalWrite(11, LOW);
      for (int i = 0; i < 5; i++) {
        digitalWrite(10, HIGH);
        delay(250);
        digitalWrite(10, LOW);
        delay(250);
      }
      digitalWrite(11, LOW);
      digitalWrite(10, HIGH);
      break;

    case 1:
      digitalWrite(4, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      delay(6000);
      digitalWrite(13, LOW);
      for (int i = 0; i < 5; i++) {
        digitalWrite(12, HIGH);
        delay(250);
        digitalWrite(12, LOW);
        delay(250);
      }
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      break;

    case 2:
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      for (int i = 0; i < 6; i++) {
        digitalWrite(6, HIGH);
        delay(500);
        digitalWrite(6, LOW);
        delay(500);
      }
      digitalWrite(5, HIGH);
      delay(2000);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(4, HIGH);
      delay(1000);
      digitalWrite(4, LOW);
      break;

    case 3:
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      for (int i = 0; i < 6; i++) {
        digitalWrite(9, HIGH);
        delay(500);
        digitalWrite(9, LOW);
        delay(500);
      }
      digitalWrite(8, HIGH);
      delay(2000);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(7, HIGH);
      delay(1000);
      digitalWrite(7, LOW);
      break;
  }
  savej = j;
  runNormalMode = true;
}