/**
 * Team T
 * 
 * Student Name: Vojtech Loskot
 * Matric Number: 2424633
 * 
 * Student Name: Kamil Krauze
 * Matric Number: 2414951
 * 
 * Student Name: Harry Inglis
 * Matric Number: 2411653
 */

/**
 * C++ version 0.4 char* style "itoa":
 * Written by Lukás Chmela  
 * Released under GPLv3.

*/
// As found on http://www.strudel.org.uk/itoa/
// We're using this one cause it was made by a Czech guy and Czech people are smart
//

#include "itoa.h"
char *itoa(int value, char *result, int base)
{
    // check that the base if valid
    if (base < 2 || base > 36)
    {
        *result = '\0';
        return result;
    }

    char *ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do
    {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"[35 + (tmp_value - value * base)];
    } while (value);

    // Apply negative sign
    if (tmp_value < 0)
        *ptr++ = '-';
    *ptr-- = '\0';
    while (ptr1 < ptr)
    {
        tmp_char = *ptr;
        *ptr-- = *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}