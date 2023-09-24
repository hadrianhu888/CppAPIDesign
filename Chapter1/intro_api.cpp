/**
 * @file intro_api.cpp
 * @brief A program that prints "Hello World!" to the console using different APIs based on the platform.
 * @version 0.1
 * @date 2023-09-24
 */

#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef __cplusplus
#include <iostream>
#endif

#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef __cplusplus
#include <iostream>
#endif

/**
 * @brief This program demonstrates different ways to output "Hello World!" message based on the platform.
 * 
 * The program uses preprocessor directives to check the platform and selects the appropriate API to output the message.
 * If the platform is __STRICT_ANSI__, the message is printed to the console using printf.
 * If the platform is _WIN32, the message is displayed in a message box using MessageBox.
 * If the platform is __PRINTF_DEPRECATED__, the message is printed to the console using fprintf.
 * If the platform is __PRINTF_VECTOR__, the message is printed to the console using printf and an array of strings.
 * If the platform is __cplusplus, the message is printed to the console using std::cout.
 * If the platform is not recognized, a preprocessor error is generated.
 * 
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line argument strings.
 * @return int The exit code of the program.
 */
int main(int argc, char *argv[]) {
#if defined(__STRICT_ANSI__)
  printf("Hello World!");
#elif defined(_WIN32)
  MessageBox(NULL, "Hello World!", "Message", MB_OK);
#elif defined(__PRINTF_DEPRECATED__)
  fprintf(stdout, "Hello World!\n");
#elif defined(__PRINTF_VECTOR__)
  const char *lines[2] = {"Hello", "World!", NULL};
  printf("%s %s\n", lines[0], lines[1]);
#elif defined(__cplusplus)
  std::cout << "Hello World!" << std::endl;
#else
#error "No terminal output API found"
#endif
  return 0;
}
