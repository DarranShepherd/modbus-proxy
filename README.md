Modbus Proxy
============

This repository contains the PCB design for a simple circuit connecting an ESP32 C3 Mini, through an RS485 transceiver to allow it to communicate with other Modbus devices.
It also contains the firmware for the ESP32 to expose a REST API allowing other devices to communicate through this device.
The firmware can also be configured to periodically read registers on a Modbus device and send them to an MQTT broker - this is designed to be used to read an Eastron SDM120 power meter and push the power readings to an OpenEnergyMonitor EmonCMS.

Running in a Dev Container
--------------------------

From https://docs.espressif.com/projects/vscode-esp-idf-extension/en/latest/additionalfeatures/docker-container.html#id1
```
usbipd list
usbipd bind --busid <BUSID>
usbipd attach --wsl --busid <BUSID> --auto-attach
```

Running Mosquitto MQTT broker
-----------------------------

Run `mosquitto.ps1` which runs
```
docker run -it -p 1883:1883 -v "$pwd/mosquitto/config:/mosquitto/config" -v "$pwd/mosquitto/data:/mosquitto/data" -v "$pwd/mosquitto/log:/mosquitto/log" eclipse-mosquitto
```