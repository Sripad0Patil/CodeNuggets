#include <TM1637Display.h>
#include <TimeLib.h>

// Define the CLK and DIO connections for TM1637
#define CLK 22
#define DIO 21
#define BUZZER_PIN 23  // Pin connected to the buzzer

TM1637Display display(CLK, DIO);

// Set initial time (e.g., 4:59 so you can test it soon)
int hours = 4;
int minutes = 59;

void setup() {
  display.setBrightness(5);
  display.clear();

  // Initialize buzzer pin as output
  pinMode(BUZZER_PIN, OUTPUT);

  // Set initial time in the ESP32's RTC
  setTime(hours, minutes, 0, 1, 1, 2023);  // Hour, Minute, Second, Day, Month, Year
}

void loop() {
  // Get current time from ESP32's RTC
  int currentHour = hour();
  int currentMinute = minute();

  // Display time in HH:MM format
  display.showNumberDecEx(currentHour * 100 + currentMinute, 0b01000000, true);

  // Check if it's time for the alarm (5:00 in this case)
  if (currentHour == 5 && currentMinute == 0) {
    triggerAlarm();
  }

  // Wait 1 second before updating time
  delay(1000);
}

// Function to trigger the alarm
void triggerAlarm() {
  // Sound the buzzer for 10 seconds
  for (int i = 0; i < 100; i++) {   // Adjust the number to control how long the buzzer sounds
    digitalWrite(BUZZER_PIN, HIGH);
    delay(100);                     // Buzzer ON
    digitalWrite(BUZZER_PIN, LOW);
    delay(100);                     // Buzzer OFF
  }
}
