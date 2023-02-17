#include <unistd.h>  // for write() and STDERR_FILENO
#include <string.h>  // for strlen()

/**
 * Writes an error message to standard error.
 *
 * This program writes the following error message to standard error:
 *   "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n"
 *
 * The message is terminated by a newline character (\n).
 */
int main() {
char msg[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
size_t len = strlen(msg);
write(STDERR_FILENO, msg, len);
return (1);
}
