#ifndef FIND_HEADER_H_INCLUDED
#define FIND_HEADER_H_INCLUDED

int pic_x, pic_y;
int dx, dy;

void objectChange() {
	pic_x1 += dx;
	pic_y1 += dy;

	if (pic_x1 >= 1000 || pic_x1 <= 0)
		dx = -dx;
	if (pic_y1 >= 600 || pic_y1 <= 0)
		dy = -dy;
}

void objectChange_1() {
	pic_x2 += dx;
	pic_y2 += dy;

	if (pic_x2 >= 900 || pic_x2 <= 0)
		dx = -dx;
	if (pic_y2 >= 500 || pic_y2 <= 0)
		dy = -dy;
}


#endif // FIND_HEADER_H_INCLUDED
