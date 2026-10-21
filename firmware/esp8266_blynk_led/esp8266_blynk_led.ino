/*
  ESP8266 + Blynk IoT remote LED control
  Create a Virtual Pin datastream V0 (Integer/Enum, 0/1) and bind a switch.
  Verify board LED polarity and pin mapping. Many onboard LEDs are active-low.
*/
#define BLYNK_TEMPLATE_ID   "TMPLxxxxxxxx"
#define BLYNK_TEMPLATE_NAME "IoT Learning Lab"
#define BLYNK_AUTH_TOKEN    "YOUR_DEVICE_AUTH_TOKEN"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

constexpr uint8_t LED_PIN = 2; // Often GPIO2 / D4 on NodeMCU; verify mapping.

BLYNK_WRITE(V0) {
  int requested = param.asInt();
  if (requested == 0 || requested == 1) {
    digitalWrite(LED_PIN, requested ? HIGH : LOW);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();
}
