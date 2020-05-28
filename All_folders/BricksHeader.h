#ifndef BRICKS_HEADER_H_INCLUDED
#define BRICKS_HEADER_H_INCLUDED


#define screenWidth 1400
#define screenHeight 700
#define yAxisMovement 60
#define totalBricks 6*10


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
	int score;


	brickStructer()
	{
		this->dx=100;
		this->dy=20;
		this->show=true;

	}

};

brickStructer a[totalBricks];





#endif // BRICKS_HEADER_H_INCLUDED
