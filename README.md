# safe_printf

- `safe_printf()`
   -  safe altrenative function of `printf()`.

### Code

```cpp
#include "safe_printf.h" // include header

int main()
{
    long l1 = 10;

    safe_printf("%ld\n", l1);  // ✅ Correct usage
 // safe_printf("%s\n", l1);   // ❌ Warning in GCC/Clang (format mismatch)

    return 0;
}
```

