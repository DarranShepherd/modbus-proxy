#include <esp_log.h>
#include <led_strip.h>

#include "rgb_led.h"

#define RGB_GPIO 0

static const char* TAG = "modbus-proxy:rgb_led";

static led_strip_handle_t led_strip;

static uint8_t saturation = 0xFF;
static uint8_t value = 0x10;

esp_err_t rgb_init(void)
{
    ESP_LOGI(TAG, "Initializing RGB LED on GPIO %d", RGB_GPIO);
    
    led_strip_config_t strip_config = {
        .strip_gpio_num = RGB_GPIO,
        .max_leds = 1,
    };
    led_strip_rmt_config_t rmt_config = {
        .resolution_hz = 10 * 1000 * 1000, // 10MHz
        .flags.with_dma = false,
    };
    esp_err_t err = led_strip_new_rmt_device(&strip_config, &rmt_config, &led_strip);
    if (err == ESP_OK) {
        led_strip_clear(led_strip);
    }
        
    return err;
}

void rgb_set_hue(uint16_t hue)
{
    led_strip_set_pixel_hsv(led_strip, 0, hue, saturation, value);
    led_strip_refresh(led_strip);
}