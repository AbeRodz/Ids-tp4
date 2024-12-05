/************************************************************************************************
Copyright (c) 2024, Abraham Rodriguez <abraham.rodz17@gmail.com>

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

#ifndef GPIO_H
#define GPIO_H

/** @file gpio.h
 ** @brief GPIO definitions.
 **/

/* === Headers files inclusions ================================================================ */

#include <stdint.h>
#include <stdbool.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

/* === Public data type declarations =========================================================== */

typedef struct gpio_s * gpio_t;

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

/**
 * @brief Creates a GPIO instance.
 *
 * This function initializes a GPIO instance for the specified port and bit.
 *
 * @param port The GPIO port number.
 * @param bit  The GPIO bit number.
 * @return gpio_t A GPIO instance.
 *
 *  NULL if there's an error.
 */
gpio_t GpioCreate(uint8_t port, uint8_t bit);

/**
 * @brief Sets a GPIO as output state.
 *
 * This function sets a GPIO instance into output state.
 *
 * @param gpio GPIO target instance.
 * @param output Output state.
 *
 */
void GpioSetOutput(gpio_t gpio, bool output);

/**
 * @brief Sets a GPIO into the desired state.
 *
 * This function sets a GPIO instance into the desired state.
 *
 * @param gpio GPIO target instance.
 * @param state Desired state.
 *
 */
void GpioSetState(gpio_t gpio, bool state);

/**
 * @brief Gets the current GPIO state.
 *
 * This function gets the currente GPIO state.
 *
 * @param gpio GPIO target instance.
 * @return bool Current state.
 */
bool GpioGetState(gpio_t gpio);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* GPIO_H */
