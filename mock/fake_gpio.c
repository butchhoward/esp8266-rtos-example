#include <driver/gpio.h>
#include <string.h>

#include "fake_gpio.h"
//stubs to stand in for the real things for the test builds


esp_err_t gpio_set_level(gpio_num_t gpio_num, uint32_t level)
{
    return ESP_OK;
}

esp_err_t gpio_set_direction(gpio_num_t gpio_num, gpio_mode_t mode)
{
    return ESP_OK;
}

gpio_config_t gpio_cfg_last_sent;

esp_err_t gpio_config(const gpio_config_t *gpio_cfg)
{
    memcpy(&gpio_cfg_last_sent, gpio_cfg, sizeof(gpio_config_t ));
    return ESP_OK;
}

void clear_gpio_config_fake_last_arg()
{
    gpio_cfg_last_sent.pin_bit_mask = -1;
    gpio_cfg_last_sent.mode = GPIO_MODE_DISABLE;
    gpio_cfg_last_sent.pull_up_en = GPIO_PULLUP_DISABLE;
    gpio_cfg_last_sent.pull_down_en = GPIO_PULLDOWN_DISABLE;
    gpio_cfg_last_sent.intr_type = GPIO_INTR_DISABLE;
}

gpio_config_t get_gpio_config_fake_last_arg()
{
    return gpio_cfg_last_sent;
}
