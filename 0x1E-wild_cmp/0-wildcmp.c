#include "holberton.h"

/**
 * star_check - check for symbol, get string w/o symbol
 * @string: string to check
 *
 * Return: pointer to string w/o star
 */
char *star_check(char *string)
{
	if (*string != '*')
		return (string);
	return (star_check(string + 1));
}

/**
 * twin_check - compare to strings for samness
 *
 * @str: string to compare
 * @thingone: pattern to compare
 * @thingtwo: string
 * Return: compared strings
 */
int twin_check(char *str, char *thingone, char *thingtwo)
{
	if (*thingone == '*')
	{
		thingone = star_check(thingone);
		thingtwo = thingone;
	}
	if (*thingtwo == *thingone)
	{
		if (*str == '\0' && *thingone == '\0')
			return (1);
		if (*str == '\0' && *thingone != '\0')
			return (0);
		if (*thingone == *thingtwo)
			return (twin_check(str + 1, thingone + 1, thingtwo));
		return (twin_check(str + 1, thingone, thingtwo));
	}
	else
	{
		if (*str != *thingone)
		{
			if (!thingtwo)
				return (0);
			return (twin_check(str, thingtwo, thingtwo));
		}
		if (*thingone == '\0')
			return (1);
		if (thingtwo == '\0')
			return (1);
		return (twin_check(str + 1, thingone + 1, thingtwo));
	}
}

/**
 * wildcmp - compare two strings
 * @s_one: string to match
 * @s_two: pattern to match
 * Return: 1 if same 0 if not
 */
int wildcmp(char *s_one, char *s_two)
{

	return (twin_check(s_one, s_two, s_two));
}

