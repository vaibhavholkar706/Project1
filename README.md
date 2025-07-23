{
  "version": 1,
  "author": "Vaibhav Holkar",
  "editor": "wokwi",
  "parts": [
    { "type": "wokwi-arduino-uno", "id": "uno", "top": 10.2, "left": 18.6, "attrs": {} },
    { "type": "wokwi-dht22", "id": "dht1", "top": -86.1, "left": -101.4, "attrs": {} },
    {
      "type": "wokwi-led",
      "id": "led1",
      "top": -70.8,
      "left": 176.6,
      "attrs": { "color": "red" }
    },
    {
      "type": "wokwi-led",
      "id": "led2",
      "top": -70.8,
      "left": 224.6,
      "attrs": { "color": "green" }
    },
    {
      "type": "wokwi-resistor",
      "id": "r1",
      "top": -63.25,
      "left": 38.4,
      "attrs": { "value": "10000" }
    },
    {
      "type": "wokwi-buzzer",
      "id": "bz1",
      "top": 204,
      "left": -84.6,
      "attrs": { "volume": "0.1" }
    },
    {
      "type": "wokwi-resistor",
      "id": "r2",
      "top": -82.45,
      "left": 115.2,
      "attrs": { "value": "220" }
    }
  ],
  "connections": [
    [ "dht1:VCC", "uno:5V", "red", [ "v0" ] ],
    [ "dht1:GND", "uno:GND.1", "black", [ "v0" ] ],
    [ "dht1:SDA", "r1:1", "green", [ "v0" ] ],
    [ "r1:2", "uno:5V", "green", [ "v0" ] ],
    [ "dht1:SDA", "uno:2", "green", [ "v0" ] ],
    [ "led1:A", "uno:3", "green", [ "v0" ] ],
    [ "led1:C", "r2:2", "green", [ "v0" ] ],
    [ "r2:1", "uno:GND.1", "green", [ "v0" ] ],
    [ "led2:A", "uno:4", "green", [ "v0" ] ],
    [ "led2:C", "r2:2", "green", [ "v0" ] ],
    [ "bz1:2", "uno:5", "green", [ "v0" ] ],
    [ "bz1:1", "uno:GND.1", "green", [ "v0" ] ]
  ],
  "dependencies": {}
}
