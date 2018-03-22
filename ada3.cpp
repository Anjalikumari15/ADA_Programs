#include<iostream>
using namespace std;
void strassen(int a[10][10],int b[10][10],int n,int c[10][10])
{	
	int i,j;
	if(n==1)
	{
		c[0][0]=a[0][0]*b[0][0];
	}
	else
	{
		int a11[10][10],a12[10][10],a21[10][10],a22[10][10];
		int b11[10][10],b12[10][10],b21[10][10],b22[10][10];
		int a1[10][10],b1[10][10],a2[10][10],b3[10][10],b4[10][10],a5[10][10],a6[10][10],b6[10][10],a7[10][10],b7[10][10];
		int p1[10][10],p2[10][10],p3[10][10],p4[10][10],p5[10][10],p6[10][10],p7[10][10];
		int c11[10][10],c12[10][10],c21[10][10],c22[10][10];
		for(i=0;i<n/2;i++)
		{
			for(j=0;j<n/2;j++)
			{
				a11[i][j]=a[i][j];
				b11[i][j]=b[i][j];
				a12[i][j]=a[i][j+n/2];
				b12[i][j]=b[i][j+n/2];
				a21[i][j]=a[i+n/2][j];
				b21[i][j]=b[i+n/2][j];
				a22[i][j]=a[i+n/2][j+n/2];
				b22[i][j]=b[i+n/2][j+n/2];
			}
		}
		for(i=0;i<n/2;i++)
		{
			for(j=0;j<n/2;j++)
			{
				a1[i][j]=a11[i][j]+a22[i][j];
				b1[i][j]=b11[i][j]+b22[i][j];
				a2[i][j]=a21[i][j]+a22[i][j];
				b3[i][j]=b12[i][j]-b22[i][j];
				b4[i][j]=b21[i][j]-b11[i][j];
				a5[i][j]=a11[i][j]+a12[i][j];
				a6[i][j]=a21[i][j]-a11[i][j];
				b6[i][j]=b11[i][j]+b12[i][j];
				a7[i][j]=a12[i][j]-a22[i][j];
				b7[i][j]=b21[i][j]+b22[i][j];					
			}
		}
		strassen(a1,b1,n/2,p1);
		strassen(a2,b11,n/2,p2);
		strassen(a11,b3,n/2,p3);
		strassen(a22,b4,n/2,p4);
		strassen(a5,b22,n/2,p5);
		strassen(a6,b6,n/2,p6);
		strassen(a7,b7,n/2,p7);
		for(i=0;i<n/2;i++)
		{
		 	for(j=0;j<n/2;j++)
		 	{
		 		c11[i][j]=p1[i][j]+p4[i][j]-p5[i][j]+p7[i][j];
		 		c12[i][j]=p3[i][j]+p5[i][j];
		 		c21[i][j]=p2[i][j]+p4[i][j];
		 		c22[i][j]=p1[i][j]+p3[i][j]-p2[i][j]+p6[i][j];
			}
		}
		for(i=0;i<n/2;i++)
		{
			for(j=0;j<n/2;j++)
			{
				c[i][j]=c11[i][j];
				c[i][j+n/2]=c12[i][j];
				c[i+n/2][j]=c21[i][j];
				c[i+n/2][j+n/2]=c22[i][j];
			}
		}			
	}
}
int main()
{
	int i,j,n,a[10][10],b[10][10],c[10][10];
	cout<<"Enter the order of matrices : ";
	cin>>n;
	cout<<"Enter elements of matrix A\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<"Enter elements of matrix B\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>b[i][j];
		}
	}
	strassen(a,b,n,c);
	cout<<"The resultant matrix is \n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<c[i][j]<<"  ";
		}
		cout<<endl;
	}
	return 0;
}
