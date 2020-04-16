# Hello World Example

Starts a FreeRTOS task to print "Hello World"

See the README.md file in the upper level 'examples' directory for more information about examples.


# Configuration

## e-Paper ESP8266 Driver Board, Waveshare

`make menuconfig` settings

```
 (/dev/cu.SLAB_USBtOUART) Default serial port 
 Default baud rate (115200 baud)
 [ * ] Use compressed upload Flash SPI mode (QI0)
 Flash SPI speed (80 MHz)
 Flash size (4 MB)
 Before flashing (Reset to bootloader)
 After flashing (Hard reset after flashing) 
 'make monitor' baud rate (74880 bps)
```

# Do the Doing

## Install and configure the ESP8266_RTOS_SDK
* Follow the steps EXACTLY: [Get Started](https://docs.espressif.com/projects/esp8266-rtos-sdk/en/latest/get-started/index.html)
* Resolve any Python issues you have

## Resolve MacOS Python issues

Python has [environment issues](https://xkcd.com/1987/)

MacOS makes those worse by still installing Python 2.7.

Pyenv helps in most cases ([there are details](https://opensource.com/article/19/5/python-3-default-mac)):
```
pyenv install 3.7.2
pyenv global 3.7.2
```

## Build 
Configure the system using the settings above.
Build and flash to device
Run monitor to see output

```shell
make menuconfig
make flash
make monitor
```
