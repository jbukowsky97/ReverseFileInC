#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"

int main(int argc, char ** argv) {
    if (argc != 3) {
        printf("usage:\n./reverse INPUT_FILENAME OUTPUT_FILENAME\n");
        exit(0);
    }

    char c = 'h';
    char * buffer = (void *) NULL;
    read_file(argv[1], &buffer);

    write_file(argv[2], buffer, 0);
    
    return 0;
}

//https://www.tutorialspoint.com/cprogramming/c_file_io.htm
