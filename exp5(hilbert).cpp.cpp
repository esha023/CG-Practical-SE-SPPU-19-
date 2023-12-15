#include<iostream>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

void move(int j, int len, int&x, int &y)
{
	if(j==1)
		y = y-len;
	else if (j == 2)
		x = x+len;
	else if (j == 3)
		y = y+len;
	else if (j == 4)
		x = x-len;
	
	//draws line from current position to (x,y)	
	lineto(x, y);
}

void hilbert(int rgt, int down, int left, int up, int iter, int len, int &x, int &y)
{
	if(iter>0)
	{
		--iter;
		hilbert(down, rgt, up, left, iter, len, x, y);
		move(rgt, len, x, y);
		hilbert(rgt, down, left, up, iter, len, x, y);
		move(down, len, x, y);
		hilbert(rgt, down, left, up, iter, len, x, y);
		move(left, len, x, y);
		hilbert(up, left, down, rgt, iter, len, x, y);
	}
}

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	int i;
	cout<<"Enter the number of iterations to be performed: ";
	cin>>i;
	int xi = 170, yi = 70, x, y, len = 10, rgt=2, down=3, left=4, up=1;
	x = xi;
	y = yi;
	moveto(x,y);
	hilbert(rgt,down,left,up,i,len, x, y);
	
	delay(10000);
	closegraph();
	return 0;
	
}
