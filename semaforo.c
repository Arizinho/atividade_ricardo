#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

//macro dos pinos GPIO
#define RED_LED 13
#define YELLOW_LED 12
#define GREEN_LED 11

//variavel para salvar estado -> 0 = vemelho; 1 = amarelo; 2 = verde 
volatile uint8_t count = 0;

//função de callback de timer repetitivo para mudar as cores do semáforo
bool repeating_timer_callback(struct repeating_timer *t){
    count = (count + 1) % 3;
    
    switch (count)
    {
    //liga led vermelho
    case 0:
        gpio_put(RED_LED, 1);
        gpio_put(YELLOW_LED, 0);
        gpio_put(GREEN_LED, 0);
        break;

    //liga led amarelo
    case 1:
        gpio_put(RED_LED, 0);
        gpio_put(YELLOW_LED, 1);
        gpio_put(GREEN_LED, 0);
        break;
    
    //liga led verde
    default:
        gpio_put(RED_LED, 0);
        gpio_put(YELLOW_LED, 0);
        gpio_put(GREEN_LED, 1);
        break;
    }
    //mantém temporizador ativo
    return true;
}

int main()
{
    //habilita interfaces de comunicação
    stdio_init_all();

    //inicializa pinos led
    gpio_init(RED_LED);
    gpio_init(YELLOW_LED);
    gpio_init(GREEN_LED);
    
    //configura como saída
    gpio_set_dir(RED_LED, GPIO_OUT);
    gpio_set_dir(YELLOW_LED, GPIO_OUT);
    gpio_set_dir(GREEN_LED, GPIO_OUT);

    //inicia semáforo em vermelho
    gpio_put(RED_LED, 1);
    gpio_put(YELLOW_LED, 0);
    gpio_put(GREEN_LED, 0);

    //configura o temporizador repetitivo a cada 3s
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer); 

    //mostra frases de alerta para cada cor do semáforo a cada 1 segundo
    while (true) {
        switch(count){
            case 0:
                printf("Pare! Sinal vermelho.\n");
                break;
            
            case 1:
                printf("Atenção! Sinal amarelo.\n");
                break;
            
            default:
                printf("Siga! Sinal verde.\n");
                break;
        }
        sleep_ms(1000);
    }
}
