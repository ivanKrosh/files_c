#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define PASS 60

int main(int argc, char *argv[])
{
    FILE *in = stdin;                            /* без аргументів - */
    FILE *out = stdout;                          /* стандартні потоки */

    if (argc == 3) {
        in = fopen(argv[1], "r");
        if (in == NULL) {
            perror(argv[1]);
            return 1;
        }
        out = fopen(argv[2], "w");
        if (out == NULL) {
            perror(argv[2]);
            fclose(in);
            return 1;
        }
    }

    char name[32];
    int mark, total = 0, kept = 0;
    while (fscanf(in, "%31s %d", name, &mark) == 2) {
        total++;
        if (mark >= PASS) {
            fprintf(out, "%s %d\n", name, mark);
            kept++;
        }
    }
    fprintf(stderr, "kept %d of %d\n", kept, total);

    if (in != stdin)
        fclose(in);
    if (out != stdout)
        fclose(out);
    return 0;
}
