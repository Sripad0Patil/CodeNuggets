#include <WiFi.h>
#include <TM1637Display.h>
#include "time.h"
#include "esp_sntp.h"

// WiFi credentials
const char *ssid = "SSiD";      // Replace with your WiFi SSID
const char *password = "password"; // Replace with your WiFi password

// NTP Server settings
const char *ntpServer1 = "pool.ntp.org";
const char *ntpServer2 = "time.nist.gov";
const long gmtOffset_sec = 19800;       // GMT+5:30 offset in seconds
const int daylightOffset_sec = 0;      // No daylight saving time in India

// Timezone rule (optional, adjust as per your region)
const char *time_zone = "IST-5:30";    // Indian Standard Time (optional)

// TM1637 Pins
#define CLK 22
#define DIO 21

TM1637Display display(CLK, DIO);

// Function to print local time for debugging
void printLocalTime() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}

// Callback function for NTP time sync
void timeavailable(struct timeval *t) {
  Serial.println("NTP time synchronized!");
  printLocalTime();
}

void setup() {
  // Initialize serial and display
  Serial.begin(115200);
  display.setBrightness(5);
  display.clear();

  // Connect to WiFi
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" CONNECTED");

  // Configure NTP
  sntp_set_time_sync_notification_cb(timeavailable); // Set callback
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer1, ntpServer2); // Basic NTP config
  // configTzTime(time_zone, ntpServer1, ntpServer2); // Optional: Timezone-based config

  Serial.println("Time synchronization initiated.");
}

void loop() {
  // Fetch the current time
  struct tm timeinfo;
  if (getLocalTime(&timeinfo)) {
    // Display the time on the 4-digit 7-segment display
    int hours = timeinfo.tm_hour;
    int minutes = timeinfo.tm_min;
    display.showNumberDecEx(hours * 100 + minutes, 0b01000000, true);
  } else {
    Serial.println("Waiting for time sync...");
  }

  // Wait for 1 second before refreshing
  delay(1000);
}
