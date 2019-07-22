#include "match.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void checkCommandLine(int argc, char *argv[]){
    if(argc < 3){
        printf("Usage: %s <expression> <file>\n", argv[0]);
        exit(1);
    }
}

void testError(bool expression, const char *message){
    if(expression){
        fprintf(stderr, "%s\n", message);
        exit(2);
    }
}

char *readFullFile(const char *fileName){
    FILE *opened = fopen(fileName, "r");
    testError(opened == NULL, "Couldn't open file.");

    testError(fseek(opened, 0, SEEK_END) != 0, "fseek failed.");
    long size = ftell(opened); 
    testError(fseek(opened, 0, SEEK_SET) != 0, "fseek failed.");

    char *fullFile = (char *)malloc(sizeof(char) * size);
    testError(fullFile == NULL, "malloc failed.");

    size_t readed = fread(fullFile, sizeof(char), size, opened);
    testError(readed != size, "fread failed.");
    fclose(opened);

    return fullFile;
}

int main(int argc, char *argv[]){
    checkCommandLine(argc, argv);
    char *fullFile = readFullFile(argv[2]);

    for(char *tok = strtok(fullFile, "\n"); tok != NULL; tok = strtok(NULL, "\n")){
        if(match(argv[1], tok)){
            printf("%s\n", tok);
        }
    }

    free(fullFile);
    return 0;
}
