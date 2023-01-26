#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum; /*Data to be shared between threads*/
void *runner(void *param); /*Thread will call this function*/

int main(int argc, char *argv[])
{
    /*Creating thread identifiers*/
    pthread_t tid;

    /*Creating thread attributes*/
    pthread_attr_t attr;

    /*Initialising of thread attributes*/
    pthread_attr_init(&attr);

    /*Creating a thread*/
    pthread_create(&tid, &attr, runner, argv[1]);
    /*Using argument with index=1 of the array of arguments because index=0 always contains the name of the command*/

    /*Waiting for thread to exit*/
    pthread_join(tid,NULL);
    /*Last argument is a place where to store a thread exit status. In this example we do not store it anywhere*/

    /*Printing results:*/
    printf("Sum = %d\n", sum);
    /*sum is a global variabe and is shared between different threads*/

}

/*  
    The thread will execute this function
    We put asterisk at the beginning of the name of the function because it is going to return a pointer
*/
void *runner(void *param)
{
    int i, upper = atoi(param);
    sum = 0;
    for (i = 1; i <= upper; i++){
        sum += i;
    } 
    pthread_exit(0);    /*Exiting the thread*/
}