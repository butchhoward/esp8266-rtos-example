# Blinky example using the ESP8266 RTOS SDK

Working thorugh building the project starting from the hello-world example and moving along to add something useful as an example.

Checkout the initial commit and step through the commits to see the progression.

```shell
git checkout d7c3c33
git crawl master
# look at code
git crawl master
# ...
```
(using the cool [git-crawl](https://github.com/magnusstahre/git-stuff))

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

Set the changes from the defaults in the make/cmake files.

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

## Build For Flash
Configure the system using the settings above.
Build and flash to device
Run monitor to see output

```shell
make defconfig flash
```

## Build For Test
Configure the system using the settings above.
Build and flash to device
Run monitor to see output

```shell
make -f Makefile.tdd
```
