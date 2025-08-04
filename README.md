Description:
This project enables controlling the volume of the Spotify desktop app on Windows using input signals from an Arduino via serial communication. A Python script reads the values sent from Arduino and adjusts Spotify’s volume dynamically. It also includes a “kill switch” feature that mutes Spotify and requires pressing the switch again to restore the previous volume.

Features:

Volume control from 0% to 100% based on Arduino input.

Kill switch to mute/unmute Spotify with a toggle mechanism.

Serial communication over a COM port.

Uses the pycaw library for controlling Windows audio sessions.

Technologies:

Python 3

Pycaw (Windows audio control)

Arduino (sending serial data)

How to use:

Connect Arduino and send volume data through the serial port.

Run the Python script to listen to serial input and control Spotify volume.

Use the kill switch button to mute/unmute Spotify.

Parts needed:

Potentiometer

7-segment display

Arduino Uno

3 push buttons
