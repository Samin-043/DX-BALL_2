#ifndef CONTAIN_NAME_H_INCLUDED
#define CONTAIN_NAME_H_INCLUDED

#include<stdio.h>
#include<string.h>

int main()
{

    FILE *fa;
    char s[10][100];
    fa=fopen("name.txt","r");

    for(int i=0;i<10;i++)
    {
        fscanf(fa,"%s",s[i]);
    }

    /*for(int i=0;i<10;i++)
    {
        printf("%s\n",s[i]);
    }
    */

    fclose(fa);

    return 0;
}



#endif // CONTAIN_NAME_H_INCLUDED
