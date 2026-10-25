#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <direct.h>
#include <windows.h>

void where(void)
{
    char cwd[MAX_PATH], full[MAX_PATH];
    _getcwd(cwd, sizeof cwd);
    _fullpath(full, "marks.txt", sizeof full);
    printf("current dir : %s\n", cwd);
    printf("marks.txt   : %s\n", full);

    FILE *f = fopen("marks.txt", "r");
    if (f == NULL) {
        perror("marks.txt");
        return;
    }
    printf("marks.txt opened\n");
    fclose(f);
}

void slash(void)
{
    const char *bad = "C:\new\table.txt";
    const char *good = "C:\\new\\table.txt";
    printf("bad : [%s]  strlen = %zu\n", bad, strlen(bad));
    printf("good: [%s]  strlen = %zu\n", good, strlen(good));
}

void crash(void)
{
    FILE *f = fopen("crash.txt", "w");
    if (f == NULL) {
        perror("crash.txt");
        return;
    }
    fprintf(f, "line 1\nline 2\nline 3\n");
    printf("3 lines written to crash.txt\n");
    volatile int *p = NULL;
    *p = 42;                                     /* аварія до fclose */
}

int main(int argc, char *argv[])
{
    SetConsoleOutputCP(CP_UTF8);                 /* кирилиця в шляху */
    setlocale(LC_ALL, ".UTF8");

    const char *what = argc > 1 ? argv[1] : "where";
    if (strcmp(what, "where") == 0)
        where();
    else if (strcmp(what, "slash") == 0)
        slash();
    else if (strcmp(what, "crash") == 0)
        crash();
    else
        fprintf(stderr, "usage: Demo6_pitfalls [where | slash | crash]\n");
    return 0;
}
