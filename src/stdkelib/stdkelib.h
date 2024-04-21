#ifndef STDKELIB_H
#define STDKELIB_H

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



// returns a+b 
// creates new string that needs to be freed
char* add_str(const char*a ,const char* b);


//unrecoverable error
void panic(char* error_messege,u8 exit_code);



#endif
