#ifndef REGEX_H
#define REGEX_H

#include <stdlib.h>
#include <stdio.h>


int regex_match(char const *str, char const *pattern);
int matchsym( int sym, char const*regexp, char const *pattern);
int matchpattern(char const *regexp, char const *pattern);


#endif /* !REGEX_H */