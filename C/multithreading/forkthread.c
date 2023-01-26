#include <pthread.h>
#include <stdio.h>
/*#include <stdlib.h>*/
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>

int value = 0;
void *runner(void *param);
int main(int argc, char *argv[])
{
    pid_t pid;
    pthread_t tid;
    pthread_attr_t attr;
    pid = fork();
    if (pid == 0)
    {
        pthread_attr_init(&attr);
        pthread_create(&tid, &attr, runner, argv[1]);
        pthread_join(tid, NULL);
        printf("CHILD: %d\n", value);
    }
    else if(pid > 0)
    {
        wait(NULL);
        printf("PARENT: %d\n", value);
    }
}
void *runner(void *param){
    value = 5;
    pthread_exit(0);
}