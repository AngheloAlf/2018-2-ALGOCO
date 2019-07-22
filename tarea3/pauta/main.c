/**
 * @file  main.c
 * @brief Main program for homework 3, INF-221, 2018-10-15
 *        A grep(1) "replacement"
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "match.h"

#define BUFSZ  1024

int main(int argc, char *argv[])
{
	FILE *infile;
	char buffer[BUFSZ];

	if(argc != 3) {
		fprintf(stderr, "usage: %s regex file\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if((infile = fopen(argv[2], "r")) == NULL) {
		fprintf(stderr, "%s: can't open %s\n", argv[0], argv[2]);
		exit(EXIT_FAILURE);
	}
	
	while(fgets(buffer, BUFSZ, infile)) {
		char *p = strchr(buffer, '\n');
		if(p)
			*p = '\0';
		if(match(argv[1], buffer))
			printf("%s\n", buffer);
	}
	exit(EXIT_SUCCESS);
}
