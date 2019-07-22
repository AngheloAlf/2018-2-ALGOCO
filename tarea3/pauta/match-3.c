/**
 * @file  match-3.c
 * @brief Pike's regexp match, augmented with 'c?'
 *   https://www.cs.princeton.edu/courses/archive/spr09/cos333/beautiful.html
 *
 * Added declarations  HvB 2018-10-04
 */

#include "match.h"

int matchhere(char *regexp, char *text);
int matchstar(int c, char *regexp, char *text);
int matchques(int c, char *regexp, char *text);

/* match: search for regexp anywhere in text */
int match(char *regexp, char *text)
{
    if (regexp[0] == '^')
        return matchhere(regexp+1, text);
    do {    /* must look even if string is empty */
        if (matchhere(regexp, text))
            return 1;
    } while (*text++ != '\0');
    return 0;
}

/* matchhere: search for regexp at beginning of text */
int matchhere(char *regexp, char *text)
{
    if (regexp[0] == '\0')
        return 1;
    if (regexp[1] == '*')
        return matchstar(regexp[0], regexp+2, text);
    if (regexp[1] == '?')
        return matchques(regexp[0], regexp+2, text);
    if (regexp[0] == '$' && regexp[1] == '\0')
        return *text == '\0';
    if (*text!='\0' && (regexp[0]=='.' || regexp[0]==*text))
        return matchhere(regexp+1, text+1);
    return 0;
}

/* matchstar: search for c*regexp at beginning of text */
int matchstar(int c, char *regexp, char *text)
{
    do {    /* a * matches zero or more instances */
        if (matchhere(regexp, text))
            return 1;
    } while (*text != '\0' && (*text++ == c || c == '.'));
    return 0;
}

/* matchques: search for c?regexp at beginning of text */
int matchques(int c, char *regexp, char *text)
{
    if (*text != '\0' && (c == '.' || c == *text))
        if (matchhere(regexp, text + 1))
	    return 1;
    return matchhere(regexp, text);
}
