#include "led.h"
#include "led_internal.h"

esp_err_t (*gpio_set_level_impl)(gpio_num_t, uint32_t) = gpio_set_level;
esp_err_t (*gpio_set_direction_impl)(gpio_num_t, gpio_mode_t) = gpio_set_direction;
esp_err_t (*gpio_config_impl)(const gpio_config_t *gpio_cfg) = gpio_config;

void led_on(void)
{
    gpio_set_level_impl(LED_BUILTIN, LED_ON_LEVEL);
}

void led_off(void)
{
    gpio_set_level_impl(LED_BUILTIN, LED_OFF_LEVEL);
}

void led_setup(void)
{
    //must configure IO before using it (the built in leds worked by accident)
    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = ( 1ULL << LED_BUILTIN );
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;

    if (gpio_config_impl(&io_conf) != ESP_OK)
    {
        printf("gpio_config failed\n");
    }
}
