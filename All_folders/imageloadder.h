#ifndef IMAGE_LOADDER_H_INCLUDED
#define IMAGE_LOADDER_H_INCLUDED


struct bCordinate
{

	int x;
	int y;


}bCordinate[4];



int home_menu;
int high_score;
int exit_button;
int instr_menu;

int Backbutton;
int newImage;


char new_Image[]="images\\othher page_wallpaper.jpg";

	
///.................button Click.........................  ///

char hs_button[30]="images\\high_score_1.jpg";
char is_button [40]= "images\\instrunction_page.png";


///....................menu option......................... ///

char button1[30]="images\\Start.png";
char button2[30]="images\\HighSc.png";
char button3[30]="images\\Rules.png";
char button4[30]="images\\end.png";

char backButton[30]="images\\return_menu.png";

char homeMenu[30]="images\\DXBall2.png";


int button_pic[4];



int gamestate=-1;
int pic_x1=240;
int pic_y1=120;





#endif //IMAGE_LOADDER_H_INCLUDED