# IoT Learning Roadmap

## Outcomes
By the end, you should be able to explain an IoT system from sensor to user interface; test sensors locally; write readable embedded firmware; connect ESP32/ESP8266 to Blynk IoT; configure datastreams and dashboards; document system topologies; and validate failure behavior.

## Six-week path

### Week 1 — Electronics and MCU basics
Study voltage/current/resistance, 3.3 V logic, GPIO, pull-ups, ADC, PWM, I2C, SPI, and UART.
**Lab:** blink an LED, read a button, log values to Serial Monitor.
**Deliverable:** pin map and standalone test sketch.

### Week 2 — Sensors and firmware structure
Read a sensor without cloud services. Learn units, calibration, sampling intervals, invalid readings, and serial diagnostics.
**Lab:** DHT11 or another sensor you own.
**Deliverable:** stable sensor sketch and wiring notes.

### Week 3 — Networking and cloud concepts
Learn Wi-Fi station mode, IP/DHCP, DNS, TLS concepts, client/server, HTTP APIs, and MQTT publish/subscribe.
**Lab:** connect to Wi-Fi and report connection state.
**Deliverable:** network topology and connection checklist.

### Week 4 — Blynk integration
Create a template, datastreams, device, and dashboard. Send sensor data and receive a dashboard command.
**Lab:** remote LED control plus telemetry.
**Deliverable:** dashboard, screenshots with secrets hidden, and test record.

### Week 5 — Reliability and security
Use timers, handle disconnects, validate control values, protect credentials, and define safe boot behavior.
**Lab:** disconnect Wi-Fi, reboot, and test recovery.
**Deliverable:** failure-mode table and debug log.

### Week 6 — Capstone
Choose a room environment monitor, plant/soil monitor, water-tank level demonstrator, smart Wi-Fi guardian, or isolated energy telemetry demonstrator.
**Deliverable:** block diagram, wiring topology, firmware, dashboard, bill of materials, test plan, and demo.

## Study loop
1. Read one concept.
2. Build the smallest test.
3. Confirm behavior in Serial Monitor.
4. Integrate one new layer.
5. Record what worked, what failed, and the next test.

## Assessment rubric (100 points)
- Hardware and wiring correctness: 15
- Standalone sensor/actuator validation: 15
- Firmware quality: 15
- Blynk template/datastream/dashboard: 20
- Network/data-flow documentation: 10
- Fault handling and recovery: 10
- Security and safety: 10
- Reproducible setup instructions: 5
