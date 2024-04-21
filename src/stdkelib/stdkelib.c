#include "stdkelib.h"

#include "../debugging/debug.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* add_str(const char* a, const char*b){
    char* buffer=malloc( sizeof(char)* 1024 );

    //set all chars to 0
    for (int i=0;i<1024;i++){
        buffer[i]=0;
    }

    strcat(buffer, a);
    strcat(buffer, b);


    return buffer;
}

void panic(char* error_messege, u8 exit_code){
    if(error_messege){
        printf("PANIC: %s",error_messege);
        print_stack_trace();
        exit(exit_code);
    }

    printf("PANIC: ERROR MESSEGE UNDEFINED");
    print_stack_trace();
    exit(exit_code);
}

