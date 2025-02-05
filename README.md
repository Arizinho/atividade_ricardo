# Semáforo com Temporizador Repetitivo

Este projeto implementa temporizador repetitivo para criar um semáforo utilizando a Raspberry Pi Pico W, com LEDs nas cores verde, amarelo e vermelho. Os LEDs ficam acesos durante 3 segundos, alternando a cada ciclo entre as cores: vermelho, amarelo e verde.

---

## **Configuração dos Pinos GPIO** 

Os pinos GPIO da Raspberry Pi Pico W estão configurados conforme a tabela abaixo:

| GPIO  | Componente      | Função                                                                     |  
|-------|-----------------|----------------------------------------------------------------------------|  
| **11** | LED Verde       | Emite cor verde (saída)                                                   |  
| **12** | LED Amarelo     | Emite cor amarela (saída)                                                 |  
| **13** | LED Vermelho    | Emite cor vermelha (saída)                                                |  

---

## **Funcionamento do Código**

1. **Inicialização**: O programa inicia o temporizador repetitivo para alternar o acendimento dos LEDs.
2. **Acionamento dos LEDs**: Os LEDs ficam acesos durante 3 segundos cada, seguindo a ordem: Vermelho, Amarelo, Verde. 
3. **Mensagens de Estado**: A cada segundo uma mensagem via serial é enviada, a depender do LED aceso:
   - "Siga! Sinal Verde."
   - "Atenção! Sinal amarelo."
   - "Pare! Sinal vermelho."

---

## **Link do Vídeo**

Link do vídeo:

https://drive.google.com/file/d/1VXEfgnm6a1NYm3uRt1uxuv77K7U9XTPa/view?usp=sharing
