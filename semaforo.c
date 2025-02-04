#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define RED_LED 13
#define BLUE_LED 12
#define GREEN_LED 11

bool repeating_timer_callback(struct repeating_timer *t){
    static uint8_t count = 0;
    count = (count + 1) % 3;
    
    switch (count)
    {
    case 0:
        gpio_put(RED_LED, 1);
        gpio_put(BLUE_LED, 0);
        gpio_put(GREEN_LED, 0);
        break;

    case 1:
        gpio_put(RED_LED, 1);
        gpio_put(BLUE_LED, 0);
        gpio_put(GREEN_LED, 1);
        break;
    
    default:
        gpio_put(RED_LED, 0);
        gpio_put(BLUE_LED, 0);
        gpio_put(GREEN_LED, 1);
        break;
    }
    return true;
}

int main()
{
    stdio_init_all();

    gpio_init(RED_LED);
    gpio_init(BLUE_LED);
    gpio_init(GREEN_LED);
    

    gpio_set_dir(RED_LED, GPIO_OUT);
    gpio_set_dir(BLUE_LED, GPIO_OUT);
    gpio_set_dir(GREEN_LED, GPIO_OUT);

    gpio_put(RED_LED, 1);
    gpio_put(BLUE_LED, 0);
    gpio_put(GREEN_LED, 0);

    struct repeating_timer timer;

    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer); 

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
