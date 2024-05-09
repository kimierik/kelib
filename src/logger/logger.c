#include "../kelib.h"

#include <libgen.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

//mkdir
#include <sys/types.h>
#include <sys/stat.h>

void __logger_log( const char* str,...);
void __logger_error( const char* str,...);
void __logger_debug( const char* str,...);


//defined in debug.c
void print_stack_trace(void);
char* get_stack_trace(void);






LOGGER logger={
    .log = &__logger_log,
    .error = &__logger_error,
    .debug = &__logger_debug,
    .__log_to_file=0,
    .__path_to_file=0,
    .__log_to_stdin=1,
};


//################################################## 
//#                                                #
//#             PUBLIC DEFINITIONS                 #
//#                                                #
//################################################## 


void set_logger_dirpath(char* path){
    //remove the name executable name
    //we only want the directory of the executable relative to where it is executed form   
    
    //set 0 at the / 
    int len=strlen(path);
    for (int i=len;i>0;i--){
        if (path[i]=='/') {
            path[i]=0;
            break;
        }
        if(i==0){
            logger.error("cannot set path to file");
        }
    }

    logger.__path_to_file=path;
}

void set_logger_log_to_file(int log){
    logger.__log_to_file=log;
}

void set_logger_log_to_stdout(int log){
    logger.__log_to_stdin=log;
}









//################################################## 
//#                                                #
//#             PRIVATE DEFINITIONS                #
//#                                                #
//################################################## 





void __log(const char*str, const char*color, const char*header, va_list args){


    //set log color
    printf("%s",color);

    if (logger.__log_to_stdin) {
        printf("%s ",header);
        vprintf(str, args);
        //printf("%s %s\n",header,str);
    }

    if (logger.__log_to_file) {

        // we do not have path to directory
        if(!logger.__path_to_file){
            panic("attempting to log to a file but dirpath is not set", 1);
        }
        
        char* path=add_str(logger.__path_to_file, "/logs/log.log");

        FILE *f = fopen(path, "a");

        //if we do not have the /logs directory
        if(errno ==2){
            char* dirpath=add_str(logger.__path_to_file, "/logs");
            mkdir(dirpath, 0700);
            f = fopen(path, "a");
            free(dirpath);
        }

        fprintf(f,"%s ",header);
        vfprintf(f, str, args);

        //cleanup
        fclose(f);
        free(path);
    }

    //reset color
    printf("\033[39m\033[49m");

}


void __logger_log(const char *str,...){
    va_list args;
    va_start(args, str);
    __log(str,"\33[1;32m","[LOGGER.LOG]",args);
    va_end(args);
}

void __logger_error(const char* str,...){ 
    va_list args;
    va_start(args, str);
    __log(str,"\33[31;31m","[LOGGER.ERROR]",args);
    char* stacktrace=get_stack_trace();

    //something is fucked here ards should not be her
    __log(stacktrace,"\33[31;31m","[LOGGER.STACKTRACE]\n",args);
    free(stacktrace);
    va_end(args);
}

void __logger_debug( const char* str,...){
    va_list args;
    va_start(args, str);
    if(logger.__debug_mode){
        __log(str,"\33[1;32m","[LOGGER.DEBUG]",args);
    }
    va_end(args);
}












