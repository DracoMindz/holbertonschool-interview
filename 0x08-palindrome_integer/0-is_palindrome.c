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
	unsigned long revNum = 0, temp;

	temp = n;

	while (temp != 0)
	{
		revNum = (revNum * 10) + (temp % 10);
		temp = (temp / 10);
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
