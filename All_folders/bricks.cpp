# include "iGraphics.h"
#include "imageloadder.h"


#define screenWidth 1000
#define screenHeight 600



void iDraw()
{
	//place your drawing codes here

	iClear();

	if(gamestate==-1)
	{

		iShowImage(0,0,screenWidth,screenHeight,home_menu);

		for(int i=0;i<3;i++)
		{
			iShowImage(bCordinate[i].x,bCordinate[i].y,pic_x1,pic_y1,button_pic[i]);
		
		}



	}
	
	else if(gamestate==0)
	{
		

	}

	else if(gamestate==1)
	{
		
		iShowImage(0,0,screenWidth,screenHeight,high_score);
		//iShowImage(screenWidth-100,screenHeight-500,50,30,return_menu);
		

	}

	else if(gamestate==2)
	{
		iShowImage(0,0,screenWidth,screenHeight,return_menu);
	}


    
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iPassiveMouse() is called when the user moves the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iPassiveMouse(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here

		for(int i=0;i<3;i++)
		{
			if(mx>=bCordinate[i].x&&mx<=bCordinate[i].x+200&&my>=bCordinate[i].y&&my<=bCordinate[i].y+80)
			{
				gamestate=i;

			}
		}
		
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here

	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		//do something with 'q'
		

	}
	if(key == 'r')
	{
		

	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}




int main()
{
	//place your own initialization codes here.
	//balltimer_1 = iSetTimer(5, ballChange1);
	//balltimer_2 = iSetTimer(5, ballChange2);

	//dx = 5;
	//dy = 7;




	iInitialize(screenWidth,screenHeight, "Simple Demo");


	home_menu=iLoadImage(homeMenu);

	button_pic[0]=iLoadImage(button1);
	button_pic[1]=iLoadImage(button2);
	button_pic[2]=iLoadImage(button3);
	
	int s=100;

	for(int i=2;i>=0;i--)
	{

		bCordinate[i].x=10;
		bCordinate[i].y=s;
		s+=150;

	}


	high_score=iLoadImage(hs_button);
    return_menu=iLoadImage(return_button);


    iStart();


	return 0;
}

