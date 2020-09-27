Pass address of a function as parameter to another function as shown below

#include <stdio.h>

void print();
void execute(void());

int main()
{
    execute(print); /// sends address of print
    return 0;
}

void print()
{
    printf("Hello!");
}

void execute(void f()) /// receive address of print
{
    f();
}
Also we can pass function as parameter using function pointer

#include <stdio.h>

void print();
void execute(void (*f)());

int main()
{
    execute(&print); /// sends address of print
    return 0;
}

void print()
{
    printf("Hello!");
}

void execute(void (*f)()) /// receive address of print
{
    f();
}
