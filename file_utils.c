#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int read_file(char * filename, char ** buffer) {
    FILE * inputFile = fopen(filename, "r");
    if (inputFile == NULL) {
        fprintf(stderr, "ERROR: could not open input file\n");
        exit(2);
    }

    struct stat st;
    stat(filename, &st);
    int size = st.st_size;

    *buffer = (char *) malloc(sizeof(char) + size * sizeof(char));
    char c;
    (* buffer)[size + 1] = '\0';
    int index = size;
    while (index >= 0) {
        c = fgetc(inputFile);
        // if (c != EOF) {
        (* buffer)[index] = c;
        // }
        index--;
    }

    fclose(inputFile);

    return 0;
}

int write_file(char * filename, char * buffer, int size) {
    FILE * outputFile = fopen(filename, "w+");
    if (outputFile == NULL) {
        fprintf(stderr, "ERROR: could not open output file\n");
        exit(2);
    }

    int result = fputs(buffer, outputFile);
    if (result < 0) {
        fprintf(stderr, "ERROR: error occurred while writing to file\n");
        exit(2);
    }

    fclose(outputFile);

    return 0;
}