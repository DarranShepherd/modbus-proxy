#include <freertos/FreeRTOS.h>
#include <esp_log.h>
#include <esp_timer.h>

#include "rgb_led.h"
#include "sdkconfig.h"

static const char* TAG = "modbus-proxy";

static void led_timer_callback(void* arg);

static uint8_t colour_idx = 0;
static uint16_t colours[] = {
    RGB_RED, RGB_ORANGE, RGB_YELLOW, RGB_GREEN_YELLOW,
    RGB_GREEN, RGB_GREEN_CYAN, RGB_AQUA, RGB_CYAN,
    RGB_BLUE, RGB_INDIGO, RGB_PURPLE, RGB_PINK
};


void app_main(void)
{
    rgb_init();

    ESP_LOGI(TAG, "Creating periodic timer");
    const esp_timer_create_args_t led_timer_args = {
        .callback = &led_timer_callback,
        .name = "led"
    };

    esp_timer_handle_t led_timer;
    ESP_ERROR_CHECK(esp_timer_create(&led_timer_args, &led_timer));

    ESP_ERROR_CHECK(esp_timer_start_periodic(led_timer, 2500000));
    
    vTaskSuspend(NULL);
}

static void led_timer_callback(void* arg)
{
    int64_t time_since_boot = esp_timer_get_time();
    ESP_LOGI(TAG, "Periodic timer called, time since boot: %lld us", time_since_boot);

    rgb_set_hue(colours[colour_idx]);
    colour_idx = (colour_idx + 1) % (sizeof(colours) / sizeof(colours[0]));
}

