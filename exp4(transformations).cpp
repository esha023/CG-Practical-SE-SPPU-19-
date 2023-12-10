#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

class matrix
{
	public:
	int n;
	int tx, ty, sx, sy, degree = 0, sum;
	float radian = 0;
	double m1[6][3], m2[6][3], ans[6][3], mult[6][3];
	
	void getmat()
	{
		cout<<"Enter total no. of vertices of polygon";
		cin>>n;
		//Taking matrix as input
		for(int i=0; i<n; i++)
		{
			cout<<"Enter x,y co-ordinates: ";
			cin>>m2[i][0]>>m2[i][1];
			m2[i][2] = 1;	
		}
		//Display the entered matrix
		cout<<"Entered matrix is: "<<endl;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<3; j++)
			{
				cout<<m2[i][j]<<"\t";
			}
			cout<<endl;
		}	
	}
	void identity()
	{
		//Creating identity matrix 
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<3; j++)
			{
				if(i==j)
					m1[i][j]=1;
				else
					m1[i][j]=0;
			}
		}	
	}
	void transl()
	{
		//Input translation vectors (tx, ty)
		cout<<"Enter values of tx, ty: ";
		cin>>tx>>ty;
		//Creating translation matrix
		m1[2][0] = tx;
		m1[2][1] = ty;
		//display the matrix
		cout<<endl;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<3; j++)
			{
				cout<<m1[i][j]<<"\t";
			}
			cout<<endl;
		}
		
	}
	void scale()
	{
		//Input scaling factors (sx, sy)
		cout<<"Enter values of sx, sy: ";
		cin>>sx>>sy;
		//Creating scaling matrix
		m1[0][0] = sx;
		m1[1][1] = sy;
		//display matric
		cout<<endl;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<3; j++)
			{
				cout<<m1[i][j]<<"\t";
			}
			cout<<endl;
		}		
	}
	void rotation()
	{
		//Input angle of rotation
		cout<<"Enter the angle of rotation: ";
		cin>>degree;
		//converting in radian
		radian = (float)(degree*3.142)/180;
		//creating rotation matrix
		m1[0][0] = cos(radian);
		m1[0][1] = sin(radian);
		m1[1][0] = -sin(radian);
		m1[1][1] = cos(radian);
		//Display rotation matrix
		cout<<endl;
		for(int i=0; i<3; i++)
		{
			for(int j=0; j<3; j++)
			{
				cout<<m1[i][j]<<"\t";
			}
			cout<<endl;
		}
	}
	void multi()
	{
		//Creating multiplication code for obj matrix * transformation matrix
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<3; j++)
			{
				sum = 0;
				for(int k=0; k<3; k++)
				{
					sum = sum + (m2[i][k]*m1[k][j]);
				}
				ans[i][j] = sum;
			}
		}
	}
	void display()
	{
		//Display resultant matrix
		cout<<"Resultant Matrix is: ";
		cout<<endl;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				cout<<ans[i][j]<<"\t";
			}
			cout<<endl;
		}
		
		int gd = DETECT, gm;
		initgraph(&gd, &gm, NULL);
	
		//plotting lines acc. to values in the matrix
		for(int i=0; i<n-1; i++)
		{
			line(m2[i][0], m2[i][1], m2[i+1][0], m2[i+1][1]);
		}
		line(m2[2][0], m2[2][1], m2[0][0], m2[0][1]);
	
		for(int i=0; i<n-1; i++)
		{
			line(ans[i][0], ans[i][1], ans[i+1][0], ans[i+1][1]);
		}
		line(ans[2][0], ans[2][1], ans[0][0], ans[0][1]);
		
		delay(5000);
		closegraph();
	}
	
};

int main()
{
	matrix m;
	int ch;
	m.getmat();
	m.identity();
	cout<<"Choose the transformation to be performed: "<<endl;
	cout<<"(1): Translation \t (2): Scaling \t (3): Rotation \t (0): Exit Program"<<endl;
	do
	{
		cout<<"enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				m.transl();
				m.multi();
				m.display();
				break;
				
			case 2:
				m.scale();
				m.multi();
				m.display();
				break;
				
			case 3:
				m.rotation();
				m.multi();
				m.display();
				break;
		}
	}while(ch!=0);
	
	return 0;
}
