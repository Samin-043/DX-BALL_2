#ifndef SCOREPLAYER_H_INCLUDED
#define SCOREPLAYER_H_INCLUDED
#include "playerdata.h"

#include<stdio.h>

int main()
{

    FILE *fa;
    fa=fopen("game_result.txt","r");

    char name[10][100];
    int score;
    int level;
    int i;
	
	

    for(i=0;i<5;i++)
    {
        fscanf(fa,"%s %d %d",name,score,level);


    }

    for(i=0;i<5;i++)
    {

        printf("%s %d %d\n",name,score,level);

    }

    fclose(fa);


}

#endif // SCOREPLAYER_H_INCLUDED
