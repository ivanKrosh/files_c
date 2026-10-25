#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void show_lines(const char *path)
{
    FILE *f = fopen(path, "r");
    if (f == NULL) {
        perror(path);
        return;
    }
    char line[64];
    int n = 0;
    while (fgets(line, sizeof line, f) != NULL)
        printf("%d: %s", ++n, line);
    fclose(f);
}

void average(const char *path)
{
    FILE *f = fopen(path, "r");
    if (f == NULL) {
        perror(path);
        return;
    }
    char name[32];
    int mark, sum = 0, count = 0, r;
    while ((r = fscanf(f, "%31s %d", name, &mark)) == 2) {
        sum += mark;
        count++;
    }
    printf("last fscanf = %d\n", r);
    printf("count = %d, sum = %d, average = %.2f\n", count, sum, (double)sum / count);
    fclose(f);
}

void average_feof(const char *path)
{
    FILE *f = fopen(path, "r");
    if (f == NULL) {
        perror(path);
        return;
    }
    char name[32];
    int mark, sum = 0, count = 0;
    while (!feof(f)) {                           /* ПОМИЛКА */
        fscanf(f, "%31s %d", name, &mark);
        printf("  %s %d\n", name, mark);
        sum += mark;
        count++;
    }
    printf("count = %d, sum = %d, average = %.2f\n", count, sum, (double)sum / count);
    fclose(f);
}

int main(int argc, char *argv[])
{
    const char *path = "marks.txt";

    if (argc > 1 && strcmp(argv[1], "feof") == 0) {
        average_feof(path);
        return 0;
    }
    show_lines(path);
    printf("\n");
    average(path);
    return 0;
}
