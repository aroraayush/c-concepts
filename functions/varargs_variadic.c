// Variable number of arguments macros defined in stdarg.h.
// These are stored in the call stack
// Example : printf()

#include <stdio.h>
#include <stdarg.h>

void print_integers(int length, ...){
    va_list args;   // List of arguments
    va_start(args, length);

    for (int i = 0; i< length; i++){
        // Use va_arg to pull the arguments one by one
        // We have to tell va_arg, what the type of argument is
        // char, floats and short not allowed
        // int, pointers, double works
        int value = va_arg(args, int);
        printf("Value at idx (%d) = %d\n",i,value);
    }

    // End varargs
    va_end(args);
}

int main(int argc, char **argv){
    
    // If we pass len less, less variables with be printed
    // If more, garbage values will be printed

    print_integers(3, 12, 14, 67);
    // Value at idx (0) = 12
    // Value at idx (1) = 14
    // Value at idx (2) = 67

}


