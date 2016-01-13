#ifndef Fifo_h
#define Fifo_h

#if (ARDUINO <  100)
#include <WProgram.h>
#else
#include <Arduino.h>
#endif

#include <stdint.h>

struct Datos {
  int8_t valor;
  bool vacio = true;
};

class Fifo
{
  public:
    Fifo(uint8_t size);
    ~Fifo();
    bool poke(int8_t value);
    Datos peek();
  private:
    uint8_t _head;
    uint8_t _tail;
    uint8_t _overflow;
    uint8_t _SIZE;
    Datos * _fila;
    void _revisarLimites();
};

#endif
