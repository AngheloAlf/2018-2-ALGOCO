/**
 * @file  match-4.c
 * @brief Pike's regexp match, adding '+' and '?', and handling escapes.
 *   https://www.cs.princeton.edu/courses/archive/spr09/cos333/beautiful.html
 *
 * Added declarations  HvB 2018-10-04
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "match.h"

/* codes for metacharacters */
enum {
	RE_START = 256,  /* ^ */
	RE_STOP,	 /* $ */
	RE_ANY,          /* . */
	RE_STAR,         /* * */
	RE_PLUS,         /* + */
	RE_QUES          /* ? */
};

int matchhere(short regexp[], char *text);
int matchstar(int c, short c_regexp[], char *text);
int matchplus(int c, short c_regexp[], char *text);
int matchques(int c, short c_regexp[], char *text);
short *compile(char *regexp);

/* compile: translate a regexp with '\' */
short *compile(char *regexp)
{
    short *c_re = malloc((strlen(regexp) + 1) * sizeof(short));
    if(c_re == NULL) {
	fprintf(stderr, "can't get memory for regexp\n");
        exit(EXIT_FAILURE);
    }
    char *sp = regexp;
    short *dp = c_re;

    if(*sp == '^') {
	    *dp++ = RE_START;
	    sp++;
    }
    for(; *sp; sp++) {
	    switch(*sp) {
	    case '\\':
		    sp++;
		    *dp++ = *sp;
		    break;
	    case '.':
		    *dp++ = RE_ANY;
		    break;
	    case '*':
		    *dp++ = RE_STAR;
		    break;
	    case '+':
		    *dp++ = RE_PLUS;
		    break;
	    case '?':
		    *dp++ = RE_QUES;
		    break;
	    case '$':
		    if(*(sp + 1) == '\0')
			    *dp++ = RE_STOP;
		    else
			    *dp++ = '$';
		    break;
	    default:
		    *dp++ = *sp;
		    break;
	    }
    }
    *dp = 0;
    return c_re;
}

/* match: search for regexp anywhere in text */
int match(char *regexp, char *text)
{
    short *c_re = compile(regexp);
    int ret = 0;

    if (c_re[0] == RE_START) {
        ret = matchhere(c_re+1, text);
    }
    else {
	do {    /* must look even if string is empty */
	    if (matchhere(c_re, text)) {
		ret = 1;
		break;
	    }
	} while (*text++ != '\0');
    }
    free(c_re);
    return ret;
}

/* matchhere: search for regexp at beginning of text */
int matchhere(short regexp[], char *text)
{
    if (regexp[0] == '\0')
        return 1;
    if (regexp[1] == RE_PLUS)
        return matchplus(regexp[0], regexp+2, text);
    if (regexp[1] == RE_STAR)
        return matchstar(regexp[0], regexp+2, text);
    if (regexp[1] == RE_QUES)
        return matchques(regexp[0], regexp+2, text);
    if (regexp[0] == RE_STOP)
        return *text == '\0';
    if (*text!='\0' && (regexp[0]==RE_ANY || regexp[0]==*text))
        return matchhere(regexp+1, text+1);
    return 0;
}

/* matchstar: search for c*regexp at beginning of text */
int matchstar(int c, short regexp[], char *text)
{
    do {    /* a * matches zero or more instances */
        if (matchhere(regexp, text))
            return 1;
    } while (*text != '\0' && (*text++ == c || c == RE_ANY));
    return 0;
}

/* matchplus: search for c+regexp at beginning of text */
int matchplus(int c, short regexp[], char *text)
{
    if(*text && (*text == c || c == RE_ANY))
	return matchstar(c, regexp, text + 1);
    return 0;
}

/* matchques: search for c?regexp at beginning of text */
int matchques(int c, short regexp[], char *text)
{
    if (*text != '\0' && (c == RE_ANY || c == *text))
        if (matchhere(regexp, text + 1))
	    return 1;
    return matchhere(regexp, text);
}
