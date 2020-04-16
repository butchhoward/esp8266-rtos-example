#ifndef LED_INTERNAL_H
#define LED_INTERNAL_H

#include <driver/gpio.h>

#define LED_BUILTIN GPIO_NUM_16

#define LOW_LEVEL 0

#define LED_ON_LEVEL LOW_LEVEL


extern esp_err_t (*gpio_set_level_impl)(gpio_num_t, uint32_t);

#endif
