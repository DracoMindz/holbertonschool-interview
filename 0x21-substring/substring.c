#include <stdlib.h>
#include <stdio.h>

#include "substring.h"


/**
 * find_substring - find all possible holderstrings containing a list of words
 * @s: the string to scan
 * @words: the array of words all holderstrings must be a concatenation of
 * @nb_words: the num of elements in the array words
 * @n: holds the address at which to store the num of lelements in array
 * Return: array storing each index in s at where holderstring is found or NULL
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	char *holder = NULL, *checkstr = NULL;
	int *string, stringlen, dict = 0, count = 0, i, j, k;

	stringlen = strlen(s);
	dict = strlen(words[0]) * nb_words;
	string = malloc(stringlen + 1);
	holder = malloc(dict + 1);
	for (i = 0; i < stringlen; i++)
	{
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < dict;)
			{
				checkstr = strstr(holder + k, words[j]);
				if (checkstr != NULL)
				{
					if ((checkstr - holder) % (strlen(words[0])) == 0)
						break;
					if ((checkstr - holder) % (strlen(words[0])) != 0)
					{
						k = checkstr - holder + 1;
						checkstr = NULL;
					}
				}
				else if (checkstr == NULL)
					i++;
			}
			if (checkstr != NULL)
				memset(checkstr, '.', (strlen(words[0])));
			else
				i++;
		}
		if (stringlen != 0 && dict != 0)
			string[count++] = i;
		i++;
	}
	free(holder);
	*n = count;

	return (string);
}
