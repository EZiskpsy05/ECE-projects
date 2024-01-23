// Define the pins for columns and layers
int columnPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};  // Pins for columns
int layerPins[] = {A0, A1, A2};  // Pins for layers

// Setup function to initialize pin modes
void setup() {
  // Set the pin modes for columns as OUTPUT
  for (int i = 0; i < 9; i++) {
    pinMode(columnPins[i], OUTPUT);
  }
  // Set the pin modes for layers as OUTPUT
  for (int i = 0; i < 3; i++) {
    pinMode(layerPins[i], OUTPUT);
  }
}

// Function to turn on all layers
void turnon(){
  // Turn on all layers by setting them to LOW
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
}

void loop() {
  digitalWrite(6,HIGH);   // Turn on the LED connected to pin 6
  delay(5000);  // Delay for 5000 milliseconds (5 seconds)
    for (int i =0;i<9;i++){
    digitalWrite(columnPins[i], HIGH);}
  delay(5000);	  // Delay for 5000 milliseconds (5 seconds)
  digitalWrite(A0,HIGH),digitalWrite(A1,HIGH),digitalWrite(A2,HIGH);
  // Call various functions to create light patterns
  	waterfall();
  	turnon();
  	alternatemain();
	fascinatingPattern();
  	GPT();
  	randommadness2();
  	moving_rectangle();
  	illusion();
	maintet();
  	lightUpStar();
  	randommadness();
  	slideDownRightToLeft();
  	mixture1();
    turnon();
}

void lightUpStar() {
  // Define the star pattern
  int starPattern[3][3] = {
    {0, 1, 0},
    {1, 1, 1},
    {0, 1, 0}
  };

  // Loop through layers
  for (int layer = 0; layer < 3; layer++) {
    // Loop through columns
    for (int col = 0; col < 9; col++) {
      // Activate LEDs based on the star pattern
      digitalWrite(layerPins[layer], HIGH);
      digitalWrite(columnPins[col], starPattern[layer][col]);
      delay(100);  // Adjust the delay for the desired speed
      digitalWrite(columnPins[col], LOW);
    }
    digitalWrite(layerPins[layer], LOW);
  }
}

void randommadness() {
  for (int col = 0; col < 9; col++) {
    for (int layer = 0; layer < 3; layer++) {
      digitalWrite(layerPins[layer], HIGH);
      digitalWrite(columnPins[col], HIGH);
      delay(50);  // Adjust the delay for the desired speed
      digitalWrite(columnPins[col], LOW);
      digitalWrite(layerPins[layer], LOW);
    }
  }
}
void fascinatingPattern() {
  // Define the pattern
  int starPattern[3][3] = {
    {3, 2, 7},
    {2, 3, 5},
    {0, 1, 3}
  };

    // Display the star pattern
    for (int i = 0; i < 1; i++) {
      for (int layer = 0; layer < 3; layer++) {
        for (int col = 0; col < 9; col++) {
          digitalWrite(layerPins[layer], HIGH);
          digitalWrite(columnPins[col], starPattern[layer][col]);
          delay(100);  // Adjust the delay for the desired speed
          digitalWrite(columnPins[col], LOW);
        }
        digitalWrite(layerPins[layer], LOW);
      }
   }
}

void randommadness2() {
  for (int i = 0; i < 3; i++) {  // Repeat the pattern 50 times (adjust as needed)
    for (int j = 0; j < 20; j++) {  // Perform random actions 20 times (adjust as needed)
      int randomCol = random(9);  // Randomly choose a column
      int randomLayer = random(3);  // Randomly choose a layer

      // Turn off all layers and columns
      for (int layer = 0; layer < 3; layer++) {
        digitalWrite(layerPins[layer], HIGH);
      }
      for (int col = 0; col < 9; col++) {
        digitalWrite(columnPins[col], LOW);
      }

      // Turn on the random layer and column
      digitalWrite(layerPins[randomLayer], LOW);
      digitalWrite(columnPins[randomCol], HIGH);

      delay(50);  // Adjust the delay for the desired speed

      // Turn off the random column and layer
      digitalWrite(columnPins[randomCol], LOW);
      digitalWrite(layerPins[randomLayer], HIGH);

      delay(50);  // Adjust the delay for the desired speed
    }
  }
}
void slideDownRightToLeft() {
  for (int col = 8; col >= 0; col--) {
    for (int layer = 0; layer < 3; layer++) {
      digitalWrite(layerPins[layer], HIGH);
      digitalWrite(columnPins[col], HIGH);
      delay(50);  // Adjust the delay for the desired speed
      digitalWrite(columnPins[col], LOW);
      digitalWrite(layerPins[layer], LOW);
    }
  }
}

void test(){
  for (int i = 0; i <10;i++){
   for (int i = 0; i < 9; i++) { 
     digitalWrite(columnPins[i], HIGH);
   }

  }
}
void tet() {
const int numColumns = 8;
int columnPins[] = {2, 3, 4, 7, 10, 9, 8, 5};
  for (int i = 0; i <2;i++){
  for (int i = 0; i < numColumns; i++) {
    // Turn on the current column
    digitalWrite(columnPins[i], HIGH);
    delay(50);  // Delay for 100 milliseconds
    
    // Turn off the previous column
    if (i > 0) {
      digitalWrite(columnPins[i - 1], LOW);
    } else {
      digitalWrite(columnPins[numColumns - 1], LOW); // Turn off the last column
    }
  }
 }

  // Turn off the last column after the loop
  digitalWrite(columnPins[numColumns - 1], LOW);
  }
void maintet(){
  tet();
 digitalWrite(A0, LOW), digitalWrite(A1,HIGH),digitalWrite(A2,HIGH);
  tet();
 digitalWrite(A1, LOW), digitalWrite(A0,HIGH),digitalWrite(A2,HIGH);
  tet();
 digitalWrite(A2, LOW), digitalWrite(A1,HIGH),digitalWrite(A0,HIGH);
  tet();
 digitalWrite(A2, LOW), digitalWrite(A1,LOW),digitalWrite(A0,LOW);
  
}

void mixture1(){
  
  tet(),slideDownRightToLeft(),test(); // Combine other function
  delay(1000);
}

void illusion() {
  // Loop through the illusion pattern 50 times
  for (int i = 0; i < 50; i++) {
    // Set layers A0, A1, and A2 to specific states
    digitalWrite(A2, HIGH), digitalWrite(A1, HIGH), digitalWrite(A0, LOW);
    // Set columns 2, 3, and 4 to HIGH
    digitalWrite(2, HIGH), digitalWrite(3, HIGH), digitalWrite(4, HIGH);
    // Delay for 50 milliseconds
    delay(50);
    
    // Set layers A0, A1, and A2 to specific states
    digitalWrite(A2, HIGH), digitalWrite(A1, LOW), digitalWrite(A0, HIGH);
    // Set columns 2, 3, and 4 to LOW
    digitalWrite(2, LOW), digitalWrite(3, LOW), digitalWrite(4, LOW);
    // Set columns 5, 6, and 7 to HIGH
    digitalWrite(5, HIGH), digitalWrite(6, HIGH), digitalWrite(7, HIGH);
    // Delay for 50 milliseconds
    delay(50);
    
    // Set layers A0, A1, and A2 to specific states
    digitalWrite(A2, LOW), digitalWrite(A1, HIGH), digitalWrite(A0, HIGH);
    // Set columns 5, 6, and 7 to LOW
    digitalWrite(5, LOW), digitalWrite(6, LOW), digitalWrite(7, LOW);
    // Set columns 8, 9, and 10 to HIGH
    digitalWrite(8, HIGH), digitalWrite(9, HIGH), digitalWrite(10, HIGH);
    // Delay for 50 milliseconds
    delay(50);
  }
}

void moving_rectangle() {
  // Turn off all layers
  for (int layer = 0; layer < 3; layer++) {
    digitalWrite(layerPins[layer], LOW);
  }
  
  // Loop through the moving rectangle pattern 10 times
  for (int i = 0; i < 10; i++) {
    // Set columns 2 and 10 to LOW
    digitalWrite(2, LOW), digitalWrite(10, LOW);
    // Set columns 5 and 7 to HIGH
    digitalWrite(5, HIGH), digitalWrite(7, HIGH);
    // Delay for 100 milliseconds
    delay(100);
    
    // Turn off columns 5 and 7
    digitalWrite(5, LOW), digitalWrite(7, LOW);
    // Set columns 4 and 8 to HIGH
    digitalWrite(4, HIGH), digitalWrite(8, HIGH);
    // Delay for 100 milliseconds
    delay(100);
    
    // Turn off columns 4 and 8
    digitalWrite(4, LOW), digitalWrite(8, LOW);
    // Set columns 3 and 9 to HIGH
    digitalWrite(3, HIGH), digitalWrite(9, HIGH);
    // Delay for 100 milliseconds
    delay(100);
    
    // Turn off columns 3 and 9
    digitalWrite(3, LOW), digitalWrite(9, LOW);
    // Set columns 2 and 10 to HIGH
    digitalWrite(2, HIGH), digitalWrite(10, HIGH);
    // Delay for 100 milliseconds
    delay(100);
  }
}

void GPT(){
  // Loop indefinitely
  for (int o=0;o<1;o++) {
    // Loop through each layer from bottom to top
    for (int layer = 2; layer >= 0; layer--) {
      // Turn off all layers
      for (int i = 0; i < 3; i++) {
        digitalWrite(layerPins[i], HIGH);
      }
      
      // Turn on the current layer
      digitalWrite(layerPins[layer], LOW);

      // Loop through each column and turn on the corresponding LED
      for (int col = 0; col < 9; col++) {
        digitalWrite(columnPins[col], HIGH);  // Turn on the current column
        delay(100);  // Adjust delay if needed
      }

      delay(100);  // Adjust delay between layers if needed

      // Turn off all columns
      for (int col = 0; col < 9; col++) {
        digitalWrite(columnPins[col], LOW);
      }
    }
    
    // Inverse pattern: Loop through each layer from top to bottom
    for (int layer = 0; layer <= 2; layer++) {
      // Turn off all layers
      for (int i = 0; i < 3; i++) {
        digitalWrite(layerPins[i], HIGH);
      }
      
      // Turn on the current layer
      digitalWrite(layerPins[layer], LOW);

      // Loop through each column and turn on the corresponding LED
      for (int col = 8; col >= 0; col--) {
        digitalWrite(columnPins[col], HIGH);  // Turn on the current column
        delay(100);  // Adjust delay if needed
      }

      delay(100);  // Adjust delay between layers if needed

      // Turn off all columns
      for (int col = 0; col < 9; col++) {
        digitalWrite(columnPins[col], LOW);
      }
    }

    delay(100);  // Adjust delay between rounds if needed
  }
}


void alternate(){ // Same functions for alternate2()
  int x[]={2,4,6,8,10};
  int y[]={3,5,7,9};
  for (int i=0;i<4;i++){
    for (int i=0;i<5;i++){
      	  delay(250);
      digitalWrite(y[i],LOW);
      digitalWrite(x[i],HIGH);
          delay(250);
      digitalWrite(x[i],LOW);
      digitalWrite(y[i],HIGH);
    }
  }
}

void alternate2() {
  int x[] = {2, 4, 6, 8, 10};
  int y[] = {3, 5, 7, 9};
  for (int j = 0; j < 3; j++) {
    // Turn x ON, y OFF
    for (int i = 0; i < 5; i++) {
      digitalWrite(x[i], HIGH);
      digitalWrite(y[i % 4], LOW);}
    delay(1000);
    // Turn x OFF, y ON
    for (int i = 0; i < 5; i++) {
      digitalWrite(x[i], LOW);
      digitalWrite(y[i % 4], HIGH);
    }
    delay(1000);
  }
}


void alternatemain(){ // Combine alternate function
  alternate2();
  delay(250);
  alternate();
}


void waterfall() {
  int x[] = {2, 3, 4, 7, 10};
    // Loop through the waterfall pattern 10 times
  for (int i=0;i<10;i++){
  for (int j = 0; j < 8; j++) {// Loop through each step of the waterfall
    digitalWrite(A0,HIGH),digitalWrite(A1,HIGH),digitalWrite(A2,LOW);
    for (int i = 0; i < 5; i++) {
      digitalWrite(x[i], HIGH);}// Turn on columns 2, 3, 4, 7, and 10
    delay(10);
    for (int i = 0; i < 5; i++) {// Turn off columns 2, 3, 4, 7, and 10
      digitalWrite(x[i], LOW);}
    digitalWrite(A0,LOW),digitalWrite(A1,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(A0,HIGH),digitalWrite(A1,HIGH),digitalWrite(A2,LOW);
    delay(10);
  }
  for (int j = 0; j < 10; j++) {
    digitalWrite(A0,HIGH),digitalWrite(A1,HIGH),digitalWrite(A2,LOW);
    for (int i = 0; i < 5; i++) {
      digitalWrite(x[i], HIGH);}
    delay(10);
    for (int i = 0; i < 5; i++) {
      digitalWrite(x[i], LOW);}
    digitalWrite(A0,LOW),digitalWrite(A1,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(A0,HIGH),digitalWrite(A1,HIGH),digitalWrite(A2,LOW);
    delay(10);
  }
  for (int j = 0; j < 10; j++) {
    digitalWrite(A0,HIGH),digitalWrite(A1,HIGH),digitalWrite(A2,LOW);
    for (int i = 0; i < 5; i++) {
      digitalWrite(x[i], HIGH);}
    delay(10);
    for (int i = 0; i < 5; i++) {
      digitalWrite(x[i], LOW);}
    digitalWrite(A0,LOW),digitalWrite(A1,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(A0,HIGH),digitalWrite(A1,HIGH),digitalWrite(A2,LOW);
    delay(10);
  }
  for (int j = 0; j < 10; j++) {
    digitalWrite(A0,HIGH),digitalWrite(A1,HIGH),digitalWrite(A2,LOW);
    for (int i = 0; i < 5; i++) {
      digitalWrite(x[i], HIGH);}
    delay(10);
    for (int i = 0; i < 5; i++) {
      digitalWrite(x[i], LOW);}
    digitalWrite(A0,LOW),digitalWrite(A1,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(A0,HIGH),digitalWrite(A1,HIGH),digitalWrite(A2,LOW);
    delay(10);
  }
  for (int j = 0; j < 10; j++) {
    digitalWrite(A0,HIGH),digitalWrite(A1,HIGH),digitalWrite(A2,LOW);
    for (int i = 0; i < 5; i++) {
      digitalWrite(x[i], HIGH);}
    delay(10);
    for (int i = 0; i < 5; i++) {
      digitalWrite(x[i], LOW);}
    digitalWrite(A0,LOW),digitalWrite(A1,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(A0,HIGH),digitalWrite(A1,HIGH),digitalWrite(A2,LOW);
    delay(10);
  }
 }
}

