#include <stdio.h>

#include "safe_printf.h" // include header

int main()
{
    long l1 = 10;

    safe_printf("%ld\n", l1);  // (O) Correct usage
    // safe_printf("%s\n", l1);  // (X) Warning in GCC/Clang (format mismatch)

    return 0;
}
