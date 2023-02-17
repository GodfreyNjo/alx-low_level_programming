#include <unistd.h>

/**
 * This program prints a message to standard error.
 *
 * The message printed is "and that piece of art is useful" - Dora Korpar, 2015-10-19\n".
 *
 * @return 1 to indicate an error has occurred.
 */
int main() {
// Define the message to be printed.
char msg[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
    
// Determine the length of the message.
size_t len = sizeof(msg) - 1;
    
// Write the message to standard error.
write(STDERR_FILENO, msg, len);
    
// Return an error code.
return (1);
}
