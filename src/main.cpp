#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
// oled 12c address
#define OLED_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, rst_pin:-1);

void setup() {
// write your initialization code here
}

void loop() {
// write your code here
}