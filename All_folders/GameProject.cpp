#include "iGraphics.h"
#include "imageloadder.h"
#include "BricksHeader.h"
#include "TextInfo.h"
#include "myscore.h"
#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<string.h>

using namespace std;

#define screenWidth 1400    ///1400///1200
#define screenHeight 740    ///700///650
#define yAxisMovement 60
#define totalBricks 6*10


////.........................Bricks design define..................../////


void defineBrick()
{	

    int sum_x=200;      ///200///100
    int sum_y=500;      ///550///450


    for(int i=0;i<totalBricks;i++)
    {

		a[i].red=rand() % 255;
		a[i].green=rand() % 255;
		a[i].blue=rand() % 255;

        a[i].x=sum_x;
        a[i].y=sum_y;

        sum_x+=100;   //100

        if(sum_x>1150)  ///1000
        {

            sum_x=200;   /// 100
            sum_y+=20;   //20

        }

	}

}



int green=0;
int red=0;
int blue=0;

int ball_x=(int)screenWidth/2;            
int ball_y=yAxisMovement;
int radius=10;

int board_x=ball_x-65;  /// 50 ////
int board_y=ball_y-20;
int dx_board=130;   ///100 ///
int dy_board=10;

int finalScore;
int image1;
int score;
int gameover=1;
int EndGame;
//int buton_image;
int hello_image;


//char img[]="images\\right_arrow.png";
char img1[]="images\\simple_color_2.jpg";

////...................backGround Image.....................///

int bg_image;			
char image[]="images\\GameStartPic.png";

void bg_imageShow()
{

	iShowImage(0,0,screenWidth,screenHeight,bg_image);

}



int dx=7;
int dy=5;


int count=0;
int level=0;
int click=0;
char str1[100];


bool isStarted =false;

void myscorefile();
void ballMovement();
void restartGame1();
void restartGame2();
void GameOverPageShow();
void playerScore();
void highScoreShow();



int rightButton=0;
char rightButtonShow[]="images\\arrow_button.png";
char showScore[60];
char showLevel[60];
char showfinalScore[60];


void playerScore()
{

    FILE *f;
    char name[100];
	int save_score=score;
    int level_1=level;

    f=fopen("GameDataSave.txt","a");


        fprintf(f,"%s\t",name);
        fprintf(f,"%d\t",level_1);
        fprintf(f,"%d\n",save_score);


    fclose(f);

}

void totalScore()
{

	itoa(score,showScore,10);
	
	itoa(level,showLevel,10);


	//iText(250,250,showScore);


}

void BorderLine()
{
	/*
	211,211,211-LightGray
	229,228,226-Platinum
	178,190,181-Ash Gray
	145,163,176-Cadet Gray
	237,201,175-Desert Sand

	*/

	iSetColor(145,163,176);

	iFilledRectangle(0,710,screenWidth,30);


}


void scoreShow()
{


	totalScore();

	iSetColor(255,255,255);

	iText(580,718,"Level",GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(0,0,0);

	iFilledRectangle(640,710,70,30);

	//iSetColor(237,201,175);

	iSetColor(0,255,0);

	iText(664,718,showLevel,GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(255,255,255);

	iText(1270,718,"Score",GLUT_BITMAP_TIMES_ROMAN_24); //740

	iSetColor(0,0,0);

	iFilledRectangle(1330,710,70,30);
	
	iSetColor(237,201,175);

	iText(1344,718,showScore,GLUT_BITMAP_TIMES_ROMAN_24);


}

void totalScore_2()
{

	itoa(finalScore,showfinalScore,10);

}


void scoreShow_2()
{

	totalScore_2();


	iSetColor(0,0,0);

	iFilledRectangle(900,345,80,30);

	iSetColor(211,211,211);

	iText(915,350,showScore,GLUT_BITMAP_TIMES_ROMAN_24);


}

char player_name[5][100]={"X","y","Z","Abc","xyz"};



/*
void highScoreShow()
{
	
			iSetColor(0,255,0);

			iText(320,450,player_name[0],GLUT_BITMAP_TIMES_ROMAN_24);

			iSetColor(0,255,0);
			
			iText(320,360,player_name[1],GLUT_BITMAP_TIMES_ROMAN_24);
			
			iSetColor(0,255,0);
			
			iText(320,270,player_name[2],GLUT_BITMAP_TIMES_ROMAN_24);

			iSetColor(0,255,0);
			
			iText(320,180,player_name[3],GLUT_BITMAP_TIMES_ROMAN_24);

			iSetColor(0,255,0);
			
			iText(320,90,player_name[4],GLUT_BITMAP_TIMES_ROMAN_24);

			

}*/


void arrow_button()
{
	

	iShowImage(1310,25,50,25,rightButton);


}


////......................draw Name Box Demo................///////


void drawNameBox()
{

	iSetColor(255,255,255);
	iFilledRectangle(600,320,200,50);
	

}

/////////...................Name state call...................../////////

void textDraw()
{

	drawNameBox();
	
	if(mode==1)
	{

		iSetColor(0,0,0);
		iText(610,333,str,GLUT_BITMAP_TIMES_ROMAN_24);

	}

	iText(530,335,"Name",GLUT_BITMAP_TIMES_ROMAN_24);

}


void ballDesign()
{


	iSetColor(red+225,green+205,blue+215);
	iFilledCircle(ball_x,ball_y,radius,30);


}

void boardDesign()
{

	iSetColor(red+215,green+205,blue);
	iFilledRectangle(board_x,board_y,dx_board,dy_board);


}



void brickDesign()
{

	
	for(int i=0;i<totalBricks;i++)
	{

		if(a[i].show)
		{

			iSetColor(a[i].red,a[i].green,a[i].blue);
			iFilledRectangle(a[i].x,a[i].y,100,20);

		}

	}
	
	
}


void showImage()
{

	iShowImage(0,0,screenWidth,screenHeight,image1);   ///screenWidth,screenHeight

	if(EndGame==1)
	{

		GameOverPageShow();

	}

}


void coOrdinate()
{

	for(int i=0;i<4;i++)
	{

		iShowImage(bCordinate[i].x,bCordinate[i].y,pic_x1,pic_y1,button_pic[i]);
		

	}

}


void nextPage()
{

	iShowImage(0,0,screenWidth,screenHeight,newImage);
	
	coOrdinate();

}

void homePage()
{


	iShowImage(0,0,screenWidth,screenHeight,home_menu);
	iSetColor(215,215,0);
	iText(1100,20,"Click To Continue.........",GLUT_BITMAP_TIMES_ROMAN_24);
	

}


int b_button=0;
int c_button=0;
int d_button=0;


void back_button()
{
	
	
	iShowImage(6,710,50,30,Backbutton);
	//30,620,50,25///

}

void imageButton()
{

	//iShowImage(1200,50,100,50,buton_image);


}

void gameStart()
{

	if(rightButton==1)
	{
		showImage();

		ballDesign(); 
		boardDesign();
		brickDesign();

		BorderLine();

		back_button();
		
		//imageButton();

		if(gameover==1)
		{

			scoreShow();

		}

		if(b_button==1)
		{

			gamestate=-1;

		}
		
		

	}



}

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


void showHighSCORE()
{
	iShowImage(0,0,screenWidth,screenHeight,high_score);

	highScoreShow();

}

void GameOverPageShow()
{

	iShowImage(0,0,screenWidth,screenHeight,hello_image);
	
	iSetColor(0,255,255);

	iText(500,400,"Oh! Game is Over",GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(0,255,0);

	//iText(600,300,"Good Bye");
	//GLUT_BITMAP_TIMES_ROMAN_24

	iText(750,350,"Total Score",GLUT_BITMAP_TIMES_ROMAN_24);

	iText(880,350,":",GLUT_BITMAP_TIMES_ROMAN_24);

	//if(gameover==1)
	//{

		scoreShow_2();
	
	//}


	
}


int bc_button;

int photo;

void iDraw()
{

	
	////////////......................Main Menu....................../////////

	iClear();

	
	if(gamestate==-1) 
	{
		

		homePage();

		/////........................Show the option................................/////
		if(click==1)
		{

			nextPage();

		}


	}
	

	////////.............................start game.........................../////////
	

	else if(gamestate==0)  
	{

		//iClear();
		
		////////////...........backbutton previous page show................//////
		
		bg_imageShow();
		
		//////.................next button......................./////

		arrow_button();

		///////.......name button.................../////
		
		textDraw();

		/////...............game start state..................../////

		gameStart();

		//GameOverPageShow();

		if(EndGame==1)
		{

			GameOverPageShow();

		}

	}

    
	///..................High Score....................///

	else if(gamestate==1) 
	{
		

		showHighSCORE();

		back_button();
		
		if(b_button==2)
		{

			//gamestate=-1;

			//homePage();
			nextPage();


		}

			
	}



	///.....................Instruction...................////

	else if(gamestate==2) 
	{
		//iClear();

		iShowImage(0,0,screenWidth,screenHeight,instr_menu);
		
		back_button();
		
		if(b_button==1)
		{

			//gamestate=-1;
			nextPage();

		}

	}

	else if(gamestate==3)
	{

		//iClear();


	}

}




void iMouseMove(int mx, int my)
{

}

void iPassiveMouse(int mx, int my)
{
	


}

void iMouse(int button, int state, int mx, int my)
{
	
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		for(int i=0;i<4;i++)
		{

			
				if(mx>=bCordinate[i].x&&mx<=bCordinate[i].x+240&&my>=bCordinate[i].y&&my<=bCordinate[i].y+120)
				{

					gamestate=i;
			
					if(gamestate==3)
					{

						exit(0);


					}


				}


		}
	
	
	}

	
	//////..................Back Button Activate..................../////


	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		//iShowImage(30,660,50,25,Backbutton);

		//30,620,50,25///

		//6,710

		if(mx>=6&&mx<=6+50&&my>=710&&my<=710+30)
		{

			b_button=1;

		}


	}


	//////.....................Right Button Acctivate...................//////

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		
		
		if(mx>=1290&&mx<=1290+50&&my>=60&&my<=40+40)   ///20,25
		{

			rightButton=1;

		}


	}

	//////.......................Name Text Show Activate....................//////


	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//iText(610,330,str);
		
		if(mx>=610&&mx<=690&&my>=335&&my<=380)
		{

			mode=1;
		
		}

	}

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{


		if(mx>=0&&mx<=screenWidth&&my>=0&&my<=screenHeight)
		{
			//1100,20

			click=1;

		}

	}

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//1200,50,100,50

		if(mx>=1000&&mx<=screenWidth&&my>=100&&my<=screenHeight)
		{

			EndGame=1;

		}

	}

}



void iKeyboard(unsigned char key)
{

	if(key == ' ')
	{
		if(!isStarted)
		{
			isStarted=true;

		}

	}
	

	////...............name input ............../////
	
	int i;

	

	if(mode==1)
	{

		if(key=='\r')
		{
	
			mode=0;

			strcpy(str,str2);
			
			printf("%s",str);

			for(i=0;i<len;i++)
			{

				str[i]=0;
				len=0;

			}

			printf("%s",str);

	
		}


		else
		{

			str[len]=key;
			len++;

		}


	}


}

void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		
	}
	

	////................board move from middle to left.....................////

	else if(key == GLUT_KEY_LEFT)
	{

		if(board_x>0)
		{

			board_x-=10;

			if(!isStarted)
			{
				ball_x-=10;
			}

		}
		

	}

	////................board move from middle to Right.....................////


	else if(key == GLUT_KEY_RIGHT)
	{

		if(board_x<screenWidth-dx_board)
		{

			board_x+=10;

			if(!isStarted)
			{

				ball_x+=10;

			}

		}
		
	}

	else if(key == GLUT_KEY_HOME)
	{

		exit(0);
		
	}

}


void ballCollisionConcept()
{

	////....................collision part..................////

		//struct brickStructer b[totalBricks]; 
		
	
	for(int i=0;i<totalBricks;i++)
		{
			
			if(a[i].show)
			{
				if(ball_x>=a[i].x&&ball_x<=a[i].x+a[i].dx)
				{
					if(ball_y>=a[i].y&&ball_y<=a[i].y+a[i].dy)
					{


						dy=-dy;

						a[i].show= false;
						
						

						if(a[i].show==false)
						{

						   score+=5;
						   finalScore+=5;
						

						}


												
						/////...............board size increase part..................../////
						
						

						if(score==80)
						{
							dx_board+=100;   /// 50 /// 
						}

						if(score>=80)
						{
							dx_board=280;   /// 150 ///
						}



						if(score==100||score==200||score==300)
						{

							score+=50;
							finalScore+=50;

						}

						if(score==155||score==270||score==405)
						{

							level++;
						
						}
							

					}

				}


				else if(ball_y>=a[i].y&&ball_y<=a[i].y+a[i].dy)
				{
					if(ball_x>=a[i].x&&ball_x<=a[i].x+a[i].dx)
					{

						
						dx=-dx;

						//count++;

						a[i].show= false;

						if(a[i].show==false)
						{

						   score+=5;
						   finalScore+=5;
						   
						}

						
						
			/////...............board size increase part..................../////
						
						

						if(score==80)
						{
							dx_board+=100;   /// 50 ///
						}

						if(score>=80)
						{

							dx_board=280;    /// 150 ///
						
						}



						if(score==100||score==200||score==300)
						{

							score+=50;
							finalScore+=50;

						}

						if(score==135||score==270||score==405)
						{

							level++;
						
						}


					}

				}
				

			}

		}


}



void ballMovement()
{

	////...................ball movement in the game screen......................./////

	if(isStarted)
	{

		ball_x+=dx;
		ball_y+=dy;

		if(ball_x>=screenWidth||ball_x<=0)
		{

			dx=-dx;

		}

		if(ball_y>=screenHeight-30||ball_y<=0)
		{

			dy=-dy;

		}
		
		ballCollisionConcept();

		
	}
		
		
		///////.......................ball and board collision part..................////////


		if(ball_x>=board_x&&ball_x<=board_x+dx_board&&ball_y>=board_y&&ball_y<=board_y+dy_board)
		{

			dy=-dy;

		}
		
		else
		{
			if(ball_y<board_y)
			{

				///..................show the score of the player......................////

				//EndGame=1;

					count++;

					if(score==0)
						level=0;

					if(count==3)
					{
						if(level>=1)
						{
							level--;
						}

					}


					if(count==5)
					{
						
						if(level>=2)
						{

							level=level-2;
						
						}

						else
						{

							level--;;
						
						}


					}

					printf("Fhardin\n");


					printf("Score : %d\n",score);


				if(score<81)
				{

					restartGame1();

				}
				
				if(score>=81)
				{

					restartGame2();

				}


			}

	}
	
	
}



void restartGame1()
{


	ball_x=(int)screenWidth/2;            
	ball_y=yAxisMovement;

	dx_board=130; //// 100 ///
	dy_board=10;


    board_x=ball_x-65;  /// 50 ///
	board_y=ball_y-20;

	dx=7;
	dy=5; 
   
	isStarted =false;


}

void restartGame2()
{

	ball_x=(int)screenWidth/2;            
	ball_y=yAxisMovement;


    board_x=ball_x-140;	/// 75 ///
	board_y=ball_y-20;

	dx=7;
	dy=5; 
   
	isStarted =false;


}



int main()
{


	defineBrick();
	playerScore();


	len=0;
	mode=0;
	str[0]=0;

	iInitialize(screenWidth, screenHeight, "DX-BALL 2");

	///...............homemenu image loading...................///

	home_menu=iLoadImage(homeMenu);


	///...............button image loading.....................///

	button_pic[0]=iLoadImage(button1);
	button_pic[1]=iLoadImage(button2);
	button_pic[2]=iLoadImage(button3);
	button_pic[3]=iLoadImage(button4);


	////..............button option coOrdinate....................////

	int s=210;

	for(int i=3;i>=0;i--)
	{

		bCordinate[i].x=10;   //10//
		bCordinate[i].y=s;
		s+=100;

	}



	bg_image=iLoadImage(image);
	rightButton=iLoadImage(rightButtonShow);
	newImage=iLoadImage(new_Image);
	//buton_image=iLoadImage(img);
	hello_image=iLoadImage(img1);


	///.................enter button option to go this page.................///

	high_score=iLoadImage(hs_button);
    instr_menu=iLoadImage(is_button);
	Backbutton=iLoadImage(backButton);


	///................background color..................................///

	image1=iLoadImage("images\\background_color.jpg");
	
	///...................settimer to ball movement.....................///

	iSetTimer(15,ballMovement);

    iStart();



	return 0;


}


