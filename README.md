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

# Testing

I am using [Unity](http://www.throwtheswitch.org/) for testing. This is a framework geared toward `C` for the most part. I have not tested it yet with any `C++`. This framework is small, easy to build within a project and provides enough structure to organize and run micro-tests. Unity is in the project in the `unity` folder. There is a script to fetch the current version of the source from its Github repository. The script is there for a convenience. I stored the unity source files in this repository and only use the script to get updates. The script is not used during the build process. Unity is built during the Test build by commands in the `./test/CMakeLists.txt`.

Along with Unity, I am using [Fake Function Framework](https://github.com/meekrosoft/fff). This is a light-weight mocking framework delivered in a single header file. It works well with Unity and provides tools to create mock functions, capture call history, and argument history of calls. I has an impressive set of tools to generate mock results and is a marvel of Preprocessor `#define` voodoo. The doc shows it working with C++, but I have not yet tested it there yet. The `fff.h` header is in the `mock` folder. There is a script to fetch the current version of the source from its Github repository. The script is there for a convenience.I stored the FFF source files in this repository and only use the script to get updates. The script is not used during the build process. FFF is built during the Test build by commands in the `./test/CMakeLists.txt` that build the `mock` folder.

There are other testing frameworks suitable for embedded C/C++. [CppUTest](https://cpputest.github.io/) and [Google Test]() can both be used, but require a bit more complicated build configurations.

The build/run process for testing is managed with several `cmake` and `make` files. The complexity is mostly driven by trying to work within the context of the IDF system used by the ESP8266 RTOS SDK (and which mimics that if the ESP32 system, both from Espressif). 

The main work is in the `test/CMakeLists.txt` which controls the test runner application and defines all the dependencies needed from the RTOS SDK. While this is the largest cmake file, it is the most straightforward. It includes the files from `./test`, `./unity`, and `./mock` along with the production code files in `./components`. I do not build anything in `./main` for the tests. I assume (and strive to achieve) a program where the `main()` (or actually, `app_main()` for these IDF projects) does the least possible beyond calling some function(s) in the libraries. The functions in the library (`./components`) are considerably easier to test that `main()`.

The overall build is controlled by the `./CMakeLists.txt` file in the base folder. 

