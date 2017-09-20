#include <stdio.h>
#include "file_utils.h"

/***********************
* main function to manage and run program
*
* used https://www.tutorialspoint.com/cprogramming/
* for all learning done about I/O and pointers
* and c in general
*
* @returns result to the system as integer
************************/
int main(int argc, char ** argv) {
    //check to make sure arguments match desired
    if (argc != 3) {
        //print usage for user
        printf("usage:\n./reverse INPUT_FILENAME OUTPUT_FILENAME\n");
        return 0;
    }

    //create c-string initially null because unkown desired size
    char * buffer = (void *) NULL;

    read_file(argv[1], &buffer);

    write_file(argv[2], buffer, 0);
    
    return 0;
}
