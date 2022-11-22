#include "mbed.h"
#include "stm32746g_discovery_lcd.h"

Thread thread1;
Thread thread2;

void thread1_function() {
  BSP_LCD_DisplayStringAt(0, 1, (uint8_t *)"MBED EXAMPLE", CENTER_MODE);
  ThisThread::sleep_for(1000);
}

void thread2_function() {
  BSP_LCD_DisplayStringAt(1, 1, (uint8_t *)"MBED EXAMPLE 2", CENTER_MODE);
  ThisThread::sleep_for(1000);
}

// main() runs in its own thread in the OS
int main() {
  // display_init();

  BSP_LCD_Init();
  BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
  BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
  BSP_LCD_Clear(LCD_COLOR_BLACK);
  BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
  BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
  BSP_LCD_SetTextColor(LCD_COLOR_DARKBLUE);

  // BSP_LCD_DisplayStringAt(1, 1, (uint8_t *)"MBED EXAMPLE 2", CENTER_MODE);

  thread1.start(thread1_function);
  thread1.join();
  BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
  BSP_LCD_Clear(LCD_COLOR_BLACK);
  ThisThread::sleep_for(1000);

  thread2.start(thread2_function);
  thread2.join();
  BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
  BSP_LCD_Clear(LCD_COLOR_BLACK);
  ThisThread::sleep_for(2000);

  //
  // ThisThread::sleep_for(1000);

  /*thread2.start(thread2_function);
  thread2.join();
  BSP_LCD_Clear(LCD_COLOR_BLACK);
  ThisThread::sleep_for(2000);*/

  while (1) {
  }

  /*while (1) {
    thread1.start(thread1_function);
    thread1.join();
    BSP_LCD_Clear(LCD_COLOR_BLACK);
    ThisThread::sleep_for(1000);

    thread2.start(thread2_function);
    thread2.join();
    BSP_LCD_Clear(LCD_COLOR_BLACK);
    ThisThread::sleep_for(2000);
    // BSP_LCD_DisplayStringAt(5, 1, (uint8_t *)"MBED EXAMPLE 2", CENTER_MODE);
  }*/
}
