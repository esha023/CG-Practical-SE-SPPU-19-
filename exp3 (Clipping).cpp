#include<iostream>
#include<graphics.h>

using namespace std;

static int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8 , xl, yl, xh, yh;

int getcode(int x, int y)
{
	int code = 0;
	
	//Perform Bitwise OR to get the outcodes
	if(y>yh) code |= TOP;
	
	if(y<yl) code |= BOTTOM;
	
	if(x>xh) code |= RIGHT;
		
	if(x<xl) code |= LEFT;
		
	return code;
}

int main()
{
	int gdriver = DETECT, gmode;
	
	//Co-ordinates of clipping window
	cout<<"Enter the Bottom left and Top right Co-ordinates of clipping window: ";
	cin>>xl>>yl>>xh>>yh;
	
	//Co-ordinates of the line
	int x1, y1, x2, y2;
	cout<<"Enter the endpoints of the line: ";
	cin>>x1>>y1>>x2>>y2;
	
	initgraph(&gdriver, &gmode, NULL);
	setcolor(10);
	//Using in-built functions
	rectangle(xl,yl,xh,yh);  
	line(x1,y1,x2,y2);
	getch();
	
	//Clipping algorithm
	//STEP 1: Get outcodes for both endpoints
	int outcode1 = getcode(x1,y1), outcode2 = getcode(x2,y2);
	int accept = 0; //Decides whether to print line or not
	
	while(1)
	{
		float m = (float)(y2-y1)/(x2-x1);
		//Case 1: LINE COMPLETELY VISIBLE
		if(outcode1==0 && outcode2==0)
		{
			accept = 1;
			break;
		}
			
		//Case 2: LINE COMPLETELY OUTSIDE THE WINDOW (AND of outcodes is NOT ZERO)
		else if((outcode1 & outcode2) != 0)
		{
			accept = 0;
			break;
		}
			
			
		//Case 3: LINE PARTIALLY VISIBLE (AND of outcodes is ZERO)
		else
		{
			int x, y, temp;
			
			//Storing non-zero outcode in temp
			if(outcode1 == 0)
			{
				temp = outcode2;
			}
			else
				temp = outcode1;
				
			//Comparing temp with each edge
			
			if(temp & TOP)
			{
				x = x1 + (yh - y1)/m;
				y = yh;
			}
			else if(temp & BOTTOM)
			{
				x = x1 + (yl - y1)/m;
				y = yl;
			}
			else if(temp & LEFT)
			{
				x = xl;
				y = y1 + m*(xl - x1);
			}
			else if(temp & RIGHT)
			{
				x = xh;
				y = y1 + m*(xh - x1);
			}
			
			//Set x, y as co-ordinates of selected temp
			//Update the outcodes acc. to new values
			if(temp == outcode1)
			{
				x1 = x;
				y1 = y;
				outcode1 = getcode(x1, y1);
			}
			else
			{
				x2 = x;
				y2 = y;
				outcode2 = getcode(x2, y2);
			}
		}
	}
	cout<<"********Output After Clipping*********";
	if(accept)
	cleardevice(); //clears the previous screen of line without clipping
	rectangle(xl, yl, xh, yh);
	setcolor(WHITE);
	line(x1, y1, x2, y2);
	delay(5000);
	closegraph();
	
	return 0;
}
