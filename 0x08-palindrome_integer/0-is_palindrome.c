#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"
/**
 * is_palindrome - check if integer is palindrome
 *
 * @n: number to be tested
 *
 * Return: 1 if yes, 0 if no
 */
int is_palindrome(unsigned long n)
{
	unsigned long revNum = 0;
	unsigned long tempNum;

	tempNum = n;

	while (tempNum != 0)
	{
		revNum = (revNum * 10) + tempNum % 10;
		tempNum = tempNum / 10;
	}
	if (n == revNum)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
