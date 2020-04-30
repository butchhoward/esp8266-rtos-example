#ifndef LED_H
#define LED_H
#include <driver/gpio.h>

void led_setup();
void led_setup_pin(gpio_num_t pin);
void led_on(void);
void led_off(void);
void led_on_pin(gpio_num_t pin);
void led_off_pin(gpio_num_t pin);

#endif
