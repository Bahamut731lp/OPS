#include "mbed.h"
#include <string>
#include "stm32746g_discovery_lcd.h"
#include "params.h"

#define MAX_LAYER_NUMBER ((uint32_t)5)

struct ThreadStruct {
    int x;
    int y;
    int period;
    int layerIndex;
    string text;
};

Thread thread1;
Thread thread2;
Thread thread3;

/*
* Funkce pro inicializaci displeje 
*/
void display_init() {
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
    BSP_LCD_Clear(LCD_COLOR_BLACK);
    BSP_LCD_Clear(LCD_COLOR_BLACK);
    BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
    BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
    BSP_LCD_SetTextColor(LCD_COLOR_DARKBLUE);
}

void init_layer(int index) {
    BSP_LCD_LayerDefaultInit(index, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(index);
    BSP_LCD_Clear(LCD_COLOR_BLACK);
    BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
    BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
    BSP_LCD_SetTextColor(LCD_COLOR_DARKBLUE);
}

/*
* Funkce pro otevření nového vlákna s textem
* @param {ThreadStruct*} currentThread - Pointer na struct držící informace o vlákně
*/
void openThread(ThreadStruct* currentThread) {
    while (true) {
        BSP_LCD_DisplayStringAtLine(currentThread->layerIndex, (uint8_t *)reinterpret_cast<const uint8_t*>(&currentThread->text));
        ThisThread::sleep_for(currentThread->period / 2);
        BSP_LCD_ClearStringLine(currentThread->layerIndex);
        ThisThread::sleep_for(currentThread->period / 2);
    }
}

int main()
{
    ThreadStruct thread1_config = {
        COORDS_1_X,
        COORDS_1_Y,
        PERIOD_1,
        1,
        TEXT_1
    };

    ThreadStruct thread2_config = {
        COORDS_2_X,
        COORDS_2_Y,
        PERIOD_2,
        2,
        TEXT_2
    };

    ThreadStruct thread3_config = {
        COORDS_3_X,
        COORDS_3_Y,
        PERIOD_3,
        3,
        TEXT_3
    };

    display_init();

    thread1.start(callback(openThread, &thread1_config));
    thread2.start(callback(openThread, &thread2_config));
    thread3.start(callback(openThread, &thread3_config));
    
    while(true) {};
}

