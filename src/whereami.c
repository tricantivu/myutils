// Re-write of pwd(1)

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sysexits.h>
#include <linux/limits.h>

int main(int argc, char *argv[])
{
        char opt;
        int no_ln;

        while ((opt = getopt(argc, argv, ":hP")) != -1) {
                switch (opt) {
                case 'h':
                        puts("Usage: whereami [-h] [-P]");
                        exit(EX_OK);

                        break;

                case 'P':
                        no_ln = 1;
                        break;

                case '?':
                        fprintf(stderr, "whereami: invalid option -%c\n", opt);
                        exit(EX_USAGE);

                        break;
                }
        }

        // Resolve symlinks in path.
        if (no_ln) {
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
