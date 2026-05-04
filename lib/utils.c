
#include "utils.h"

void memclr(void *dst, unsigned int size)
{
    unsigned char *p = (unsigned char *)dst;

    while (size--)
    {
        *p++ = 0;
    }
}