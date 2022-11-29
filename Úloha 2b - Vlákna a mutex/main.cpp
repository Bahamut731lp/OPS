#include "mbed.h"
#include "stm32746g_discovery_lcd.h"

Mutex displayLock;
Thread thread1;
Thread thread2;

void thread1_function() {

    while(1) {
        displayLock.lock();
        BSP_LCD_DisplayStringAtLine(1, (uint8_t *)"MBED EXAMPLE");
        displayLock.unlock();
        ThisThread::sleep_for(1000);

        displayLock.lock();
        BSP_LCD_ClearStringLine(1);
        displayLock.unlock();

        ThisThread::sleep_for(1000);
    }
}

void thread2_function() {
    while(1) {
        displayLock.lock();
        BSP_LCD_DisplayStringAtLine(3, (uint8_t *)"MBED EXAMPLE 2");
        displayLock.unlock();
        ThisThread::sleep_for(1000);

        displayLock.lock();
        BSP_LCD_ClearStringLine(3);
        displayLock.unlock();
        ThisThread::sleep_for(2000);
    }
}

// main() runs in its own thread in the OS
int main() {
  // display_init();

  BSP_LCD_Init();
  BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
  BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
  BSP_LCD_Clear(LCD_COLOR_BLACK);
  BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
  BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);

  thread1.start(thread1_function);
  thread2.start(thread2_function);

  while (1) {}
}
