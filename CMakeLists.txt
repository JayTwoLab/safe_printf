cmake_minimum_required(VERSION 3.16)

project(safe_printf LANGUAGES C)

add_executable(safe_printf main.c
    safe_printf.h)

include(GNUInstallDirs)
install(TARGETS safe_printf
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
