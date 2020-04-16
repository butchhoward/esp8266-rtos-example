#include "esp_system.h"

void esp_chip_info(esp_chip_info_t* out_info)
{
    out_info->model = CHIP_ESP8266;
    out_info->revision = 1;
    out_info->cores = 1;
    out_info->features = 0x03; //flash and wifi bits set
}

void esp_restart(void)
{
    //you want to make sure this does not get called during testing
    //this is here to avoid triggering "-Winvalid-noreturn"
    while(1);
}
