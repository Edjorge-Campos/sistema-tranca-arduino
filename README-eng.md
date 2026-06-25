



# Password Lock System — Arduino Uno

A physical security system developed with an Arduino Uno that controls a lock based on a password entered through a 4x4 keypad.

This is my first personal project. I am Edjorge Campos, an 18-year-old first-year Computer Engineering student at ISCTE. I have a strong interest in developing functional systems, both digital and embedded. This project came to life after my Computer Architecture class sparked a desire to build something physical and real early on in my degree.

---

## Demonstration

https://github.com/user-attachments/assets/146f1d1e-6a7a-423a-a969-5d139b49fc25

## How it works

The system starts with the lock closed and the LCD displaying "Tranca fechada". The user types a 4-digit password on the keypad, with each key appearing as an asterisk on the screen. By pressing `#`, the system verifies the password:

- If correct, the LCD shows "Pass certa", the servo opens the lock, the green LED turns on, and after 2 seconds the lock closes automatically.
- If incorrect, the LCD shows "Pass errada" and the red LED turns on.
- If more than 4 digits are entered without confirming, the LCD shows "Pass invalida".

---

## Components

- 1x Arduino Uno
- 1x 4x4 Matrix Keypad
- 1x 16x2 LCD
- 1x Potentiometer (LCD brightness/contrast)
- 1x Servo motor
- 1x Green LED
- 1x Red LED
- 2x 100Ω Resistors
- 1x Breadboard
- Jumper wires

---

## Connections/Pinout

- **Keypad (Rows):** Pins 2, 3, 4, 5
- **Keypad (Columns):** Pins 6, 7, 8, 9
- **Servo motor:** Pin 10
- **Green LED:** Pin 11
- **Red LED:** Pin 12
- **LCD (RS, E, D4, D5, D6, D7):** Pins A0, A1, A2, A3, A4, A5

---

## Wiring Diagram

<img width="1536" height="694" alt="CircuitDesign" src="https://github.com/user-attachments/assets/d735fffe-2514-4281-938c-4568bef11c8a" />


---

## Libraries used

- [Keypad](https://playground.arduino.cc/Code/Keypad/) — matrix keypad reading
- [Servo](https://www.arduino.cc/reference/en/libraries/servo/) — servo motor control
- [LiquidCrystal](https://www.arduino.cc/reference/en/libraries/liquidcrystal/) — LCD control

---

## Future improvements

There are a few things I plan to improve as I gain more experience:

- Replace `delay()` with `millis()` to avoid blocking the system during wait times
- Save the password in EEPROM to allow changing it without recompiling the code
- Add a limit of attempts with a temporary lockout after consecutive errors
- Allow changing the password directly through the keypad

---

## Author

Edjorge Campos  
1st Year — Computer Engineering  
Interest in computer architecture and functional systems
