# Lab 2 — DHT11 Telemetry to Blynk

## Goal
Send temperature and humidity readings to a dashboard.

## Wiring
DHT module VCC → suitable supply, GND → GND, DATA → GPIO 4. Confirm the module pinout and logic level.

## Cloud setup
- V0: Temperature, Double, °C, suggested range 0–60.
- V1: Humidity, Double, %, suggested range 0–100.
- V2: LED Control, Integer/Enum, 0–1.
- Bind value widgets/gauges to V0 and V1; bind switch to V2.

## Procedure
1. Test DHT11 locally first and confirm valid serial readings.
2. Fill in Blynk and Wi-Fi placeholders.
3. Upload firmware/esp32_blynk_dht11/esp32_blynk_dht11.ino.
4. Check device online status and dashboard values.
5. Test sensor disconnection and verify invalid readings are skipped.

## Pass criteria
- Valid readings appear periodically.
- Sensor failures are logged and do not publish NaN.
- LED switch still works during telemetry.
