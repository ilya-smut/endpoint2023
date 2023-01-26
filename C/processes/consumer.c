#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>

int main()
{
    const int SIZE = 4096;
    const char *name = "OS";
    const char *message_0 = "Hello";
    const char *message_1 = "World!";
    int fd;
    char *ptr;

    fd = shm_open(name, O_RDWR, 0666);
    printf("File Descriptor: %d\n", fd);
    ptr = (char *) mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    printf("%p\n", ptr);
    printf("%s", (char *)ptr);
    shm_unlink(name);
    return 0;
}