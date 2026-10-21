# Firmware Patterns for Reliable IoT

## Readable structure
1. Configuration/constants
2. Pin definitions
3. State variables
4. Setup: initialize serial, GPIO, sensor, network/cloud
5. Timed tasks: sensor sampling, telemetry, health status
6. Callbacks: incoming datastream values
7. Safe-state and error handling

## Use timers
The main loop should process the Blynk library frequently, while telemetry is sent on a controlled interval. Use BlynkTimer or an equivalent scheduler.

## Validate commands
- Accept only expected values.
- Enforce allowed ranges.
- Do not map untrusted values to arbitrary GPIOs or motor power.
- Use local physical interlocks for systems where failure could cause harm.

## Reconnection and failures
- Monitor serial output during development.
- Distinguish sensor failure from network failure.
- Avoid blocking delays that prevent cloud processing.
- For production, define retry/backoff behavior, stale-data handling, and safe boot defaults.

## Secrets
- Keep secrets in a local configuration file that is not committed, or use IDE/build secret mechanisms.
- Rotate a token if exposed.
- Never publish Wi-Fi credentials in example screenshots or logs.
