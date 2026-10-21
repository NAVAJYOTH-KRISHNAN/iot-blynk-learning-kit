/*
  ESP32 + Blynk IoT remote LED control
  Create a Virtual Pin datastream V0 (Integer/Enum, values 0 and 1).
  Bind a switch widget to V0.
  Replace placeholders with values from your Blynk template/device.
  Keep credentials private.
*/
#define BLYNK_TEMPLATE_ID   "TMPLxxxxxxxx"
#define BLYNK_TEMPLATE_NAME "IoT Learning Lab"
#define BLYNK_AUTH_TOKEN    "YOUR_DEVICE_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

constexpr uint8_t LED_PIN = 2; // Verify for your exact board.
BlynkTimer timer;

BLYNK_WRITE(V0) {
  int requested = param.asInt();
  if (requested == 0 || requested == 1) {
    digitalWrite(LED_PIN, requested ? HIGH : LOW);
  }
}

BLYNK_CONNECTED() {
  // Optional: synchronize server state after configuring datastream behavior.
  // Blynk.syncVirtual(V0);
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW); // Safe default at boot.
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.println("Blynk LED control connected.");
}

void loop() {
  Blynk.run();
  timer.run();
}
