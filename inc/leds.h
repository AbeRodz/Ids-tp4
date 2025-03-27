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

#ifndef LEDS_H
#define LEDS_H

#include <stdint.h>
#include <stdbool.h>
/** @file leds.h
 ** @brief led control function definitions
 **/

/* === Headers files inclusions ================================================================ */

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

/* === Public data type declarations =========================================================== */

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */


/**
 * @brief Initiates led
 *
 * @param leds Pointer to GPIO port designated to leds.
 */
void LedsInit(uint16_t *leds);


/**
 * @brief Function to turn a selected LED ON
 * 
 * @param led selected LED to turn ON
 * 
 */
void LedTurnOnSingle(uint8_t led);

/**
 * @brief Function to turn a selected LED OFF
 * 
 * @param led selected LED to turn OFF
 * 
 */
void LedTurnOffSingle(uint8_t led);

/**
 * @brief Function to turn all LEDs OFF
 * 
 */
void LedsTurnOffAll();

/**
 * @brief Function to turn all LEDs ON
 * 
 */
void LedsTurnOnAll();

/**
 * @brief Function to check whether LED ON/OFF
 * 
 * @param led selected LED to check
 * 
 * @return bool true only if LED is on
 */
bool isLedOn(uint8_t led);
/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* LEDS_H */
