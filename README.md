<a name="oben"></a>

<div align="center">

|[:skull:ISSUE](https://github.com/frankyhub/MQTT/issues?q=is%3Aissue)|[:speech_balloon: Forum /Discussion](https://github.com/frankyhub/MQTT/discussions)|[:grey_question:WiKi](https://github.com/frankyhub/MQTT/wiki)||
|--|--|--|--|
| | | | |
|![Static Badge](https://img.shields.io/badge/RepoNr.:-%2062-blue)|<a href="https://github.com/frankyhub/MQTT/issues">![GitHub issues](https://img.shields.io/github/issues/frankyhub/MQTT)![GitHub closed issues](https://img.shields.io/github/issues-closed/frankyhub/MQTT)|<a href="https://github.com/frankyhub/MQTT/discussions">![GitHub Discussions](https://img.shields.io/github/discussions/frankyhub/MQTT)|<a href="https://github.com/frankyhub/MQTT/releases">![GitHub release (with filter)](https://img.shields.io/github/v/release/frankyhub/MQTT)|
|![GitHub Created At](https://img.shields.io/github/created-at/frankyhub/MQTT)| <a href="https://github.com/frankyhub/MQTT/pulse" alt="Activity"><img src="https://img.shields.io/github/commit-activity/m/badges/shields" />| <a href="https://github.com/frankyhub/MQTT/graphs/traffic"><img alt="ViewCount" src="https://views.whatilearened.today/views/github/frankyhub/github-clone-count-badge.svg">  |<a href="https://github.com/frankyhub?tab=stars"> ![GitHub User's stars](https://img.shields.io/github/stars/frankyhub)|
</div>



# MQTT
Message Queuing Telemetry Transport

## Story

Das ist ein Repo mit einem Raspberry PI und zwei Wemos D1 Mini für die Anzeige von zwei Dashboards mit MQTT. Auf dem Raspi ist Node-RED und der MQTT Broker Mosquitto installiert. Der erste Wemos D1 Mini ist mit einem BME280 verbunden und zeigt die Temperatur, die Luftfeuchte und den Luftdruck an. Für das zweite Dashboard ist am zweiten Wemos D1 Mini ist ein LDR, ein Bewegungsmelder, eine LED, ein Relais und ein Dallas Temperatursensor installiert. Beide Dashboards werden mit der Node-RED IP-Adresse aufgerufen.

![Bild](pic/ESP1.png)


## Hardware

| Anzahl | Bezeichnung | 
| -------- | -------- | 
| 1  | Raspberry PI   |
|  --- |   --- |

| Anzahl | Bezeichnung | 
| -------- | -------- | 
|   | Microcontroller 1   |
| 1  |  Wemos D1 Mini  |
| 1  |  BME280  |
| ---  | ---   |

| Anzahl | Bezeichnung | 
| -------- | -------- | 
|   | Microcontroller 2   |
| 1  |  Wemos D1 Mini  |
| 1  |  LED 5mm  |
| 1  |  330R  |
|  2 |   10kR |
|  1 |  DS18B20  |
| 1  | Mini AM312 PIR   |
| 1  | LDR   |
| 1  |  5V/230V Relais  |
| ---  | ---   |




## Software

Raspi Programme
+ Node-RED
+ MQTT Broker Mosquitto
  
Wemos-Programme
+ Programm 1 für Node 1
+ Programm 2 für Node 2
  
Node-RED Flows für den Import in Node-RED
+ Flow 1: Temperatur, Luftfeuchte und Luftdruck
+ Flow 2: Relais-Switch, PIR-Status, LDR und Temperatur-Kurve

## Installation

+ Auf dem Raspi Node-RED und Mosquitto installieren und starten.
+ Die beiden Flows in Node-RED importieren und mit Mosquitto verbinden (Deploy-Button).
+ Die C++ Programme in die Arduino IDE kopieren und in die beiden Wemos D1 Minis laden.

Wemos D1 Mini 1
+ Den BME280 an 3,3V und GND anschließen. SDA an D2, SDL an D1.

Wemos D1 Mini 2
+ LDR -> A0
+ Relais -> D0
+ PIR-> D1
+ DS18B20-> D2
+ LED -> D6


![Bild](pic/wemos2.jpg)

## Linux-Befehle

```Linux

Mosquitto Broker installieren:
pi@franky:~ $ sudo apt update
pi@franky:~ $ sudo apt install -y mosquitto mosquitto-clients



Node-RED installieren:
pi@franky:~ $ bash <(curl -sL https://raw.githubusercontent.com/node-red/raspbian-deb-package/master/resources/update-nodejs-and-nodered)

Restart Pi:
pi@franky:~ $ sudo reboot

Mosquitto Start:
pi@franky:~ $ sudo service mosquitto start

Test:
http://xxx:1880
z.B:
http://192.168.1.104:1880

Node-RED Dashboard aufrufen:
http://192.168.1.104:1880/ui


==================================================================


Linux-Befehle

Zeige Arbeitsverzeichnis:
pifranky~ $ pwd

Arbeitsverzeichnis auflisten:
pifranky~ $ ls

Neuen Ordner erstellen:
pifranky~ $ mkdir NewFolder
pifranky~ $ ls

Ordner-Verzeichnis nach oben:
pifranky~/NewFolder $ cd .. 
pifranky~ $ ls 

Neue Datei erstellen:
pifranky~/NewFolder $ touch NewFile.txt
pifranky~/NewFolder $ ls

Datei kopieren mit neuem Namen:
pifranky~/NewFolder $ cp NewFile.txt OtherFile.txt
pifranky~/NewFolder $ ls

Datei loeschen:
pifranky~/NewFolder $ rm NewFile.txt
pifranky~/NewFolder $ ls

Datei verschieben:
pifranky~/NewFolder $ mv OtherFile.txt /home/pi
pifranky~/NewFolder $ cd ..
pifranky~/NewFolder $ ls

NANO-Editor starten:
pifranky~ $ cd
pifranky~ $ nano OtherFile.txt

Mit Strg+G das HilfemenÃ¼ aufzurufen und mit den Pfeiltasten nach unten zu scrollen.
Mit Strg+X NANO beenden und Y fÃ¼r speichern (oder N fÃ¼r verwerfen)

Paketversionen aktualisieren:
pifranky~ $ sudo apt-get update

Software installieren:
pifranky~ $ sudo apt-get install <SOFTWARE_NAME>

Software (Python) starten:
pifranky~ $ python

Software loeschen:
pifranky~ $ sudo apt-get remove <SOFTWARE_NAME>

Konfigurationstool Ã¶ffnen:
pifranky~ $ sudo raspi-config

Raspberry Pi herunterfahren:
pifranky~ $ sudo poweroff

Raspberry Pi Neustart:
pifranky~ $ sudo reboot

==================================================================

WS2812B RGB LED Strip installieren

pi@raspberry:~ $ curl -sS get.pimoroni.com/unicornhat | bash

pi@raspberry:~ $ node-red-stop
pi@raspberry:~ $ cd ~/.node-red
pi@raspberry:~/.node-red $ npm install node-red-node-pi-neopixel

pi@raspberry:~ $ node-red-start

==================================================================

CodeLite installieren (Raspberry Pi C++ Entwicklungsumgebung)
sudo apt-get install codelite

C++ Compiler nachinstallieren:
sudo apt-get install build-essential

==================================================================
```


## Flow 1
```json
[
    {
        "id": "2b566407.d5918c",
        "type": "tab",
        "label": "Flow 1",
        "disabled": false,
        "info": ""
    },
    {
        "id": "5a45b8da.52b0d8",
        "type": "mqtt in",
        "z": "2b566407.d5918c",
        "name": "",
        "topic": "esp/bme280/temperature",
        "qos": "1",
        "datatype": "auto",
        "broker": "6f6ed074.6ae5f",
        "x": 270,
        "y": 120,
        "wires": [
            [
                "3042e15e.80a4ee"
            ]
        ]
    },
    {
        "id": "3042e15e.80a4ee",
        "type": "ui_gauge",
        "z": "2b566407.d5918c",
        "name": "",
        "group": "37de8fe8.46846",
        "order": 2,
        "width": 0,
        "height": 0,
        "gtype": "gage",
        "title": "Temperatur",
        "label": "ÂºC",
        "format": "{{value}}",
        "min": 0,
        "max": "40",
        "colors": [
            "#00b500",
            "#f7df09",
            "#ca3838"
        ],
        "seg1": "",
        "seg2": "",
        "x": 550,
        "y": 120,
        "wires": []
    },
    {
        "id": "8ff168f0.0c74a8",
        "type": "mqtt in",
        "z": "2b566407.d5918c",
        "name": "",
        "topic": "esp/bme280/humidity",
        "qos": "1",
        "datatype": "auto",
        "broker": "8db3fac0.99dd48",
        "x": 260,
        "y": 200,
        "wires": [
            [
                "29251f29.6687c"
            ]
        ]
    },
    {
        "id": "29251f29.6687c",
        "type": "ui_gauge",
        "z": "2b566407.d5918c",
        "name": "",
        "group": "37de8fe8.46846",
        "order": 2,
        "width": 0,
        "height": 0,
        "gtype": "gage",
        "title": "Luftfeuchte",
        "label": "%",
        "format": "{{value}}",
        "min": "10",
        "max": "80",
        "colors": [
            "#53a4e6",
            "#1d78a9",
            "#4e38c9"
        ],
        "seg1": "",
        "seg2": "",
        "x": 550,
        "y": 200,
        "wires": []
    },
    {
        "id": "294f7eea.999d72",
        "type": "mqtt in",
        "z": "2b566407.d5918c",
        "name": "",
        "topic": "esp/bme280/pressure",
        "qos": "1",
        "datatype": "auto",
        "broker": "8db3fac0.99dd48",
        "x": 260,
        "y": 280,
        "wires": [
            [
                "58610d70.bb9764"
            ]
        ]
    },
    {
        "id": "58610d70.bb9764",
        "type": "ui_gauge",
        "z": "2b566407.d5918c",
        "name": "",
        "group": "37de8fe8.46846",
        "order": 4,
        "width": 0,
        "height": 0,
        "gtype": "gage",
        "title": "Luftdruck",
        "label": "hPa",
        "format": "{{value}}",
        "min": 0,
        "max": "1200",
        "colors": [
            "#b366ff",
            "#8000ff",
            "#440088"
        ],
        "seg1": "",
        "seg2": "",
        "x": 540,
        "y": 280,
        "wires": []
    },
    {
        "id": "6f6ed074.6ae5f",
        "type": "mqtt-broker",
        "name": "",
        "broker": "192.168.1.110",
        "port": "1883",
        "clientid": "",
        "usetls": false,
        "compatmode": false,
        "keepalive": "60",
        "cleansession": true,
        "birthTopic": "",
        "birthQos": "0",
        "birthPayload": "",
        "closeTopic": "",
        "closeQos": "0",
        "closePayload": "",
        "willTopic": "",
        "willQos": "0",
        "willPayload": ""
    },
    {
        "id": "37de8fe8.46846",
        "type": "ui_group",
        "name": "Frankyhub MQTT BME280",
        "tab": "53b8c8f9.cfbe48",
        "order": 1,
        "disp": true,
        "width": "6",
        "collapse": false
    },
    {
        "id": "8db3fac0.99dd48",
        "type": "mqtt-broker",
        "name": "",
        "broker": "192.168.1.110",
        "port": "1883",
        "clientid": "",
        "usetls": false,
        "compatmode": false,
        "keepalive": "60",
        "cleansession": true,
        "birthTopic": "",
        "birthQos": "0",
        "birthPayload": "",
        "closeTopic": "",
        "closeQos": "0",
        "closePayload": "",
        "willTopic": "",
        "willQos": "0",
        "willPayload": ""
    },
    {
        "id": "53b8c8f9.cfbe48",
        "type": "ui_tab",
        "name": "Home",
        "icon": "dashboard",
        "order": 2,
        "disabled": false,
        "hidden": false
    }
]

```

## Flow 2
```json
[
    {
        "id": "94cf8e9e.4c4dc",
        "type": "tab",
        "label": "Flow 2",
        "disabled": false,
        "info": ""
    },
    {
        "id": "c78da7aa.0ef3e8",
        "type": "mqtt in",
        "z": "94cf8e9e.4c4dc",
        "name": "",
        "topic": "esp8266/temperature",
        "qos": "2",
        "datatype": "auto",
        "broker": "6f6ed074.6ae5f",
        "x": 280,
        "y": 300,
        "wires": [
            [
                "7a6de433.20e89c"
            ]
        ]
    },
    {
        "id": "eb30e74b.9ca058",
        "type": "mqtt out",
        "z": "94cf8e9e.4c4dc",
        "name": "",
        "topic": "esp8266/output",
        "qos": "",
        "retain": "",
        "broker": "8db3fac0.99dd48",
        "x": 480,
        "y": 60,
        "wires": []
    },
    {
        "id": "e8ad8388.38fc9",
        "type": "ui_switch",
        "z": "94cf8e9e.4c4dc",
        "name": "",
        "label": "Output",
        "group": "9a1861f8.88c6d",
        "order": 0,
        "width": 0,
        "height": 0,
        "passthru": true,
        "decouple": "false",
        "topic": "",
        "style": "",
        "onvalue": "on",
        "onvalueType": "str",
        "onicon": "",
        "oncolor": "",
        "offvalue": "off",
        "offvalueType": "str",
        "officon": "",
        "offcolor": "",
        "x": 230,
        "y": 60,
        "wires": [
            [
                "eb30e74b.9ca058"
            ]
        ]
    },
    {
        "id": "92c8e523.183738",
        "type": "mqtt in",
        "z": "94cf8e9e.4c4dc",
        "name": "",
        "topic": "esp8266/ldr",
        "qos": "2",
        "datatype": "auto",
        "broker": "6f6ed074.6ae5f",
        "x": 250,
        "y": 220,
        "wires": [
            [
                "fd29e914.9d46e8"
            ]
        ]
    },
    {
        "id": "e96d7d26.26dfb",
        "type": "mqtt in",
        "z": "94cf8e9e.4c4dc",
        "name": "",
        "topic": "esp8266/motion",
        "qos": "2",
        "datatype": "auto",
        "broker": "8db3fac0.99dd48",
        "x": 260,
        "y": 140,
        "wires": [
            [
                "9e0997cb.ba5aa8"
            ]
        ]
    },
    {
        "id": "9e0997cb.ba5aa8",
        "type": "ui_text",
        "z": "94cf8e9e.4c4dc",
        "group": "9a1861f8.88c6d",
        "order": 0,
        "width": 0,
        "height": 0,
        "name": "",
        "label": "PIR Status:",
        "format": "{{msg.payload}}",
        "layout": "row-spread",
        "x": 490,
        "y": 140,
        "wires": []
    },
    {
        "id": "fd29e914.9d46e8",
        "type": "ui_gauge",
        "z": "94cf8e9e.4c4dc",
        "name": "",
        "group": "9a1861f8.88c6d",
        "order": 0,
        "width": 0,
        "height": 0,
        "gtype": "gage",
        "title": "LDR",
        "label": "Luminosity",
        "format": "{{value}}",
        "min": 0,
        "max": "1023",
        "colors": [
            "#00b500",
            "#e6e600",
            "#ca3838"
        ],
        "seg1": "",
        "seg2": "",
        "x": 510,
        "y": 220,
        "wires": []
    },
    {
        "id": "7a6de433.20e89c",
        "type": "ui_chart",
        "z": "94cf8e9e.4c4dc",
        "name": "",
        "group": "9a1861f8.88c6d",
        "order": 0,
        "width": 0,
        "height": 0,
        "label": "Temperatur",
        "chartType": "line",
        "legend": "false",
        "xformat": "HH:mm:ss",
        "interpolate": "linear",
        "nodata": "",
        "dot": false,
        "ymin": "",
        "ymax": "",
        "removeOlder": 1,
        "removeOlderPoints": "",
        "removeOlderUnit": "3600",
        "cutout": 0,
        "useOneColor": false,
        "useUTC": false,
        "colors": [
            "#1f77b4",
            "#aec7e8",
            "#ff7f0e",
            "#2ca02c",
            "#98df8a",
            "#d62728",
            "#ff9896",
            "#9467bd",
            "#c5b0d5"
        ],
        "outputs": 1,
        "useDifferentColor": false,
        "x": 490,
        "y": 300,
        "wires": [
            []
        ]
    },
    {
        "id": "6f6ed074.6ae5f",
        "type": "mqtt-broker",
        "name": "",
        "broker": "192.168.1.110",
        "port": "1883",
        "clientid": "",
        "usetls": false,
        "compatmode": false,
        "keepalive": "60",
        "cleansession": true,
        "birthTopic": "",
        "birthQos": "0",
        "birthPayload": "",
        "closeTopic": "",
        "closeQos": "0",
        "closePayload": "",
        "willTopic": "",
        "willQos": "0",
        "willPayload": ""
    },
    {
        "id": "8db3fac0.99dd48",
        "type": "mqtt-broker",
        "name": "",
        "broker": "192.168.1.110",
        "port": "1883",
        "clientid": "",
        "usetls": false,
        "compatmode": false,
        "keepalive": "60",
        "cleansession": true,
        "birthTopic": "",
        "birthQos": "0",
        "birthPayload": "",
        "closeTopic": "",
        "closeQos": "0",
        "closePayload": "",
        "willTopic": "",
        "willQos": "0",
        "willPayload": ""
    },
    {
        "id": "9a1861f8.88c6d",
        "type": "ui_group",
        "name": "Frankyhub Multi-Dashboard",
        "tab": "897e8f0f.c94fb",
        "order": 1,
        "disp": true,
        "width": "6",
        "collapse": false
    },
    {
        "id": "897e8f0f.c94fb",
        "type": "ui_tab",
        "name": "Frankyhub MQTT Dashboard",
        "icon": "dashboard",
        "disabled": false,
        "hidden": false
    }
]
```

Dashboard 1 (Node-RED IP-Adresse/ui)

![Bild](pic/Dashboard1.png)

Serieller Monitor 1

![Bild](pic/Seriell1.png)

Node-RED Flow 1

![Bild](pic/node-red1.png)

Dashboard 2

![Bild](pic/Dashboard2.png)

Serieller Monitor 2

![Bild](pic/Seriell2.png)

Node-RED Flow 2

![Bild](pic/node-red2.png)

Einfache Erweiterung von Node-RED um die Funktion "Licht"

![Bild](pic/node-red3.png)

Erweiterung der Funktion "Licht" im Dashboard 2

![Bild](pic/Dashboard4.png)

Erweiterung von Node-RED um die Funktion "ESP1" (Switch D5 mit Debug-Funktion)

![Bild](pic/node-red4.png)

Schalten und dimmen mit dem "ESP1" Dashboard

![Bild](pic/ESP1.png)

Erweiterung von Node-RED um die Funktion "LED-STRIPE"

![Bild](pic/led-stripe.png)

![Bild](pic/ledstripe.png)



---

<div style="position:absolute; left:2cm; ">   
<ol class="breadcrumb" style="border-top: 2px solid black;border-bottom:2px solid black; height: 45px; width: 900px;"> <p align="center"><a href="#oben">nach oben</a></p></ol>
</div>  

---
