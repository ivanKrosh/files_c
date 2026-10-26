#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* друкує всі байти файлу в шістнадцятковому вигляді */
static void dump(const char *name)
{
    FILE *f = fopen(name, "rb");                 /* "rb": байти як є */
    if (f == NULL) {
        perror(name);
        return;
    }
    int c, n = 0;
    printf("%-10s:", name);
    while ((c = fgetc(f)) != EOF) {              /* наступний байт або EOF */
        printf(" %02X", c);
        n++;
    }
    printf("  (%d bytes)\n", n);
    fclose(f);
}

int main(void)
{
    int a[3] = { 7, 1000000, -25 };

    FILE *t = fopen("text.txt", "w");            /* текстовий файл */
    FILE *b = fopen("binary.bin", "wb");         /* двійковий файл */
    if (t == NULL || b == NULL) {
        perror("fopen");
        return 1;
    }

    for (int i = 0; i < 3; i++)
        fprintf(t, "%d\n", a[i]);                /* число -> цифри */
    fwrite(a, sizeof a[0], 3, b);                /* байти з пам'яті як є */

    fclose(t);
    fclose(b);
    printf("text.txt and binary.bin written\n\n");

    dump("text.txt");
    dump("binary.bin");
    return 0;
}
