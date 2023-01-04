// pwd(1)

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#include <linux/limits.h>

int main(int argc, char *argv[])
{
        char opt;
        int no_ln, use_env;

        while ((opt = getopt(argc, argv, ":hPL")) != -1) {
                switch (opt) {
                case 'h':
                        puts("Usage: whereami [-h] [-P] [-L]");
                        exit(EX_OK);

                        break;

                case 'P':
                        no_ln = 1;
                        break;

                case 'L':
                        use_env = 1;
                        break;

                case '?':
                        fprintf(stderr, "whereami: invalid option -%c\n", optopt);
                        exit(EX_USAGE);

                        break;
                }
        }

        char cwd[PATH_MAX];

        if (getcwd(cwd, sizeof(cwd)) == NULL) {
                fputs("whereami: couldn't get current directory.", stderr);
                exit(EX_SOFTWARE);
        }
        // Resolve symlinks in path.
        if (no_ln)
                puts(cwd);

        // Show path with symlinks.
        else if (use_env) {

                char *pwd = getenv("PWD");

                (strstr("../", pwd) != NULL || strstr("./", pwd) != NULL) ? puts(cwd) : puts(pwd);
        }
}
