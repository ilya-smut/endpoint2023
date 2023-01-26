#include <stdio.h>

int main()
{
    int var1 = 11;
    int var2 = 22;
    int var3 = 33;

    printf("var1 has value %d and located at memory address %p\n", var1, &var1);
    printf("var2 has value %d and located at memory address %p\n", var2, &var2);
    printf("var3 has value %d and located at memory address %p\n", var3, &var3);

    int* ptr;
    ptr = &var1;
    var2 = *ptr;
    *ptr = var3;

    printf("\nvar1 has value %d and located at memory address %p\n", var1, &var1);
    printf("var2 has value %d and located at memory address %p\n", var2, &var2);
    printf("var3 has value %d and located at memory address %p\n", var3, &var3);


}