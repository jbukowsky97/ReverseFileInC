#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

/***********************
* reads the provided file reverse into a char *
*
* @returns success of reading the file
************************/
int read_file(char * filename, char ** buffer) {
    //open up inputFile for read
    FILE * inputFile = fopen(filename, "r");
    //check for error
    if (inputFile == NULL) {
        fprintf(stderr, "ERROR: could not open input file\n");
        exit(2);
    }

    //get size of characters in file
    //credit -> woodring
    struct stat st;
    stat(filename, &st);
    int size = st.st_size;

    //allocate correct size for (char *) buffer
    *buffer = (char *) malloc(sizeof(char) + size * sizeof(char));
    //check for malloc error
    if (*buffer == NULL) {
        fprintf(stderr, "ERROR: failed to malloc");
        exit(12);
    }
    //make last char the null pointer to signify end of string
    (* buffer)[size] = '\0';
    //loop from the back to the front to reverse file's contents
    int index = size - 1;
    while (index >= 0) {
        (* buffer)[index] = fgetc(inputFile);
        index--;
    }

    //close file for os
    fclose(inputFile);

    return 0;
}

/***********************
* writes to the given file the char * passed in
*
* note: size unneeded in my implementation because I
* added null terminator to the end of the (char *) buffer
*
* @returns result of opening the file for write+
************************/
int write_file(char * filename, char * buffer, int size) {
    //open up outputFile for write+, to create if file doesn't exist
    FILE * outputFile = fopen(filename, "w+");
    //check for error
    if (outputFile == NULL) {
        fprintf(stderr, "ERROR: could not open output file\n");
        //free memory
        free(buffer);
        exit(2);
    }

    //write (char *) buffer to file, get result of writing to check for errors
    int result = fputs(buffer, outputFile);
    if (result < 0) {
        fprintf(stderr, "ERROR: error occurred while writing to file\n");
        exit(2);
    }

    //close file for os
    fclose(outputFile);

    return 0;
}
