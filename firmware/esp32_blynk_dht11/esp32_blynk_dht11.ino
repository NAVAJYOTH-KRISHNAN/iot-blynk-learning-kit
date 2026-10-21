/*
  ESP32 + DHT11 telemetry + Blynk LED switch
  Datastreams: V0 temperature (Double), V1 humidity (Double), V2 LED (0/1).
  Install Blynk and a compatible DHT sensor library.
  Check your module pinout before wiring.
*/
#define BLYNK_TEMPLATE_ID   "TMPLxxxxxxxx"
#define BLYNK_TEMPLATE_NAME "IoT Learning Lab"
#define BLYNK_AUTH_TOKEN    "YOUR_DEVICE_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

constexpr uint8_t DHT_PIN = 4;
constexpr uint8_t LED_PIN = 2;
#define DHTTYPE DHT11
DHT dht(DHT_PIN, DHTTYPE);
BlynkTimer timer;

void sendSensorReadings() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("DHT read failed; skipping cloud update.");
    return;
  }

  Serial.printf("Temperature: %.1f C, Humidity: %.1f %%\n",
                temperature, humidity);
  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, humidity);
}

BLYNK_WRITE(V2) {
  int requested = param.asInt();
  if (requested == 0 || requested == 1) {
    digitalWrite(LED_PIN, requested ? HIGH : LOW);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  dht.begin();

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(3000L, sendSensorReadings);
}

void loop() {
  Blynk.run();
  timer.run();
}
