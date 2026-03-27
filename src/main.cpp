#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>

// Instantiate the display object
TFT_eSPI tft = TFT_eSPI(); 

void setup() {
  // Start serial for basic debugging output
  Serial.begin(115200);
  delay(2000); // Brief pause to open serial monitor
  Serial.println("Starting TFT_eSPI test on Raspberry Pi Pico...");

  // 1. Initialize the screen
  tft.init();
  tft.setRotation(1); // 1 = Landscape. Try 0, 2, or 3 if it's upside down or sideways.
  
  // 2. Clear the screen to black
  tft.fillScreen(TFT_BLACK);

  // 3. Draw static test text
  tft.setTextColor(TFT_WHITE, TFT_BLACK); // White text with black background to prevent overwriting artifacts
  tft.setTextSize(2);
  tft.setCursor(10, 10);
  tft.println("TFT_eSPI is working!");

  // 4. Draw a few shapes to test color and rendering
  tft.drawRect(10, 40, 100, 50, TFT_RED);       // Red hollow rectangle
  tft.fillCircle(160, 65, 20, TFT_BLUE);        // Blue filled circle
}

void loop() {
  // A simple counter to prove the screen hasn't frozen and is actively updating
  static int counter = 0;
  
  tft.setCursor(10, 110);
  tft.setTextColor(TFT_GREEN, TFT_BLACK); 
  tft.setTextSize(3);
  
  // Print the counter
  tft.print("Count: ");
  tft.println(counter);

  counter++;
  delay(500); // Update twice a second
}