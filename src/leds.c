/************************************************************************************************
Copyright (c) 2025, Abraham Rodriguez <abraham.rodz17@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

/** @file leds.c
 ** @brief LED function implementations.
 **/

/* === Headers files inclusions =============================================================== */

#include "leds.h"

/* === Macros definitions ====================================================================== */
/**  @brief Mask to turn OFF all leds */
#define ALL_LEDS_OFF 0x0000
/**  @brief Mask to turn ON all leds */
#define ALL_LEDS_ON 0xFFFF
/** @brief Led offset for masking */
#define LEDS_TO_BIT_OFFSET 1
/** @brief Bit to generate mask*/
#define LED_BIT_ON 1
/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */
/** @brief private variable to store port address*/
static uint16_t * port_address;
/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */

void  LedsInit(uint16_t *leds) {
    port_address = leds;
    LedsTurnOffAll();
}

static uint16_t LedToMask(uint8_t led){
    return (LED_BIT_ON<<(led - LEDS_TO_BIT_OFFSET));
}
void LedTurnOnSingle(uint8_t led){
    *port_address |= LedToMask(led); 
}
void LedTurnOffSingle(uint8_t led){
    *port_address  &= ~LedToMask(led); 
}
void LedsTurnOffAll(){
    *port_address  = ALL_LEDS_OFF; 
}
void LedsTurnOnAll(){
    *port_address  = ALL_LEDS_ON; 
}

bool isLedOn(uint8_t led){
    return (*port_address & LedToMask(led)) != 0;
}
/* === End of documentation ==================================================================== */
