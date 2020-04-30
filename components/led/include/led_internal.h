#ifndef LED_INTERNAL_H
#define LED_INTERNAL_H

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>

#define LED_BUILTIN GPIO_NUM_0
#define LOW_LEVEL 0
#define HIGH_LEVEL 1

#define LED_ON_LEVEL LOW_LEVEL
#define LED_OFF_LEVEL HIGH_LEVEL


extern esp_err_t (*gpio_set_level_impl)(gpio_num_t, uint32_t);
extern esp_err_t (*gpio_set_direction_impl)(gpio_num_t, gpio_mode_t);
extern esp_err_t (*gpio_config_impl)(const gpio_config_t *gpio_cfg);
extern void (*vTaskDelay_impl)(const TickType_t xTicksToDelay);


void led_on_pin_impl(gpio_num_t pin);
void led_off_pin_impl(gpio_num_t pin);
void led_setup_pin_impl(gpio_num_t pin);

#endif
