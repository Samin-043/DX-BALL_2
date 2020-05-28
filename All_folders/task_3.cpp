#include<iostream>
# include "iGraphics.h"
using namespace std;


#define screenWidth 1200
#define screenHeight 650
#define yAxisMovement 50
#define totalBricks 5*10


int menu_image;
int play_button;
int button;


/*struct cpOrdinate
{

	int x1;
	int y1;


}cpOrdinate[3];
*/






struct brickStructer
{
	int x;
	int y;
	int dx;
	int dy;
	int red;
	int green;
	int blue;
	bool show;


	brickStructer()
	{
		this->dx=100;
		this->dy=20;
		this->show=true;

	}


};


brickStructer a[totalBricks];


void defineBrick()
{	

    int sum_x=100;
    int sum_y=450;


    for(int i=0;i<totalBricks;i++)
    {

		a[i].red=rand() % 255;
		a[i].green=rand() % 255;
		a[i].blue=rand() % 255;

        a[i].x=sum_x;
        a[i].y=sum_y;

        sum_x+=100;

        if(sum_x>1000)
        {
            sum_x=100;
            sum_y+=20;

        }
	}
}

int green=0;
int red=0;
int blue=0;

int ball_x=(int)screenWidth/2;            
int ball_y=yAxisMovement;
int radius=10;

int board_x=ball_x-50;
int board_y=ball_y-20;
int dx_board=100;
int dy_board=10;

int image1;
int score_image;
 

int pic_x1=screenWidth-100;
int pic_y1=screenHeight-50;

int dx=7;
int dy=5;


bool isStarted =false;


void ballMovement();
void restartBall();


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

	iShowImage(0,0,1200,650,image1);

}

void scoreImage()
{

	iShowImage(pic_x1,pic_y1,100,50,score_image);

}


/*void menuImage()
{
	iShowImage(0,0,screenWidth,screenHeight,menu_image);
	
	//play_button;

	iShowImage(20,400,50,50,play_button);


     //button;

	iShowImage(20,200,50,50,button);



	
}*/

void iDraw()
{
	showImage();

	ballDesign();
	boardDesign();
	brickDesign();
	scoreImage();
     //menuImage();


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
		//place your codes here
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{

	}
	else if(key == 'r')
	{

	}

	else if(key == ' ')
	{
		if(!isStarted)
		{
			isStarted=true;

		}

	}


}

void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	
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

	else if(key == GLUT_KEY_UP)
	{
		
		
	}

	else if(key == GLUT_KEY_LEFT)
	{
		exit(0);
	}
	

}

void ballMovement()
{
	if(isStarted)
	{
		ball_x+=dx;
		ball_y+=dy;

		if(ball_x>=screenWidth||ball_x<=0)
		{
			dx=-dx;
		}

		if(ball_y>=screenHeight||ball_y<=0)
		{
			dy=-dy;
		}
		
		///collision

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
						
					}

				}


				else if(ball_y>=a[i].y&&ball_y<=a[i].y+a[i].dy)
				{
					if(ball_x>=a[i].x&&ball_x<=a[i].x+a[i].dx)
					{

						dx=-dx;
						a[i].show= false;

					}

				}
			}
		}
		
		for(int i=0;i<totalBricks;i++)
		{
			if(a[i].show)
			{

			}

		}

		if(ball_x>=board_x&&ball_x<=board_x+dx_board&&ball_y>=board_y&&ball_y<=board_y+dy_board)
		{
			dy=-dy;

		}
		else
		{
			if(ball_y<board_y)
			{
				
			    restartBall();

			}
		}
	}
	
	
}




//int red=0;
//int green=0;
//int blue=0;


void restartBall()
{
	
	ball_x=(int)screenWidth/2;            ///type casting///
	ball_y=yAxisMovement;

    board_x=ball_x-50;
	board_y=ball_y-20;

	dx=7;
	dy=5; 
   
	isStarted =false;


}


int main()
{

	defineBrick();

	iInitialize(screenWidth, screenHeight, "The Ultimate");

	image1=iLoadImage("images\\background_color.jpg");


	iSetTimer(15,ballMovement);


    iStart();



	return 0;
}


