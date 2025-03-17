////////////////////////////////////////////////////////////////
// safe_printf() : safe altrenative function of printf.
//   https://github.com/JayTwoLab/safe_printf
//   MIT License
////////////////////////////////////////////////////////////////

#ifndef SAFE_PRINTF_H
#define SAFE_PRINTF_H

#include <stdio.h>
#include <stdarg.h>

// Enable format checking for GCC and Clang
#if defined(__GNUC__) || defined(__clang__)
#define FORMAT_CHECK(fmt, args) __attribute__((format(printf, fmt, args)))
#else
#define FORMAT_CHECK(fmt, args)
#endif

// Define snprintf for MSVC to prevent security warnings
#if defined(_MSC_VER)
#define snprintf _snprintf
#endif

// Declaration of safe_printf (with format checking for GCC/Clang)
void safe_printf(const char *format, ...) FORMAT_CHECK(1, 2);

void safe_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

#endif // SAFE_PRINTF_H
