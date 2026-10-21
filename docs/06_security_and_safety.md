# IoT Security and Safety Basics

## Minimum security baseline
- Use unique credentials per device where possible.
- Never hardcode production secrets in public repositories.
- Use supported secure connections; do not disable TLS verification as a workaround.
- Keep firmware and libraries updated.
- Validate every remote command.
- Restrict access to dashboards and device controls.
- Avoid exposing credentials in serial logs.
- Document credential rotation/revocation.

## Physical safety
- ESP32/ESP8266 pins are logic outputs, not power drivers.
- Use rated driver circuits for relays, motors, pumps, and solenoids.
- Mains wiring requires qualified design, enclosure, fusing, strain relief, isolation, and compliance with applicable rules; it is outside this starter kit.
- Cloud connectivity can fail or be delayed. Keep safety-critical behavior local.
- Define safe states for reset, sensor fault, and network loss.
