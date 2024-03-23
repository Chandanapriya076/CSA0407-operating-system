#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096
int main(int argc, char *argv[]) {
    char buf[4096];
    int fd1 = open(argv[1], O_RDONLY), fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644), n;
    while ((n = read(fd1, buf, sizeof(buf))) > 0) write(fd2, buf, n);
    close(fd1); close(fd2);
    return 0;
}

