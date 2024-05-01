# 3-Digit 7-Segment Display Counter

This repository contains code for an Arduino-based project that controls a 3-digit 7-segment common cathode LED display
using a 74HC164 shift register IC. The code demonstrates a counter that cycles through numbers from 0 to 100 and displays
them on the 7-segment display.

## Requirements

- Arduino or compatible microcontroller (such as ESP8266, ESP32 etc.).
- 3-digit 7-segment common cathode LED display.
- 74HC164 shift register IC.
- Wires and resistors for connecting the display and shift register to the microcontroller.
- Breadboard (optional) for prototyping.

## Wiring

Connect the microcontroller pins, shift register, and 3-digit 7-segment display according to the pin definitions in the code:

- `D1` (Pin 1) -> Control for the first digit.
- `D2` (Pin 13) -> Control for the second digit.
- `D3` (Pin 14) -> Control for the third digit.
- `clockPin` (Pin 5) -> Clock pin for the shift register.
- `dataPin` (Pin 4) -> Data pin for the shift register.

**Shift Register Connection:**
- Connect the shift register's output pins to the segments of the 3-digit 7-segment display as per your circuit design.
- Connect the shift register's `clock` and `data` inputs to the corresponding `clockPin` and `dataPin` on the microcontroller.

## Code Overview

- The `setup()` function initializes the pins as outputs and clears the display.
- The `loop()` function cycles through numbers from 0 to 100, displaying each on the 3-digit display.
- The `displayNum()` function handles the display of a given number on the 3-digit 7-segment display.
- The `clearDisplay()` function clears the display by turning off all digits.

## Usage

1. Clone the repository to your local machine:
    ```shell
    git clone https://github.com/abhisheksrvt/3-digit-7-segment-display.git
    ```

2. Open the project in your Arduino IDE.

3. Connect the 3-digit 7-segment common cathode LED display and the 74HC164 shift register
    to your microcontroller according to the wiring instructions above.
   
5. Upload the code to your Arduino.

6. Observe the display cycling through numbers from 0 to 100.

## Contributing

Contributions are welcome! If you find any bugs or have suggestions for improvements, please open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).

---

Thank you for checking out this project! We hope you find it useful and educational.
