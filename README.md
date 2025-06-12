Modbus Proxy
============

This repository contains the PCB design for a simple circuit connecting an ESP32 C3 Mini, through an RS485 transceiver to allow it to communicate with other Modbus devices.
It also contains the firmware for the ESP32 to expose a REST API allowing other devices to communicate through this device.
The firmware can also be configured to periodically read registers on a Modbus device and send them to an MQTT broker - this is designed to be used to read an Eastron SDM120 power meter and push the power readings to an OpenEnergyMonitor EmonCMS.