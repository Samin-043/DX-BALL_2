#ifndef PLAYERDATA_H_INCLUDED
#define PLAYERDATA_H_INCLUDED
#include<stdio.h>

#include<string.h>

struct playerInfo
{
    char name[100];
    int score;
    int level;

    playerInfo(char name,int score,int level)
    {
        //strcpy(this->name,name);
        this->score=score;
        this->level=level;

    }

    void printinfo()
    {

        printf("%s %d %d\n",this->name,this->score,this->level);

    }



};

struct playerInfo p;

#endif // PLAYERDATA_H_INCLUDED
