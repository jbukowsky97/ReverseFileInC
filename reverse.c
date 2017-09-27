#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"

/***********************
* main function to manage and run program
*
* used https://www.tutorialspoint.com/cprogramming/
* for all external learning done about I/O and pointers
* and c in general
*
* @returns result to the system as integer
************************/
int main(int argc, char ** argv) {
    //check to make sure arguments match desired
    if (argc != 3) {
        //print usage for user
        printf("usage:\n\t./reverse INPUT_FILENAME OUTPUT_FILENAME\n");
        return 0;
    }

    //create char * initially null because unkown desired size
    char * buffer = (void *) NULL;

    //read from file, also storing size of buffer
    int size = read_file(argv[1], &buffer);

    //reverse array in log(n) approach
    int left = 0;
    int right = size - 1;
    while(left < right) {
        char temp = buffer[left];
        buffer[left] = buffer[right];
        buffer[right] = temp;
        left++;
        right--;
    }

    //write to file
    write_file(argv[2], buffer, size);
    
    //free memory from (char *) buffer
    free(buffer);

    //successfully terminate program
    return 0;
}
