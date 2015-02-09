/* Copyright (C) 2013-2015 by Jacob Alexander
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef __output_com_h
#define __output_com_h

// ----- Includes -----

// Compiler Includes
#include <stdint.h>

// Local Includes
#include <buildvars.h> // Defines USB Parameters, partially generated by CMake



// ----- Defines -----

// Max size of key buffer needed for NKRO
// Boot mode uses only the first 6 bytes
#define USB_NKRO_BITFIELD_SIZE_KEYS 26
#define USB_BOOT_MAX_KEYS 6



// ----- Enumerations -----

// USB NKRO state transitions (indicates which Report ID's need refreshing)
// Boot mode just checks if any keys were changed (as everything is sent every time)
typedef enum USBKeyChangeState {
	USBKeyChangeState_None          = 0x00,
	USBKeyChangeState_Modifiers     = 0x01,
	USBKeyChangeState_MainKeys      = 0x02,
	USBKeyChangeState_SecondaryKeys = 0x04,
	USBKeyChangeState_TertiaryKeys  = 0x08,
	USBKeyChangeState_System        = 0x10,
	USBKeyChangeState_Consumer      = 0x20,
	USBKeyChangeState_All           = 0x3F,
} USBKeyChangeState;



// ----- Variables -----

// Variables used to communciate to the output module
// XXX Even if the output module is not USB, this is internally understood keymapping scheme
extern          uint8_t  USBKeys_Modifiers;
extern          uint8_t  USBKeys_Keys[USB_NKRO_BITFIELD_SIZE_KEYS];
extern          uint8_t  USBKeys_Sent;
extern volatile uint8_t  USBKeys_LEDs;

extern          uint8_t  USBKeys_SysCtrl;  // 1KRO container for System Control HID table
extern          uint16_t USBKeys_ConsCtrl; // 1KRO container for Consumer Control HID table

extern volatile uint8_t  USBKeys_Protocol; // 0 - Boot Mode, 1 - NKRO Mode

// Misc variables (XXX Some are only properly utilized using AVR)
extern          uint8_t  USBKeys_Idle_Config;
extern          uint8_t  USBKeys_Idle_Count;

extern USBKeyChangeState USBKeys_Changed;

extern          uint8_t  Output_Available; // 0 - Output module not fully functional, 1 - Output module working



// ----- Capabilities -----

void Output_consCtrlSend_capability( uint8_t state, uint8_t stateType, uint8_t *args );
void Output_sysCtrlSend_capability( uint8_t state, uint8_t stateType, uint8_t *args );
void Output_usbCodeSend_capability( uint8_t state, uint8_t stateType, uint8_t *args );



// ----- Functions -----

void Output_setup();
void Output_send();

void Output_firmwareReload();
void Output_softReset();

// Relies on USB serial module
unsigned int Output_availablechar();

int Output_getchar();
int Output_putchar( char c );
int Output_putstr( char* str );

#endif

