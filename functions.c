#include "my_printf.h"


int int_length(int n)
{
    int counter = 0;

    if (n < 0)
    {
        n = n * -1;
    }
    if (n == 0)
    {
        return 1; 
    }
    while (n > 0)
    {
        n = n / 10;
        counter++;
    }
    return counter;
}

int hex_length(unsigned long n)
{
    int counter = 0;

    if (n == 0)
    {
        return 1; 
    }
    while (n > 0)
    {
        n = n / 16;
        counter++;
    }
    return counter;
}

unsigned long long_length(unsigned long n)
{
    int counter = 0;

    if (n == 0)
    {
        return 1; 
    }
    while (n > 0)
    {
        n = n / 16;
        counter++;
    }
    return counter;
}

int octal_length(int n)
{
    int counter = 0;

    if (n == 0)
    {
        return 1; 
    }
    while (n > 0)
    {
        n = n / 8;
        counter++;
    }
    return counter;
}

int to_power(int n, int to_power)
{
    if (to_power == 0)
    {
        return 1;
    }
    int temp = n;
    for (int i = 0; i < to_power - 1; i++)
    {
        n = n * temp;
    }
    return n; 
}

int ftoi(float f)
{
    while (f < 0)
    {
        f = f * 10;
    }
    return f;
}

void my_itoa(unsigned int n, char* buffer)
{
    int temp; 
    int length = int_length(n);
    int index = 0;

    while (length != 0)
    {
        int dividend = to_power(10, length - 1);
        temp = n / dividend;
        length--;

        buffer[index] = '0' + temp;
        n = n - temp * dividend; 
        index++;
    }
    buffer[index] = '\0';
}

void hex_to_str(unsigned long decimal, char* str, int hex_length)
{
    char hex_arr[] = "0123456789abcdef";

    for (int i = 0; i < hex_length; i++)
    {   
        int mod = decimal % 16;
        decimal = decimal / 16;
        str[hex_length -1 - i] = hex_arr[mod];
    }
}

void octal_to_str(int decimal, char* str, int octal_length)
{
    char octal_arr[] = "01234567";

    for (int i = 0; i < octal_length; i++)
    {   
        int mod = decimal % 8;
        decimal = decimal / 8;
        str[octal_length -1 - i] = octal_arr[mod];
    }
}

int copy_str(char* buffer, int index, char* str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        buffer[index] = str[i];
        i++;
        index++;
    }
    return index;
}

int handle_char(char* buffer, int index, va_list arg_list)
{
    char c = va_arg(arg_list, int);
    buffer[index] = c;
    index++;
    return index;
}

int handle_string(char* buffer, int index, va_list arg_list)
{
    char* str = va_arg(arg_list, char*);
    if (str == NULL)
    {
        str = "(null)!\n";
    }
    index = copy_str(buffer, index, str);
    return index;
    
}

int handle_int(char* buffer, int index, va_list arg_list)
{
    int value = va_arg(arg_list, int);
    int value_length = int_length(value);
    char int_buffer[value_length + 2];

    if (value < 0)
    {
        buffer[index] = '-';
        value = value * -1;
        index++;
    }

    my_itoa(value, int_buffer);
    index = copy_str(buffer, index, int_buffer);
    return index;
}

int handle_pointer(char* buffer, int index, va_list arg_list)
{
    buffer[index] = '0';
    buffer[index + 1] = 'x';
    index += 2;

    unsigned long address = va_arg(arg_list, unsigned long);
    unsigned long length = long_length(address);
    char address_buffer[length + 1];
    address_buffer[length] = '\0';
    hex_to_str(address, address_buffer, length);

    index = copy_str(buffer, index, address_buffer);
    return index;
}

int handle_unsigned_int(char* buffer, int index, va_list arg_list)
{
    int value = va_arg(arg_list, int);
    int value_length = int_length(value);
    char int_buffer[value_length + 2];

    my_itoa(value, int_buffer);

    index = copy_str(buffer, index, int_buffer);
    return index;
}

int handle_hex(char* buffer, int index, va_list arg_list)
{
    int decimal = va_arg(arg_list, int);
    int length = hex_length(decimal);
    char hex_buffer[length + 1];
    hex_buffer[length] = '\0';
    hex_to_str(decimal, hex_buffer, length);

    index = copy_str(buffer, index, hex_buffer);
    return index;                   
}

int handle_octal(char* buffer, int index, va_list arg_list)
{
    int decimal = va_arg(arg_list, int);
    int length = octal_length(decimal);
    char octal_buffer[length + 1];
    octal_buffer[length] = '\0';
    octal_to_str(decimal, octal_buffer, length);

    index = copy_str(buffer, index, octal_buffer);
    return index;
}

void init_dispatch_table(HandlerFunction *dispatch_table) 
{
    dispatch_table['c'] = &handle_char;
    dispatch_table['s'] = &handle_string;
    dispatch_table['d'] = &handle_int;
    dispatch_table['p'] = &handle_pointer;
    dispatch_table['u'] = &handle_unsigned_int;
    dispatch_table['x'] = &handle_hex;
    dispatch_table['o'] = &handle_octal;
}
