/*
	Copyright 2023. 홍윤기 all right reserved.

	Permission is hereby granted, free of charge, to any person obtaining
	a copy of this software and associated documentation files (the
	"Software"), to deal in the Software without restriction, including
	without limitation the rights to use, copy, modify, merge, publish,
	distribute, sublicense, and/or sell copies of the Software, and to
	permit persons to whom the Software is furnished to do so, subject to
	the following conditions:

	The above copyright notice and this permission notice shall be
	included in all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
	EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
	MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
	NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
	LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
	OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
	WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <bsp.h>
#include <yss/instance.h>

void initializeBoard(void)
{
	using namespace define::gpio;

	// USART3 초기화
	gpioB.setAsAltFunc(10, altfunc::PB10_USART3_TX);
	// STM32F1 시리즈는 UART의 RX를 Alternate Function으로 설정하면 안됨

	usart3.enableClock();
	usart3.initialize(115200, 128);
	usart3.enableInterrupt();

	// UART4 초기화
	gpioC.setAsAltFunc(10, altfunc::PC10_UART4_TX);
	// STM32F1 시리즈는 UART의 RX를 Alternate Function으로 설정하면 안됨

	uart4.enableClock();
	uart4.initialize(115200, 128);
	uart4.enableInterrupt();
}

