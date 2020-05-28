#ifndef HIGH_SCORE_VARIABLE_H_INCLUDED
#define HIGH_SCORE_VARIABLE_H_INCLUDED

#include"iGraphics.h"

char player_name[5][100]={"X","y","Z","Abc","xyz"};

void highScoreShow()
{

			iSetColor(255,255,255);

			iText(410,540,"PlayerName",GLUT_BITMAP_TIMES_ROMAN_24);

			iSetColor(0,255,0);

			iText(420,450,player_name[0],GLUT_BITMAP_TIMES_ROMAN_24);

			iSetColor(0,255,0);
			
			iText(420,360,player_name[1],GLUT_BITMAP_TIMES_ROMAN_24);
			
			iSetColor(0,255,0);
			
			iText(420,270,player_name[2],GLUT_BITMAP_TIMES_ROMAN_24);

			iSetColor(0,255,0);
			
			iText(420,180,player_name[3],GLUT_BITMAP_TIMES_ROMAN_24);

			iSetColor(0,255,0);
			
			iText(420,90,player_name[4],GLUT_BITMAP_TIMES_ROMAN_24);

			iSetColor(255,255,255);

			iText(840,540,"Level",GLUT_BITMAP_TIMES_ROMAN_24);
			
			iSetColor(0,255,0);

			iText(840,450,"3",GLUT_BITMAP_TIMES_ROMAN_24);

			iSetColor(0,255,0);

			iText(840,360,"2",GLUT_BITMAP_TIMES_ROMAN_24);

			iSetColor(0,255,0);

			iText(840,270,"2",GLUT_BITMAP_TIMES_ROMAN_24);

			iSetColor(0,255,0);

			iText(840,180,"1",GLUT_BITMAP_TIMES_ROMAN_24);

			iSetColor(0,255,0);

			iText(840,90,"0",GLUT_BITMAP_TIMES_ROMAN_24);



}


#endif //HIGH_SCORE_VARIABLE_H_INCLUDED