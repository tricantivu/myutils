// Re-write of pwd(1)

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sysexits.h>
#include <linux/limits.h>

int main(int argc, char *argv[])
{
        char opt;
        int ln_opt;

        while ((opt = getopt(argc, argv, ":hn")) != -1) {
                switch (opt) {
                case 'h':
                        puts("Usage: whereami [-h] [-n]");
                        exit(EX_OK);

                        break;

                case 'n':
                        ln_opt = 1;
                        break;

                case '?':
                        fprintf(stderr, "whereami: invalid option -%c\n", opt);
                        exit(EX_USAGE);

                        break;
                }
        }

        // Resolve symlinks in path.
        if (ln_opt) {
                char cwd[PATH_MAX];

                if (getcwd(cwd, sizeof(cwd)) == NULL) {
                        fputs("whereami: couldn't get current directory.", stderr);
                        exit(EX_SOFTWARE);
                } else
                        puts(cwd);

                // Show path with symlinks.
        } else {
                puts(getenv("PWD"));
        }
}
