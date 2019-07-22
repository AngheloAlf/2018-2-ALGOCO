/* match: search for regexp anywhere in text */
int match(char *regexp, char *text);

/* matchhere: search for regexp at beginning of text */
int matchhere(char *regexp, char *text);

/* matchstar: search for c*regexp at beginning of text */
int matchstar(int c, char *regexp, char *text);

/* matchplus: search for c+ regexp at beginning of text */
int matchplus(int c, char *regexp, char *text);

/* matchqustion: search for c? regexp at beginning of text */
int matchqustion(int c, char *regexp, char *text);

/* matchscape: search for \c regexp at beginning of text */
int matchscape(int c, char *regexp, char *text);