#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class Line
//Using DDA Line drawing algorithm
{
	int x, y, dx, dy, xi, yi, len;
	public:
		void put()
		{
			putpixel(x,y,9);
		}
		void lin(int x1, int y1, int x2, int y2)
		{
			dx = x2 - x1;
			dy = y2 - y1;
			
			if(abs(dx) > abs(dy))
			{
				len = abs(dx);
			}
			else
				len = abs(dy);
				
			xi = dx/len;
			yi = dy/len;
			
			//initial point
			x = x1;
			y = y1;
			put();
			
			//plotting other points
			for(int i = 1; i<=len; i++)
			{
				x = x + xi;
				y = y + yi;
				put();
				delay(5);
			}
		}
};

class Circle
//Using Bresemham Circle Drawing algorithm
{
	public:
		void cir(int x, int y, int rad)
		{
			int x1 = 0;
			int y1 = rad;
			putpixel(x1, y1, 6);

			//Decision making parameter
			int pk = 3 - 2*rad;
			
			while(x1<=y1)
			{
				if(pk<=0)
				{
					pk = pk + (4*x1) + 6;
				}
				else
				{
					pk = pk + (4*(x1-y1)) + 10;
					y1--;
				}
				//Always increament x1
				x1++;

				//According to octant
				putpixel(x+x1, y+y1, 3);
				putpixel(x-x1, y+y1, 3);
				putpixel(x+x1, y-y1, 3);
				putpixel(x-x1, y-y1, 3);
				putpixel(x+y1, y+x1, 3);
				putpixel(x-y1, y+x1, 3);
				putpixel(x+y1, y-x1, 3);
				putpixel(x-y1, y-x1, 3);
				delay(10);
			}	
		}
};

int main()
{
	Line l;
	Circle c;
	int gd = DETECT, gm = DETECT;
	initgraph(&gd, &gm, NULL);

	//Plotting main square
	l.lin(100,100,400,100);
 	l.lin(100,400,400,400);
 	l.lin(100,100,100,400);
 	l.lin(400,100,400,400);

	//Plotting diamond inside square
 	l.lin(250,100,100,250);
 	l.lin(100,250,250,400);
 	l.lin(250,400,400,250);
 	l.lin(250,100,400,250);

	//Circle inside rhombus
 	c.cir(250,250,100);
 	
 	delay(500);
 	closegraph();
 	
 	return 0;
}
