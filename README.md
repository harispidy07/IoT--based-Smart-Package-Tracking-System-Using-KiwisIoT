# IoT-Based Smart Package Tracking System Using KiwisIoT

## Project Overview

This project is designed to monitor and track package conditions using IoT technology. An ESP8266 NodeMCU collects tracking information from connected sensors and transmits the data to the KiwisIoT platform for remote monitoring. It helps improve package visibility and supports smarter logistics and delivery management.

## Hardware Components

- ESP8266 NodeMCU
- Tracking Sensors
- Jumper Wires
- Power Supply

## Software Requirements

- Arduino IDE
- ESP8266 Board Package
- KiwisIoT Arduino Library

## Circuit Connections

Sensor connections depend on the hardware configuration used in the project.

## Working Principle

The connected sensors collect package-related information and send the readings to the ESP8266 NodeMCU. The controller processes the data and transmits it to the KiwisIoT platform, allowing users to monitor package information remotely through an IoT dashboard.

## KiwisIoT Dashboard

The dashboard displays package monitoring information for remote tracking.

| Data            | Description                    |
| --------------- | ------------------------------ |
| Package Data    | Collected sensor readings      |
| Tracking Status | Package monitoring information |
| Remote Access   | Monitoring through KiwisIoT    |

## Configuration

Update your Wi-Fi credentials and KiwisIoT Topic ID in the Arduino code:

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";
const char* topic = "YOUR_TOPIC_ID";
```

Upload the code to the NodeMCU ESP8266 and monitor package information through the KiwisIoT dashboard.

## Applications

- Smart package monitoring
- Logistics management
- Delivery tracking
- Package condition monitoring
- Smart supply chain systems

## Project Reference

**Hackster.io Project:**  
[https://www.hackster.io/harispidy07/iot-based-smart-package-tracking-system-using-kiwisiot-af66d4](https://www.hackster.io/harispidy07/iot-based-smart-package-tracking-system-using-kiwisiot-af66d4)

**KiwisIoT Platform:**  
[https://kiwisiot.com/](https://kiwisiot.com/)

**KiwisIoT GitHub Repository:**  
[https://github.com/Kiwistron/KiwisIoT-Projects](https://github.com/Kiwistron/KiwisIoT-Projects)

## Author

**Hariprasath S**

GitHub: [https://github.com/harispidy07](https://github.com/harispidy07)

---

_Built using ESP8266 and KiwisIoT for smart package monitoring and tracking._
