/**************************************************************************/
/*! 
    @file     SnesController.h
    @author   Alfredo Rius
	@license  BSD (see license.txt)

    Library to use an snes controller

	@section  HISTORY

	v1.0 - Just starting
	
*/
/**************************************************************************/


#ifndef SnesController_h
#define SnesController_h

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif


#define SNES_BUTTONS     12
#define SNES_UP          4
#define SNES_DOWN        5
#define SNES_LEFT        6
#define SNES_RIGHT       7
#define SNES_L           10
#define SNES_R           11
#define SNES_START       3
#define SNES_SELECT      2
#define SNES_A           8
#define SNES_B           0
#define SNES_Y           1
#define SNES_X           9

class SnesController
{
  public:
    SnesController(uint8_t clk_pin, uint8_t strobe_pin, uint8_t data_pin);
    void SnesControllerRead(uint8_t * data);
  private:
    uint8_t  _clk_pin;
    uint8_t  _strobe_pin;
    uint8_t  _data_pin;
};

#endif
