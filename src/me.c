// whoami(1).

#include <pwd.h>
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
                        puts("Usage: me [-h]");
                        exit(EX_OK);

                        break;

                case '?':
                        fprintf(stderr, "me: invalid option -%c.", optopt);
                        exit(EX_USAGE);

                        break;
                }
        }

        if (getpwuid(getuid()) == NULL) {
                fputs("me: failed to get username.", stderr);
                exit(EX_SOFTWARE);
        }

        puts(getpwuid(getuid())->pw_name);
}
