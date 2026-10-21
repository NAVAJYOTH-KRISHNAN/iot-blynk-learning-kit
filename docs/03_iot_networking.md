# IoT Networking: Concepts and Choices

## Main building blocks
- **Device/edge:** MCU reads sensors and controls local outputs.
- **Access network:** Wi-Fi, Ethernet, cellular, LoRaWAN, or another link.
- **Cloud/platform:** device identity, message ingestion, storage, rules, and dashboards.
- **Application:** mobile/web UI, alerts, APIs, and data analysis.

## HTTP/REST
Useful for request/response APIs, configuration, and occasional uploads. It is straightforward to debug, but frequent polling can add overhead.

## MQTT
A lightweight publish/subscribe protocol. Devices publish to topics through a broker; subscribers receive messages for topics they subscribe to. It is useful for telemetry and decoupled systems. Blynk has API options documented for integrations; follow its current authentication and topic rules.

## Blynk library vs direct protocols
- Use the Blynk Arduino library for the fastest learning path with virtual-pin datastreams and widgets.
- Explore Blynk.Edgent for supported provisioning workflows.
- Explore direct MQTT/HTTP after the basic integration works.

## Design questions
1. What happens when Wi-Fi is unavailable?
2. Is data buffered locally or discarded?
3. Does the device reconnect automatically?
4. What is the expected update rate?
5. What data is sent, and is it sensitive?
6. What is the safe output state after reboot or network loss?
7. Are local limits/interlocks required for remote actuation?

## Offline-first pattern
- Keep critical sensing and safe control local.
- Treat cloud commands as requests, not guaranteed real-time control.
- Validate incoming values and reject out-of-range commands.
- Reconnect with backoff rather than spinning in a tight loop.
- For production, consider timestamped logs and a policy for stale commands.
