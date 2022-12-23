// Re-write of clear(1).

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sysexits.h>

void die(char msg[], int status)
{
        fprintf(stderr, "clean: %s\n", msg);

        exit(status);
}

int main(void)
{
        // Check STDOUT is connected to a terminal.
        if (isatty(1) == 1) {
                // Clear terminal.
                if (write(1, "\e[2J\e[H", sizeof("\e[2J\e[H")) == -1)
                        die("can't clear terminal.", EX_IOERR);
        } else
                die("can't clear terminal.", EX_OSERR);
}
