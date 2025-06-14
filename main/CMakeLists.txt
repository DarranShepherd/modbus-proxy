idf_component_register(SRCS "main.c" "rgb_led.c"
                       REQUIRES esp_timer
                       PRIV_REQUIRES spi_flash
                       INCLUDE_DIRS "")
