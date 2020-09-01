#include<stdio.h>

int fun(){
    static int x = 0; ///will remain until the program ends
    return x++;
}
int main(){
    printf("%d",fun());
    printf("%d",fun());
}
