# Safe printf implementation for the C language: safe_printf()

## 1. Why do we need safe_printf()?
- When using printf() in the C language, using an incorrect format specifier can lead to unexpected behavior or program crashes.
- For example, printf("%s", l1);If you try to output a long-type variable to %s, you may get a runtime error.

## 2. Implement safe_printf() that works in GCC, Clang, and MSVC
- Here's an implementation of safe_printf() that enables formatting in GCC and Clang, and works fine in MSVC.

```cpp
#include "safe_printf.h" // include header

int main()
{
    long l1 = 10;

    safe_printf("%ld\n", l1);  // ✅ Correct usage
 // safe_printf( "%s\n", l1);  // ❌ Compile Warning (format mismatch)

    return 0;
}
```

## 3. Key Improvements
- Detecting formatting errors in GCC/Clang
   - __attribute__((format(printf, x, y))) If there is incorrect formatting, a warning is raised at compile time.
   - For example, safe_printf("%s", l1);Alert output.
- Can run securely even on MSVC
   - MSVC does not support __attribute__, so the compiler cannot detect errors, but it is configured to work without errors when executed.
- Processing _snprintf compatible with snprintf
   - MSVC uses _snprintf by default instead of snprintf, so it can be automatically mapped and run safely in a Windows environment.

## 4. Summary
- I have now implemented safe_printf(), which is available in GCC, Clang, and MSVC.
   - If you use GCC/Clang, invalid formatters can be detected at compile time.
   - Even on MSVC, safe_printf() can run without problems.
   - In Windows/Linux/macOS environments, you can provide safe output with the same code.
- Now you can write more secure C code without worrying about formatting errors when using printf()! 🚀

### Compiler
- gcc
- clang
- Visual C++

### License
- MIT License
- https://github.com/JayTwoLab/safe_printf

   
   

