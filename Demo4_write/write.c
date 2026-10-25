#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

#define N 5

const char *names[N] = { "Antoniuk", "Boiko", "Hrytsenko", "Moroz", "Shevchuk" };
int marks[N] = { 88, 52, 71, 95, 64 };

void report(FILE *out)
{
    int sum = 0;
    fputs("Group 432\n", out);
    fputs("--------------\n", out);
    for (int i = 0; i < N; i++) {
        fprintf(out, "%-10s %3d\n", names[i], marks[i]);
        sum += marks[i];
    }
    fputs("--------------\n", out);
    fprintf(out, "%-10s %5.1f\n", "average", (double)sum / N);
}

int main(void)
{
    report(stdout);                              /* на екран */

    FILE *f = fopen("report.txt", "w");
    if (f == NULL) {
        perror("report.txt");
        return 1;
    }
    report(f);                                   /* у файл - той самий код */
    fclose(f);

    FILE *lf = fopen("log.txt", "a");            /* дописати в кінець */
    if (lf == NULL) {
        perror("log.txt");
        return 1;
    }
    time_t now = time(NULL);
    char stamp[20];
    strftime(stamp, sizeof stamp, "%Y-%m-%d %H:%M:%S", localtime(&now));
    fprintf(lf, "%s  report.txt: %d students\n", stamp, N);
    fclose(lf);

    printf("\nreport.txt written, one line added to log.txt\n");
    return 0;
}
