#include <stddef.h>
#include "regex.h"


/**
* matchpattern - find match
* @regexp: string to check against pattern
* @pattern: pattern
*
*/
int matchpattern(char const *regexp, char const *pattern)
{

	/* NULL cases */
	if (regexp[0] == '\0' && pattern[0] == '\0')
		return (1);

	/* incase of symbols */
	if (regexp[1] == '*')
		return (matchsym(regexp[0], regexp + 2, pattern));
	if (*pattern != '\0' && (regexp[0] == '.' || regexp[0] == *pattern))
		return (matchpattern(regexp + 1, pattern + 1));
	return (0);
}
/**
 * matchsym -  search for syombol
 * @sym: symbol
 * @regexp: string to check
 * @pattern: pattern
 *
 */
int matchsym(int sym, char const *regexp, char const *pattern)
{
	do {
		if (matchpattern(regexp, pattern))
			return (1);
	} while (*pattern != '\0' && (*pattern++ == sym || sym == '.'));
	return (0);
}
/**
 * regex_match - checks wether a pattern matches a string
 * @str: string to check
 * @pattern: pattern
 *
 */
int regex_match(char const *str, char const *pattern)
{
	return (matchpattern(str, pattern));
}
