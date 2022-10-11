#include "morse.h"

DigitalOut myled(LED1);

static float delkaCarky = 0.6;
static float delkaTecky = 0.2;
static float delkaPauzy = 1.0;
static float delkaTicha = 0.1;

namespace Morse {
    void carka() {
        myled = 1;
        wait(delkaCarky);
        myled = 0;
        wait(delkaTicha);    
    }    
    void tecka(){
        myled = 1;
        wait(delkaTecky);
        myled = 0;
        wait(delkaTicha);
    }
    
    void pauza() {
        wait(delkaPauzy);
    }
    
    void blink(string morse, int n) {
        for (int i = 0; i < n; i++) {
            char znak = morse[i];
    
            switch(znak) {
                case '.':
                    tecka();
                    break;
                case '-':
                    carka();
                    break;
                default:
                    pauza();
                    break;
            }
        }
    }
}