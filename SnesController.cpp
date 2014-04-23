/**************************************************************************/
/*! 
    @file     SnesController.cpp
    @author   Alfredo Rius
	@license  BSD (see license.txt)

    Library to use an snes controller

	@section  HISTORY

    v1.0 - Just starting

*/
/**************************************************************************/

/*
#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
*/

#include "Arduino.h"
#include "SnesController.h"

SnesController::SnesController(uint8_t clk_pin, uint8_t strobe_pin, uint8_t data_pin)
{
  pinMode(clk_pin, OUTPUT);
  pinMode(strobe_pin, OUTPUT);
  _clk_pin = clk_pin;
  _strobe_pin = strobe_pin;
  _data_pin = data_pin;
}

void SnesController::SnesControllerRead(uint8_t * data)
{
  uint8_t i;
  digitalWrite(_strobe_pin,HIGH);
  digitalWrite(_strobe_pin,LOW);
  for(i=0;i<SNES_BUTTONS;i++){
    data[i] = !digitalRead(_data_pin);
    digitalWrite(_clk_pin,HIGH);
    digitalWrite(_clk_pin,LOW);
  }
}
