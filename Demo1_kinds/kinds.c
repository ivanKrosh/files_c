#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int a[3] = { 7, 1000000, -25 };

    FILE *t = fopen("nums.txt", "w");            /* текстовий файл */
    FILE *b = fopen("nums.bin", "wb");           /* двійковий файл */
    if (t == NULL || b == NULL) {
        perror("fopen");
        return 1;
    }

    for (int i = 0; i < 3; i++)
        fprintf(t, "%d\n", a[i]);                /* число -> цифри */
    fwrite(a, sizeof a[0], 3, b);                /* байти з пам'яті як є */

    fclose(t);
    fclose(b);
    printf("nums.txt and nums.bin written\n");
    return 0;
}
