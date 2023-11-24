#include "main.h"
/**
 * print_binary prints a number as binary string
 * @n: the number to print 
 *
 *
 * return void
 **/
void print_binary(unsigned long int n)
{
	int bits = sizeof(n) * 8 ,print= 0;

	while(bits)
	{ 
	  if( n & 1L << --bits)
	   { 
		   _putchar('1');
		   print ++;
	   }
	  else if (print)
		  _putchar('0');
	
	}
	if (!print)
	      _putchar('0');
}
