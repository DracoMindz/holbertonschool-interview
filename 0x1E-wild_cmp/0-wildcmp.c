#include "holberton.h"

/**
 * star_check - check for '*', get string w/o '*'
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
 *
 *
 *
 *
 */
int check_strings(char *str, char *thing1, char *thing2 )
{
	/*star check*/
	if(*thing1 == '*')
	{
		thing1 = star_checker(thing1);
		thing2 = thing1
	}

	if (*thing2 == *thing1)
	{
			/* check Null cases */
		if (*str == '\0' && *thing1 == '\0')
			return (1);
		if (*str == '\0' && *thing1 != '\0')
			return (0);
		if (*thing1 == *thing2)
			return (check_strings(str + 1, thing1 + 1, thing2));
		return (check_strings(str + 1, thing1, thing2));
	}
	else
	{

		if (*str != *thing1)
		{
			if (!thing2)
				return (0)
			return (check_strings(str, thing2, thing2));
		}

		if (*thing1 == '\0')
			return (1);
		if (thing2 == '\0')
			return (1);
		return (check_strings(str +1, thing1 + 1, thing2));
	}
}
/**
 * wildcmp - compare two strings
 *
 * @s1: string to match
 * @s2: pattern to match
 * Return: 1 if same 0 if not
 */
int wildcmp(char *s1, char *s2)
{
	return(check_strings(s1, s2, s2));
}

