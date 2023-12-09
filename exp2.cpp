#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

class Line
{
	int x, y, xi, yi, dx, dy, len;
	
	public:
		void put()
		{
			putpixel(x, y, 10);
		}
		
		void lin(int x1, int y1, int x2, int y2)
		{
			dx = x2 - x1;
			dy = y2 - y1;
			
			if(abs(dx)>abs(dy))
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
			for(int i =0; i<=len; i++)
			{
				x = x + xi;
				y = y + yi;
				put();
				delay(5);
			}
		}
};

class Circle
{
	public:
		void cir(int x, int y, int rad)
		{
			int x1 = 0;
			int y1 = rad;
			putpixel(x1, y1, 10);
			
			int pk = 3 - 2*rad;
			
			while(x1<y1)
			{
				if(pk<=0)
				{
					pk = pk + 4*x1 + 6;
				}
				else
				{
					pk = pk + 4*(x1-y1) + 10;
					y1--;
				}
				x1++;
				
				putpixel(x+x1, y+y1, 9);
				putpixel(x-x1, y+y1, 9);
				putpixel(x+x1, y-y1, 9);
				putpixel(x-x1, y-y1, 9);
				putpixel(x+y1, y+x1, 9);
				putpixel(x-y1, y+x1, 9);
				putpixel(x+y1, y-x1, 9);
				putpixel(x-y1, y-x1, 9);
				
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
	c.cir(250, 250, 200);
	l.lin(50, 250, 250, 50);
	l.lin(250, 50, 450, 250);
	l.lin(450, 250, 50, 250);
	c.cir(250, 167, 80);
	
	delay(500);
	closegraph();
	
	return 0;
}
