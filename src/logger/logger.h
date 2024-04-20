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






// if we want to log to a file aswell
void set_logger_log_to_file(int log);
void set_logger_log_to_stdin(int log);
void set_logger_dirpath(char* path);



void __logger_log( char* str);
void __logger_error( char* str);
void __logger_debug( char* str);










#endif
