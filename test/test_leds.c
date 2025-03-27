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

/** @file test_leds.c
 ** @brief unit tests for led control
 **/

/* === Headers files inclusions =============================================================== */

#include "unity.h"
#include "leds.h"


/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */
static uint16_t virtual_leds = 0xFFFF;
/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */\

void setUp(void){

    LedsInit(&virtual_leds);
}

/** @test initiates all LEDs as turned off. */ 
void test_init_every_led_turned_off(void) {
    uint16_t virtual_leds = 0xFFFF;

    LedsInit(&virtual_leds);

    TEST_ASSERT_EQUAL_HEX16(0x0000,virtual_leds);
}

/** @test initiates all LEDs as turned off. */ 
void test_turn_on_single_led(void){

    LedTurnOnSingle(4);

    TEST_ASSERT_EQUAL_HEX16(0x0008,virtual_leds);

}

/** @test turns off a single LED. */ 
void test_turn_off_single_led(void){
    LedTurnOnSingle(4);
    LedTurnOffSingle(4);
    TEST_ASSERT_EQUAL_HEX16(0x0000,virtual_leds);

}

/** @test turns off a multiple designated LEDs. */ 
void test_turn_on_off_multiple_led(void){
    LedTurnOnSingle(4);
    LedTurnOnSingle(6);

    LedTurnOffSingle(4);
    LedTurnOffSingle(8);

    TEST_ASSERT_EQUAL_HEX16(0x0020,virtual_leds);

}

/** @test turns on all LEDs. */ 
void test_turn_on_all_leds(void){
    LedsTurnOnAll();

    TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtual_leds);

}

/** @test turns off all LEDs. */ 
void test_turn_off_all_leds(void){
    LedsTurnOffAll();

    TEST_ASSERT_EQUAL_HEX16(0x0000, virtual_leds);

}

/** @test gets current ON status */ 
void test_get_on_status(void){
    LedTurnOnSingle(4);

    TEST_ASSERT_TRUE(isLedOn(4));

}
/** @test gets current OFF status */ 
void test_get_on_off_status(void){
    LedTurnOnSingle(4);
    LedTurnOffSingle(4);

    TEST_ASSERT_FALSE(isLedOn(4));

}
/* === Public function implementation ========================================================== */



/* === End of documentation ==================================================================== */
