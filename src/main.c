

#include "logger/logger.h"
#include "debugging/debug.h"
#include <stdio.h>


extern LOGGER logger;


int main( int argc, char** argv){

    set_logger_dirpath(argv[0]);

    set_logger_log_to_file(1);
    set_logger_log_to_stdin(0);

    logger.log("testing");


    logger.error("error happen");
    logger.log("something else");



    return 0;
}
