#include <stdio.h>

void mult(int* array_pointer, int* num_ptr)
{
    int i;
    for (i = 0; i < 5; i++)
    {   
        int result = *(array_pointer + i) * *num_ptr;
        printf("%d : %d\n", *(array_pointer+i), result);
    }
}


int main()
{
    int array[5] = {1, 2, 3, 4, 5};
    int i;

    int num = 3;
    int* ptr;
    ptr = &array;

    mult(ptr, &num);
}