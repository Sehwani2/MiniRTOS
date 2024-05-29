#include "stdint.h"
#include "HalUart.h"
#include "stdio.h"

uint32_t putstr(const char* s)
{
	uint32_t c =0;
	while(*s)
	{
		Hal_uart_put_char(*s++);
		c++;
	}
	return c;
}

uint32_t debug_printf(const char* format, ...)
{
	va_list args;
	va_start(args,format);
	vsprintf(printf_buf, format, args);
	va_end(args);

	return putstr(printf_buf);
}

uint32_t vsprintf(char* buf, const char* format, va_list arg)
{
	uint32_t c = 0;

	char	ch;
	char*	str;
	uint32_t uint;
	uint32_t hex;

	for(uint32_t i =0; format[i] ; i++)
	{
		if(format[i] == '%')
		{
			i++;
			switch(format[i])
			{
			case 'c':
				ch = (char)va_arg(arg, int32_t);
				buf[c++] = ch;
				break;
			case 's':
				str = (char*)va_arg(arg,char*);
				if(str == NULL)
				{
					str = "(null)";
				}
				while(*str)
				{
					buf[c++] = (*str++);
				}
				break;
			case 'u':
				uint = (uint32_t)va_arg(arg,uint32_t);
				c += utoa(&buf[c], uint , utoa_dec);
				break;
			case 'x':
				hex = (uint32_t)va_arg(arg, uint32_t);
				c += utoa(&buf[c], hex, utoa_hex);
				break;
			}
		}
		else
		{
			buf[c++] = format[i];
		}
	}

	if(c > PRINTF_BUF_LEN)
	{
		buf[0] = '\0';
		return 0;
	}

	buf[c] = '\0';
	return c;
}
