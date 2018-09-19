# ArduinoSnake

This is my first Arduino project, a simple snake game using an Arduino, joystick, and 8x8 LED matrix interfaced with a MAX7219 display driver.

## Installation

Download .ino, .cpp, and .h into a folder titled "Snake" and upload .ino to board. Wire components according to diagram below.

<p align="center"> 
  <img src="https://i.imgur.com/gI9TfAa.png" width="600">
</p>

## How to Play

Player starts in top left corner, and food (single pixel) is randomly generated. Eating food increases length by 1. Leaving map or self-colliding loses, filling map wins.

<br>

<p align="center"> 
  <img src="https://i.imgur.com/hlYpcdZ.jpg?1" width="450">
</p>
