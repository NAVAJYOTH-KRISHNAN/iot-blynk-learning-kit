# Troubleshooting Guide

| Symptom | Likely causes | Checks |
|---|---|---|
| Board not detected | Cable, driver, port | Try a data cable, inspect device manager, select correct port |
| Upload fails | Wrong board/port, boot mode, power | Confirm board package, close serial monitor if needed, check boot instructions |
| Wi-Fi never connects | Credentials, 2.4 GHz setting, weak signal | Verify credentials and router settings; ESP32/ESP8266 generally use 2.4 GHz Wi-Fi |
| Blynk device offline | Wrong template/token or Wi-Fi failure | Recheck credentials and serial output |
| Dashboard does not change | Pin/type/widget mismatch | Compare datastream and firmware mappings |
| Switch changes UI, not GPIO | Callback or pin mismatch | Check BLYNK_WRITE(Vx), board pinout, and logic polarity |
| Sensor invalid/NaN | Wiring, library, timing, unsupported sensor | Test sensor standalone and verify exact model |
| Network/cloud issues | Excessive updates or blocking code | Add timers, reduce message rate, remove long blocking delays |
| ESP32 resets | Power instability, short, high current load | Disconnect loads, inspect supply/wiring and reset reason |
| Output reversed | Active-low module/LED | Check the module schematic and logic polarity |

## Debug order
1. Test power and wiring.
2. Test sensor/actuator without cloud.
3. Test Wi-Fi independently.
4. Confirm Blynk credentials and device status.
5. Confirm datastream/widget mapping.
6. Test callbacks and GPIO behavior.
7. Add reliability logic only after baseline works.
