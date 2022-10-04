#include "mbed.h"
#include "stm32746g_discovery_lcd.h"
#include <string> 

using namespace std;

DigitalOut myled(LED1);

void carka()
{
    myled = 1;
    wait(0.6);
    myled = 0;
    wait(0.1);
}

void tecka()
{
    myled = 1;
    wait(0.2);
    myled = 0;
    wait(0.1);
}

void pauza()
{
    wait(1.0);
}

void decoder(string morse, int n)
{
    int znak = 0;
    
    for (int i = 0; i < n; i++) {
        if (morse[i] == '.') {
            znak = 1;
        } else if (morse[i] == '-') {
            znak = 2;
        } else {
            znak = 3;
        }
        
        switch(znak) {
            case 1:
                tecka();
                break;
            case 2:
                carka();
                break;
            default:
                pauza();
                break;
        }
    }
}

int main()
{
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
    BSP_LCD_Clear(LCD_COLOR_BLACK);
    BSP_LCD_Clear(LCD_COLOR_BLACK);
    BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
    BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
    BSP_LCD_SetTextColor(LCD_COLOR_DARKBLUE);
    
    BSP_LCD_DisplayStringAt(0, 1, (uint8_t *)"DEVIN KANEK & HATEJ MAMPL", CENTER_MODE);

    string morse ="-.. . ...- .. -. / -.- .- -. . -.- / .... .- - . .--- / -- .- -- .--. .-..";
    int n = morse.length();
    while(1) {
        decoder(morse, n);
    }
}
