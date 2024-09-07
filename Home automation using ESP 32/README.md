
![Logo](https://user-images.githubusercontent.com/80714882/234116124-5bbd7e92-5432-42f2-bb0e-574ed005aee8.png)


# Smart Home automation

This ESP8266-based home automation project that leverages Blynk for remote control and monitoring, a DHT sensor for temperature and humidity readings, and two relays for managing external devices. By combining these elements, you can create a versatile system for automating tasks and monitoring environmental conditions within your smart home environment.

## Badges

Add badges from somewhere like: [shields.io](https://shields.io/)

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)
[![GPLv3 License](https://img.shields.io/badge/License-GPL%20v3-yellow.svg)](https://opensource.org/licenses/)
[![AGPL License](https://img.shields.io/badge/license-AGPL-blue.svg)](http://www.gnu.org/licenses/agpl-3.0)


## Features

- Connects to your WiFi network.
- Reads temperature and humidity from a DHT11 sensor.
- Sends sensor data to Blynk app for visualization.
- Controls two relays (Relay 3 and Relay 4) via Blynk virtual buttons.
- Implements ultrasonic distance measurement using an HC-SR04 sensor.
- Controls Relay 1 based on the measured distance.
- Allows setting a temperature threshold for controlling Relay 2 via a Blynk virtual slider.


## Hardware requirements

- ESP8266 development board (e.g., NodeMCU)
- DHT11 sensor
- HC-SR04 senso
- Relays 
- Resistors (values may vary depending on relay specifications)
- Jumper wires
- Breadboard (optional)
## Software requirements

- Arduino IDE
- ESP8266 Board package (if not already installed)
- Blynk app

- DHT library (https://learn.adafruit.com/dht/downloads)
- Blynk library for ESP8266 (https://docs.blynk.io/en/blynk-library-firmware-api/installation/install-blynk-library-in-arduino-ide)
## Setup

- Install the ESP8266 Board package and Blynk and DHT libraries in the Arduino IDE
- Connect the DHT sensor, relays, and HC-SR04 sensor  to your ESP8266 board according to the wiring diagram (not included in this file)
- Configure the WiFi credentials (ssid and pass) in the code
- Obtain your Blynk auth token from the Blynk app and set it in the BLYNK_AUTH_TOKEN variable
- In the Blynk app, create a new project and add the following widgets:
- Two virtual gauges for temperature (V2) and humidity (V3)
- Two virtual buttons for controlling Relay 3 (V7) and Relay 4 (V8)
- One virtual slider for setting the temperature threshold (V5) 
- One virtual gauge for displaying distance (V0) 
- Upload the code to your ESP8266 board

## Notes

- You can customize the code to add more features and functionalities.
- Ensure proper connections and component ratings before powering up the circuit.
- Refer to the Blynk documentation for detailed information on creating and using widgets in the app.

## Additional Resources:

- ESP8266 documentation: https://docs.espressif.com/projects/esp-idf/en/stable/esp32/index.html
- Blynk documentation: https://docs.blynk.io/en
- DHT library documentation: [https://learn.adafruit.com/dht/overview](https://learn.adafruit.com