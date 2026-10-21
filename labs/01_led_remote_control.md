# Lab 1 — Remote LED Control with Blynk

## Goal
Switch an LED from the Blynk mobile or web dashboard.

## Hardware
ESP32, LED, 220–1,000 ohm resistor, jumper wires, USB cable.

## Wiring
GPIO 2 → resistor → LED anode; LED cathode → GND. Verify the pin for your board.

## Cloud setup
1. Create a template for ESP32 + Wi-Fi.
2. Add a Virtual Pin datastream V0, integer/enum with values 0 and 1.
3. Create a device and copy template ID/name and device token.
4. Add a switch widget bound to V0.
5. Fill credentials in firmware/esp32_blynk_led/esp32_blynk_led.ino.
6. Upload, open Serial Monitor, and test both switch states.

## Pass criteria
- Device appears online.
- Switch ON lights LED; OFF turns it off.
- Power cycle results in a known safe output state.
- Credentials are not visible in screenshots or public code.

## Troubleshooting
Check datastream pin, widget binding, token, Wi-Fi credentials, board pin, LED polarity, and serial logs.
