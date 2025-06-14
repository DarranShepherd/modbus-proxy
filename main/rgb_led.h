#define RGB_RED 0
#define RGB_ORANGE 30
#define RGB_YELLOW 60
#define RGB_GREEN_YELLOW 90
#define RGB_GREEN 120
#define RGB_GREEN_CYAN 150
#define RGB_AQUA 180
#define RGB_CYAN 210
#define RGB_BLUE 240
#define RGB_INDIGO 270
#define RGB_PURPLE 300
#define RGB_PINK 330

esp_err_t rgb_init(void);
void rgb_set_hue(uint16_t hue);
