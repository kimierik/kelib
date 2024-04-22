
#include "../kelib.h"

#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * prints stack trace etc
 * */
void print_stack_trace(void){
    void *array[10];
    char **strings;
    int size, i;

    size = backtrace (array, 10);
    strings = backtrace_symbols (array, size);
    if (strings != NULL) {
        printf ("Obtained %d stack frames.\n", size);
        for (i = 0; i < size; i++){
            printf ("%s\n", strings[i]);
        }
    }

    free (strings);
}


//returned string must be freed
char* get_stack_trace(void){
    void *array[10];
    char **strings;
    int size, i;

    char * returnBuffer =malloc(sizeof(char)*1024);
    for(int i =0;i<1024;i++){
        returnBuffer[i]=0;
    }

    size = backtrace (array, 10);
    strings = backtrace_symbols (array, size);
    if (strings != NULL) {
        sprintf (returnBuffer,"Obtained %d stack frames.\n", size);
        for (i = 0; i < size; i++){
            strcat(returnBuffer, strings[i]);
            strcat(returnBuffer, "\n");
        }
    }
    return returnBuffer;
}


