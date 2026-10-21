# Blynk IoT Setup: Template, Datastreams, Dashboard

Official documentation: https://docs.blynk.io/

## Integration paths
**Static credentials:** easiest for learning. Create a device and add template/device credentials to firmware. Keep them private.

**Blynk.Edgent:** a provisioning-oriented path for supported boards, with capabilities documented in the official Edgent guide. Follow the current guide for your specific board and library version.

## Create a template
1. Sign in to Blynk.Console.
2. Open Developer Zone and create a template.
3. Choose ESP32 and Wi-Fi for the primary examples.
4. Copy Template ID and Template Name into firmware.
5. Create a device from the template and obtain its device authentication token for the static-token workflow.

## Datastreams for DHT11 + LED
Use Virtual Pin datastreams for the provided Arduino sketches.

| Name | Virtual pin | Type | Suggested range | Direction |
|---|---|---|---|---|
| Temperature | V0 | Double | 0 to 60 °C | Device to cloud |
| Humidity | V1 | Double | 0 to 100 % | Device to cloud |
| LED Control | V2 | Integer/Enum | 0 to 1 | App and device |
| Device Status (optional) | V3 | Integer | 0 to 1 | Device to cloud |

Match each pin, data type, and range in the console to firmware.

## Dashboard
- Temperature: value display or gauge bound to V0.
- Humidity: value display or gauge bound to V1.
- LED control: switch bound to V2.
- Optional: chart widgets for telemetry history where supported by your plan/settings.
- Configure mobile and web dashboards as needed.

## Firmware credentials
- BLYNK_TEMPLATE_ID
- BLYNK_TEMPLATE_NAME
- BLYNK_AUTH_TOKEN
- Wi-Fi SSID and password

Never share real credentials in screenshots, public repositories, issue trackers, or logs.

## Data flow
Sensor → MCU firmware → Blynk datastream → cloud → dashboard.
Dashboard switch → datastream → BLYNK_WRITE callback → validated GPIO action.

## Message rate
Do not write continuously in a fast loop. Use BlynkTimer or event-driven updates. For a learning demo, begin around 2–5 seconds unless the sensor/application needs a different cadence. Respect current platform limits.
