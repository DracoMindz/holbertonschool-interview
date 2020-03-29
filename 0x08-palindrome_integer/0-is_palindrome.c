#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"
/**
 * palindrome_check - check if integer is palindrome
 *
 * @n: number to be tested
 *
 * Return: 1 if yes, 0 if no
 */
int palindrome_check(unsigned long n)
{
	unsigned long revNum = 0;

	if (n != 0)
	{
		revNum = (revNum * 10) + (n % 10);
		palindrome_check(n / 10);
	}
	return (revNum);
}
/**
 * is_palindrome - check if integer is palindrome
 *
 * @n: number to be tested
 *
 * Return: 1 if yes, 0 if no
 */
int is_palindrome(unsigned long n)
{
	unsigned long revNum;

	revNum = palindrome_check(n);

	if (n == revNum)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
