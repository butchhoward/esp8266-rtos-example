#ifndef BLINKEN_LIGHTS_H
#define BLINKEN_LIGHTS_H

#include <driver/gpio.h>

#define DEVICE_TYPE_FEATHER
// #define DEVICE_TYPE_WAVESHARE

#if defined(DEVICE_TYPE_WAVESHARE)
    #define LEDS_BUILTIN_RED GPIO_NUM_16
    #define LEDS_BUILTIN_BLUE GPIO_NUM_2
#elif defined(DEVICE_TYPE_FEATHER)
    #define LEDS_BUILTIN_RED GPIO_NUM_0
    #define LEDS_BUILTIN_BLUE GPIO_NUM_2
#else
    #error "Use a known DEVICE_TYPE_XXX"
#endif

void blinken_setup(void);
void blinken_loop(void);

#endif
