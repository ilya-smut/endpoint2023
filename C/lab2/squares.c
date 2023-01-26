#include <stdio.h>
int square(int num);

int main(){
    int i;
    for (i = 1; i < 11; i++){
        printf("%d: %d\n", i, square(i));
    }
}

int square(int num){
    return num * num;
}