// yes(1).

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sysexits.h>

int main(int argc, char *argv[])
{
        char opt;

        while ((opt = getopt(argc, argv, ":h")) != -1) {
                switch (opt) {

                case 'h':
                        puts("Usage: sure [-h] STRING");
                        exit(EX_OK);

                        break;

                case '?':
                        fprintf(stderr, "sure: invalid option -%c", optopt);
                        exit(EX_USAGE);

                        break;
                }
        }

        // Print string.
        if (argc == 1) {
                while (1) {
                        puts("y");
                }

        } else if (argc > 1) {
                while (1) {
                        // Print last argument.
                        puts(argv[argc - 1]);
                }
        }
}
