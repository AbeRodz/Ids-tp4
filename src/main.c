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

/** @file main.c
 ** @brief main program
 **/

/* === Headers files inclusions =============================================================== */

#include "main.h"
#include "gpio.h"

/* === Macros definitions ====================================================================== */

#define RED_LED_PORT   1
#define GREEN_LED_PORT 2
#define BLUE_LED_PORT  3

#define RED_LED_PIN    7
#define GREEN_LED_PIN  11
#define BLUE_LED_PIN   14

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

// TODO
void Delay(uint32_t duration) {
}
/* === Public function implementation ========================================================== */

int main(void) {
    gpio_t red_led, green_led, blue_led;

    // LED init
    red_led = GpioCreate(RED_LED_PORT, RED_LED_PIN);
    GpioSetOutput(red_led, true);
    GpioSetState(red_led, true);

    green_led = GpioCreate(GREEN_LED_PORT, GREEN_LED_PIN);
    GpioSetOutput(green_led, true);
    GpioSetState(green_led, true);

    blue_led = GpioCreate(BLUE_LED_PORT, BLUE_LED_PIN);
    GpioSetOutput(blue_led, true);
    GpioSetState(blue_led, true);

    while (1) {
        GpioSetState(red_led, false);
        GpioSetState(green_led, true);
        GpioSetState(blue_led, false);

        Delay(1000);

        GpioSetState(red_led, true);
        Delay(100);
        GpioSetState(green_led, false);
        Delay(200);
        GpioSetState(blue_led, true);
        Delay(300);
    }

    return 0;
}

/* === End of documentation ==================================================================== */
