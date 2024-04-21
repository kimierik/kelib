#ifndef LOGGER_H
#define LOGGER_H




// add log id or something
// so we can have different log files 


typedef struct LOGGER {
    void (*log)(char*);
    void (*debug)(char*);
    void (*error)(char*);

    int __log_to_file;
    char* __path_to_file;
    int __log_to_stdin;
    int __debug_mode;
} LOGGER;



// setting to 1 logs all logs to a file
void set_logger_log_to_file(int log);

// setting to 0 removes logging to stdout
void set_logger_log_to_stdout(int log);

// directory where we will put the logs into
void set_logger_dirpath(char* path);




#endif
