#include "led.h"
#include "led_internal.h"

esp_err_t (*gpio_set_level_impl)(gpio_num_t, uint32_t) = gpio_set_level;

void led_on(void)
{
    gpio_set_level_impl(LED_BUILTIN, LED_ON_LEVEL);
}
