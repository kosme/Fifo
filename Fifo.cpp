#include "Fifo.h"

Fifo::Fifo(uint8_t size)
{
  _SIZE = size;
  _head = 0;
  _tail = 0;
  _overflow = 0;
  _fila = (Datos *) malloc(sizeof(Datos) * _SIZE);
}

Fifo::~Fifo()
{
  free(_fila);
  _fila = NULL;
}

bool Fifo::poke(int8_t value)
{
  _revisarLimites();
  _fila[_head%_SIZE].vacio = false;
  _fila[_head%_SIZE].valor = value;
  if(((_head++ - _tail) >= _SIZE)||(_overflow > 0))
  {
    _tail++;
    if(_overflow < _SIZE)
      _overflow++;
    return true;
  }
  return false;
}

Datos Fifo::peek()
{
  static struct Datos _resp;
  _revisarLimites();
  _resp = _fila[_tail % _SIZE];
  _fila[_tail % _SIZE].vacio = true;
  if(_resp.vacio == false)
    _tail++;
  if(_overflow > 0)
    _overflow--;
  return _resp;
}

void Fifo::_revisarLimites()
{
  if((_head == UINT8_MAX)||(_tail == UINT8_MAX))
  {
    _head = _head % _SIZE;
    _tail = _tail % _SIZE;
  }
}
