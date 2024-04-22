#include "../kelib.h"

#include <libgen.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

//mkdir
#include <sys/types.h>
#include <sys/stat.h>

void __logger_log( char* str);
void __logger_error( char* str);
void __logger_debug( char* str);


//defined in debug.c
void print_stack_trace(void);
char* get_stack_trace(void);



typedef struct LOGGER {
    void (*log)(char*);
    void (*debug)(char*);
    void (*error)(char*);

    int __log_to_file;
    char* __path_to_file;
    int __log_to_stdin;
    int __debug_mode;
} LOGGER;



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





void __log(char*str,char*color,char*header){

    //set log color
    printf("%s",color);

    if (logger.__log_to_stdin) {
        printf("%s %s\n",header,str);
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

        fprintf(f,"%s %s \n",header, str);
        fclose(f);
        free(path);
    }
}


void __logger_log(char *str){
    __log(str,"\33[1;32m","[LOGGER.LOG]");
}

void __logger_error(char* str){ 
    __log(str,"\33[31;31m","[LOGGER.ERROR]");
    char* stacktrace=get_stack_trace();
    __log(stacktrace,"\33[31;31m","[LOGGER.ERROR]\n");
    free(stacktrace);
}

void __logger_debug( char* str){
    if(logger.__debug_mode){
        __log(str,"\33[1;32m","[LOGGER.DEBUG]");
    }
}












