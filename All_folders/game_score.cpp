#include<stdio.h>
#include<string.h>

void playerScore()
{

    FILE *f;
    char name[100]="Sakib";
    int save_score=380;
    int level=2;

    f=fopen("GameDataSave.txt","a");


        fprintf(f,"%s\t",name);
        fprintf(f,"%d\t",level);
        fprintf(f,"%d\n",save_score);


    fclose(f);

}


int main()
{

    playerScore();

    return 0;
}
