
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

#define OLED_RESET 4
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int ledPin=13;
String message;

void setup(){
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
  display.display();
  delay(500);
  
  display.clearDisplay();
  
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.cp437(true);
  
  display.clearDisplay();
  display.setCursor(10, 10);
  display.print("Waiting for \n  greeting...");
  display.display();

}

void loop(){
  if(Serial.available()){         //From RPi to Arduino
    message = Serial.readString();  //conveting the value of chars to integer

    display.clearDisplay();
    display.setCursor(10, 10);
    display.print("Good Morning!");
    display.display();
    
    delay(1000);

    display.clearDisplay();
    display.setCursor(10, 10);
    display.print("You said: ");
    display.display();
    
    delay(1000);
    
    display.clearDisplay();
    display.setCursor(10, 10);
    display.print(message);
    display.display();
    
    delay(2000);
  }
}
