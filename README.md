# Welcome to My Printf
***

This is a re-implementation of the printf() function from the C standard library. It uses a variadic function, a dispatch table, and buffer manipulation for formatting output. It was written to handle different data types, format specifiers, and error cases.

My code is well-organized with a modular approach, allowing for easy maintenance and extensibility. The use of a dispatch table and clear control flow enhances code readability and organization.

Through this project, I learned how to use an array of function pointers, as well as manipulate string buffers and convert data types. Additionally, I gained knowledge on writing well-designed programs by splitting them into multiple files and using concise functions.

## Installation
`git clone git@github.com:andreamaciasr/my_printf.git`  
`cd my_printf`  
`make`  
`./my_printf`  

## Usage
my_printf function receives a data type specifier and the data that needs to be printed.

**This function can print:**
```
%c - chars
%s - strings
%d - signed decimals
%u - unsigned decimal
%o - unsigned octals
%h - unsigned hexadecimals
%p - memory addresses
```