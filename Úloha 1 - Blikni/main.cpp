#include "mbed.h"
#include "stm32746g_discovery_lcd.h"
#include <string> 
#include "morse.h"
using namespace std;

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
        Morse::blink(morse, n);
    }
}