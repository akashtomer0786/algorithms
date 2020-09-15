#include<stdio.h>
int main(void){
    FILE *fp;
    char c;

    fp = fopen("Untitled2sdf.c","r");
    do{
        c=fgetc(fp);
        putchar(c);
    }while(c!=EOF);

    fclose(fp);
}
