# Toolchain and Hardware Setup

## Recommended starter kit
- ESP32 DevKit board (primary platform)
- USB data cable
- Breadboard and jumper wires
- LED plus 220–1,000 ohm resistor
- Pushbutton
- DHT11 module or an I2C sensor
- Optional low-voltage relay module for a low-voltage demo
- Multimeter

## Software
1. Install Arduino IDE 2.x: https://www.arduino.cc/en/software
2. Install the ESP32 board package using the current official Espressif guide.
3. For ESP8266, install the official ESP8266 Arduino core using its current guide.
4. Install the Blynk library from Arduino Library Manager.
5. Install any library required by your exact sensor.
6. Select the correct board and serial port; use a known-good USB data cable.

References:
- ESP32 Arduino core: https://docs.espressif.com/projects/arduino-esp32/en/latest/
- ESP8266 Arduino core: https://arduino-esp8266.readthedocs.io/

## First upload
1. Upload Blink or a serial-print sketch.
2. Open Serial Monitor at the configured baud rate.
3. Verify board selection and port.
4. If upload fails, check cable, port, board package, boot mode, and driver before changing code.

## ESP32 LED wiring
- GPIO 2 → resistor → LED anode; LED cathode → GND.
- Board variants differ; GPIO 2 may not be the onboard LED pin. Use an external LED if uncertain.
- Never connect an LED without a current-limiting resistor.

## DHT11 wiring
Verify labels and module datasheet. Typical modules expose VCC, GND, DATA.
- VCC → voltage supported by the module; 3.3 V is a conservative choice for 3.3 V logic.
- GND → GND.
- DATA → GPIO 4.
- Bare sensors may need a pull-up; some breakout modules already include one.
- Ensure DATA is not pulled up to 5 V.

## Power rules
- Share ground between MCU and low-voltage modules unless the interface is isolated.
- Do not power a motor or relay coil from a GPIO.
- Use a correctly rated driver and supply for loads.
- Verify current budget and regulator limits before connecting peripherals.
