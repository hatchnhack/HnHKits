# HatchnHack ESP AIO AC Switch

---

Hatchnhack ESP AIO AC switch works with ESP-01, ESP-12E/F, Touch, Qiachip RF and has pinout supporting a wide range of relays with coil voltage 5-6VDC.  
It is fully programmable and has a very simple connections, AC in - AC out. It can be used with alexa and smartphone within a local area network for wireless control of a relay. The circuit can support upto 20A load.

### Operating Parameters
1. Input 230 VAC
2. Output 230 VAC
3. RF 433MHz
4. WiFi 2400-2484 MHz IEEE 802.11 b/g/n
5. Operating Voltage - Control 3.3VDC, Relay 5VDC.

---

### The TOP side

<img src="./aio_ac_top.svg" alt="HatchnHack ESP AIO AC switch" width="400"/>

### The BOTTOM side

<img src="./aio_ac_bottom.svg" alt="HatchnHack ESP AIO AC switch" width="400"/>

---

### Using the switch.

This switch requires 230VAC as input to operate. The output's live and neutral wires can be connected to the PTR connectors provide with neutral wire routed using an external wire. 

<img src="./AOI_AC_HnH.png" alt="HatchnHack ESP AIO AC switch" width="600"/>

#### To program the switch
- Power on the switch
- Press and holde the PROG button
- Press and release the RST button while holding the PROG button
- Now the switch is in programming mode
- Use esptool.py or Arduino IDE or any IDE of your choice to program the switch.

---

### Order at HnHCart.com

### BOM
**Qty Value**|**Device**|**Package**|**Parts**|**HnHCart SKU**
:-----:|:-----:|:-----:|:-----:|:-----:
2|AK500/3-H|5mm Pitch|X1, X2|[6B13](https://www.hnhcart.com/products/3-pin-ptr-connector)
6|10K|R1206|R1, R2, R3, R4, R5, R6|[3A28-X](https://www.hnhcart.com/products/10k-ohm-smd-resistor-10-pieces)
1|1K|R1206|R7|[3A28-G](https://www.hnhcart.com/products/1k-ohm-smd-resistor-1206)
2|DTSM-3|DTSM-3|PROG, RST|[6H16](https://www.hnhcart.com/products/micro-smd-push-button-3x6x2-5-smd)
2|GPIO7|M07|SL1, SL2|[6M06](https://www.hnhcart.com/products/header-male-1x10mm)
1|PROG|M04|SL3|[6M06](https://www.hnhcart.com/products/header-male-1x10mm)
1|RED LED|1206|PWR|[3A29-J](https://www.hnhcart.com/products/red-led-smd-1206)
1|HiLink 5V/3W|HLK-PM01|AC2DC|[6F10](https://www.hnhcart.com/products/hi-link-5v-3w-ac-dc-power-convertor)
1|Relay|L90CSDC6V|Relay|[6S39](https://www.hnhcart.com/products/leone-relay-6v-30a)
1|REG1117-3.3V|SOT223|IC2|[2F24](https://www.hnhcart.com/products/reg1117-ic)
2|0.1uF|C1206K|C4, C5|[3A29-E](https://www.hnhcart.com/products/0-1-uf-x7r-50v-smd-capacitor-1206)
2|10uF|C1206K|C3, C6|[3A27-B](https://www.hnhcart.com/products/10-uf-smd-capacitor-10-pieces)
1|1n4007|SMADIODE|D2|[3A30-3E](https://www.hnhcart.com/products/smd-diode-a7-5-pieces)
1|3400 N-MOS|SOT-23|T1| [3A29-T](https://www.hnhcart.com/products/si2302-n-channel-1-25-w-2-5-v-mosfet)
1|ESP-01|2X4|J1|[6EE35](https://www.hnhcart.com/products/esp-01-serial-wifi-wireless-transceiver-module)
1|ESP826612E|ESP8266EX|IC1|[6G15](https://www.hnhcart.com/products/esp-12e-wifi-module)
1|Qiachip|RX-480E|SL2|[6EE34](https://www.hnhcart.com/products/qiachip-wireless-433mhz-rf-module-receiver-remote-control-built-in-learning-code-1527-decoding-4-channel-output)
