#include "Fifo.h"

#define SIZE 8

Fifo cola(SIZE);

struct Datos celda;

void setup()
{
  pinMode(13,OUTPUT);
  Serial.begin(115200);
  for(int i=0;i<SIZE;i++)
  {
    if(cola.poke(i))
      Serial.println("Overflow");
    else
      Serial.print(".");
  }
  Serial.println();
  for(int i =0;i<SIZE;i++)
  {
    celda = cola.peek();
    if(celda.vacio==false)
    {
      Serial.println(celda.valor);
    }
    else
    {
      Serial.println("Underflow");
    }
  }

  for(int i=0;i<2;i++)
  {
    if(cola.poke(i+8))
      Serial.println("Overflow");
    else
      Serial.print(".");
  }
  Serial.println();
  for(int i =0;i<3;i++)
  {
    celda = cola.peek();
    if(celda.vacio==false)
    {
      Serial.println(celda.valor);
    }
    else
    {
      Serial.println("Underflow");
    }
  }

  for(int i=0;i<SIZE+2;i++)
  {
    if(cola.poke(i+10))
    {
      Serial.println("Overflow");
    }
    else
      Serial.print(".");
  }
  Serial.println();
  for(int i =0;i<SIZE+8;i++)
  {
    celda = cola.peek();
    if(celda.vacio==false)
    {
      Serial.println(celda.valor);
    }
    else
    {
      Serial.println("Underflow");
    }
  }
}

void loop()
{
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
}
