Street Light Analysis Kit
=========================

Project Overview
----------------

The Street Light Analysis Kit is an innovative IoT project utilizing the ESP32 microcontroller to analyze street light intensity. This project aims to provide valuable data on street lighting conditions, which can be used for urban planning, energy saving, and ensuring public safety.

Features
--------

*   **Light Intensity Measurement**: Utilizes a light sensor to measure and record the intensity of street lights.
*   **Data Storage**: Records the light intensity data on an SD card for later analysis.
*   **Expandable**: Designed with modularity in mind, allowing for future integration of additional sensors and communication methods.

Hardware Requirements
---------------------

*   ESP32 Microcontroller
*   Light Sensor (e.g., photoresistor)
*   SD Card Module
*   (Other components as per project expansion)

Software Requirements
---------------------

*   Arduino IDE or ESP-IDF
*   Necessary libraries for interfacing with the Light Sensor and SD Card

Installation
------------

1.  Clone the repository to your local machine.
2.  Open the project in Arduino IDE or your preferred ESP32 development environment.
3.  Install the required libraries through the Library Manager in Arduino IDE.
4.  Connect the ESP32 to your computer and select the appropriate board and COM port in your IDE.
5.  Upload the code to your ESP32.

Usage
-----

*   Ensure all hardware components are correctly connected.
*   Power up the ESP32.
*   The device will automatically start measuring light intensity and recording the data to the SD card.

Acknowledgments
---------------

*   Thanks to [Electronic Wings](https://www.electronicwings.com/) for their invaluable resources on ESP32.
