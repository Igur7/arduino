This Arduino project lets you control the brightness of an RGB LED using a single potentiometer. You can select which color (Red, Green, or Blue) to adjust by pressing one of three buttons. The selected color remains active until another button is pressed. Brightness values are updated in real-time and printed to the serial monitor only when they change significantly (±2 steps).

📦 Features:
3 buttons to select color (Red / Green / Blue)

1 potentiometer to control brightness (0–255)

Smooth PWM dimming of RGB LED

Serial output prints only on meaningful change (avoids spam)

🧰 Hardware:
Arduino (Uno/Nano/etc.)

RGB LED (common cathode)

3 momentary push buttons

1 potentiometer (10kΩ recommended)

3 resistors for LED (~220Ω each)
