// 3 digit 7-segment cathode led display 
// code for counter from 1 to 100
#include <Arduino.h>

// Define ESP8266 pins
#define D1 1 // digit 1
#define D2 13 // digit 2
#define D3 14 // digit 3
#define clockPin 5 // clock pin
#define dataPin 4 // data pin

// Array of cathode pins for each display digit
int cathodePins[] = {D1, D2, D3};  // digit 1, digit 2, digit 3

// Array to hold digit values
int numbers[3];

long number = 0; 
int num1 = 0;
int num2 = 0;
int num3 = 0;

// Segment map for numbers 0-9 (common cathode display)
byte table[10] = {
    B11111100, // 0
    B01100000, // 1
    B11011010, // 2
    B11110010, // 3
    B01100110, // 4
    B10110110, // 5
    B10111110, // 6
    B11100000, // 7
    B11111110, // 8
    B11110110  // 9
};

int count = 0; // Keeps track of which digit is being displayed

// Function to clear the display by turning off all digits
void clearDisplay() {
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
}

// Function to display a number on the 7-segment display
void displayNum(long num) {
  num1 = num / 100;
  numbers[0] = num1;
  int num1_remove = num - (num1 * 100);
  num2 = num1_remove / 10;
  numbers[1] = num2;
  int num2_remove = num1_remove - (num2 * 10);
  num3 = num2_remove / 1;
  numbers[2] = num3;
  
  clearDisplay();

if ( numbers[0] == 0 && count == 0){
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000); //send the data
}else if ( numbers[0] == 0 && numbers[1] == 0 && count == 1){
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000); //send the data
}else {
  shiftOut(dataPin, clockPin,LSBFIRST, table[numbers[count]]); 
}
  
//  shiftOut(dataPin, clockPin,LSBFIRST, table[numbers[count]]); 
  digitalWrite(cathodePins[count], LOW); 
  count++; 
  if (count == 3) { 
    count = 0;
  }
  delay(2);  // try out different delays suitable to your board
}

void setup() {
    // Set pins as output
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT); 
    // Clear the display initially
    clearDisplay();
}

void loop() {
    // Iterate through numbers from 0 to 99
    for (long num = 0; num < 101; num++) {
      // Display the current number
      displayNum(num);
    }
}
