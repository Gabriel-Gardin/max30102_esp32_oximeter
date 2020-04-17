# ESP32 OXIMETER
Source code of an esp32 + maxim max30102 oximeter and heart rate device. This project was intended to be used as a cheap alternative to commercial oximeters in these hard days fighting corona virus.

This code is based on the great job of [Aromring](https://github.com/aromring/MAX30102_by_RF)

Hoppefully this can be usefull to somone.

## Espressif IoT Development Framework version

These project was built using esp-idf version: v4.1-beta1-63-g9f024df9e-dirty

[Available here](https://github.com/espressif/esp-idf/tree/release/v4.1)


## Connections beetwen esp32 and maxim max30102
MAX30102 Vin   ->   3v3

MAX30102 GND   ->   GND

MAX30102 SDA   -> GPIO33

MAX30102 SCL   -> GPIO32


## Flashing the code
Afer connecting everything up plug you esp32 to the pc and then in the project directory terminal run these commands:

```
idf.py fullclean

idf.py flash
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)
