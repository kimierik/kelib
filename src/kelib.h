#ifndef __KELIB_H
#define __KELIB_H

//im used to use bool true/ false 
#define false 0
#define true 1

#define bool int

//proper naming scheme for datatypes
#define i8 char
#define u8 unsigned char

#define i16 short
#define u16 unsigned short

#define i32 long
#define u32 unsigned long

#define i64 long long
#define u64 unsigned long long

#define f32 float
#define f64 double
#define f80 long double


// returns a+b 
// creates new string that needs to be freed
char* add_str(const char*a ,const char* b);




typedef struct LOGGER {
    void (*log)(const char*,...)__attribute__((format(printf,1,2)));
    void (*debug)(const char*,...)__attribute__((format(printf,1,2)));
    void (*error)(const char*,...)__attribute__((format(printf,1,2)));

    int __log_to_file;
    char* __path_to_file;
    int __log_to_stdin;
    int __debug_mode;
} LOGGER;



//unrecoverable error
void panic(char* error_messege,u8 exit_code);

// setting to 1 logs all logs to a file
void set_logger_log_to_file(int log);

// setting to 0 removes logging to stdout
void set_logger_log_to_stdout(int log);

// directory where we will put the logs into
void set_logger_dirpath(char* path);






#endif
