#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void)
{
    char write_msg[BUFFER_SIZE] = "Greetings\n";
    char read_msg[BUFFER_SIZE];
    int fd[2];
    pid_t pid;

    /* CREATING OF THE PIPE*/
    if (pipe(fd) == -1){
        fprintf(stderr, "Pipe failed\n");
        return 1;
    }


    /*CREATING THE CHILD PROCESS*/
    pid = fork();

    /*PARENT*/
    if (pid > 0)
    {
        close(fd[READ_END]);
        write(fd[WRITE_END], write_msg, strlen(write_msg)+1);
        close(fd[WRITE_END]);
    }
    else /*CHILD*/
    {
        close(fd[WRITE_END]);
        read(fd[READ_END], read_msg, BUFFER_SIZE);
        printf("read %s\n", read_msg);
        close(fd[READ_END]);
    }
    return 0;
    
}