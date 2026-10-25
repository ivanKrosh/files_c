#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <errno.h>
#include <io.h>

int main(int argc, char *argv[])
{
    if (argc < 3) {
        fprintf(stderr, "usage: Demo2_open <file> <mode>\n");
        return 2;
    }
    const char *path = argv[1];
    const char *mode = argv[2];

    FILE *f = fopen(path, mode);
    if (f == NULL) {
        perror(path);                            /* текст помилки - у stderr */
        fprintf(stderr, "  errno = %d\n", errno);
        return 1;
    }

    int fd = _fileno(f);
    printf("fopen(\"%s\", \"%s\") = %p\n", path, mode, (void *)f);
    printf("  descriptor = %d   (stdin %d, stdout %d, stderr %d)\n",
           fd, _fileno(stdin), _fileno(stdout), _fileno(stderr));
    printf("  HANDLE     = %p\n", (void *)_get_osfhandle(fd));

    fclose(f);
    return 0;
}
