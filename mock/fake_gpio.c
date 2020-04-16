#include <driver/gpio.h>

//stubs to stand in for the real things for the test builds


esp_err_t gpio_set_level(gpio_num_t gpio_num, uint32_t level)
{
    return ESP_OK;
}
