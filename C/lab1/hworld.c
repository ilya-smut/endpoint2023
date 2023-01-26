#include <stdio.h>

int main()
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("for itertion number %d\n", i);
    }

    int n = 0;
    while (n < 10)
    {
        n++;
        if (n % 2 == 0)
        {
            printf("The number is even: %d\n", n);
            continue;
        }
        printf("The number is odd: %d\n", n);
    }

    return 0;
}