#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

typedef int (*HandlerFunction)(char* buffer, int index, va_list arg_list);

int int_length(int n);
int hex_length(unsigned long n);
unsigned long long_length(unsigned long n);
int octal_length(int n);
int to_power(int n, int to_power);
int ftoi(float f);
void my_itoa(unsigned int n, char* buffer);
void hex_to_str(unsigned long decimal, char* str, int hex_length);

void octal_to_str(int decimal, char* str, int octal_length);
int copy_str(char* buffer, int index, char* str);
int handle_char(char* buffer, int index, va_list arg_list);
int handle_string(char* buffer, int index, va_list arg_list);
int handle_int(char* buffer, int index, va_list arg_list);
int handle_pointer(char* buffer, int index, va_list arg_list);
int handle_unsigned_int(char* buffer, int index, va_list arg_list);
int handle_hex(char* buffer, int index, va_list arg_list);
int handle_octal(char* buffer, int index, va_list arg_list);
void init_dispatch_table(HandlerFunction *dispatch_table);