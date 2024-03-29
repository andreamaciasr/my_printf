#include "my_printf.h"

int my_printf(char * restrict format, ...) {
    va_list arg_list;
    va_start(arg_list, format);

    HandlerFunction dispatch_table[200] = {0};

    char buffer[400];
    int index = 0;
    int i = 0;

    init_dispatch_table(dispatch_table);

    while (format[i] != '\0') 
    {
        if (format[i] == '%') 
        {
            i++;
            int f = format[i];
            HandlerFunction handler = dispatch_table[f];
            if (handler != 0) 
            {
                index = handler(buffer, index, arg_list);
            }
            i++;
        } 
        else 
        {
            buffer[index] = format[i];
            i++;
            index++;
        }
    }

    buffer[index] = '\0';
    write(1, buffer, index);
    va_end(arg_list);
    return index;
}

int main (void)
{   
    int a = 33;
    int n = 333;

    my_printf("This is a char: %c, and int: %d\n", a);
    my_printf("This is a string: %s\n", "abcd");
    my_printf("This is an int: %d\n", a);
    my_printf("This is a pointer: %p\n", &a);
    my_printf("Null str: %s", NULL);
    my_printf("This is a unsigned int: %u\n", n);
    my_printf("This is a hex: %x\n", n);
    my_printf("This is an octal: %o\n", n);

}