/* Teensyduino Core Library
 * http://www.pjrc.com/teensy/
 * Copyright (c) 2013 PJRC.COM, LLC.
 * Modifications by Jacob Alexander 2014-2018 for use with McHCK and Kiibohd-dfu
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * 1. The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * 2. If the Software is incorporated into a build system that allows
 * selection among a list of target devices, then similar target
 * devices manufactured by PJRC.COM must be included in the list of
 * target devices and selectable in the same manner.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

MEMORY
{
	FLASH     (rx) : ORIGIN = 0x0,                   LENGTH = 512K
	FLASH_APP (rx) : ORIGIN = 16K,                   LENGTH = 256K - 16K
	RAM      (rwx) : ORIGIN = 0x20000000 - 128K / 2, LENGTH = 128K
}

/* Starting Address of the application ROM */
_bootloader  = ORIGIN( FLASH );
_app_rom     = ORIGIN( FLASH_APP );
_app_rom_end = ORIGIN( FLASH ) + LENGTH( FLASH );

FlexRAM = 0x14000000;
FTFL = 0x40020000;
SCB = 0xe000ed00;
USB0 = 0x40072000;
SIM = 0x40047000;

/* Section Definitions */
INCLUDE mk.ld

