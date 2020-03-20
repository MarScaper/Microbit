# MicrobitFastDigitalWrite

Sample C code with optimized digitalWrite(). fastDigitalWrite() macro is more than 10x faster than the Nordic Semiconductor nRF5 library.

## Console

Optimized fastDigitalWrite(): 128.40ns -> 7.79MHz
Standard digitalWrite():  1784.60ns -> 0.56MHz
Speed improvement: 13.90x


# MicrobitTimers

Sample C code showing usage of hardware timers (Timer0, Timer1 and Timer2) with Arduino IDE and micro:bit board.

## Video

[![Alt text for your video](https://img.youtube.com/vi/ZVl5-23s2xQ/0.jpg)](https://www.youtube.com/watch?v=ZVl5-23s2xQ)

## Prerequisites

Install Micro:bit board within Arduino...

https://learn.adafruit.com/use-micro-bit-with-arduino/install-board-and-blink

## License

Copyright (c) 2020 by Sebastien MARCHAND 
Web:www.marscaper.com - Email:sebastien@marscaper.com

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
