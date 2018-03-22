#include<iostream>
using namespace std;
int b[3];
int* maxmin(int a[],int f,int l)
{
	int *c;
	int *d;
	if(f==l)	
	{
		b[0]=a[f];
		b[1]=a[f];
		return b;
	}	
    else if(f==l-1)
	{
		if(a[f]>a[l])
		{
			b[0]=a[l];
			b[1]=a[f];
		}
		else 
 		{
			b[0]=a[f];
			b[1]=a[l];
		}
		return b;
	}
	else 
	{
		int min,min1,min2,max,max1,max2;
		int mid=(f+l)/2;
		c=maxmin(a,f,mid);
        min1=c[0];
		max1=c[1];
		d=maxmin(a,mid+1,l);
		max2=d[1];
		min2=d[0];
		if(max1>max2)
		{
			max=max1;
		}
		else max=max2;
		if(min1>min2)
		{
			min=min2;
		}
		else min=min1; 
		b[0]=min;
		b[1]=max;
		return b;
	}
}
int main()
{
	int i,n,f,l,max,min;
	int a[100];
	cout<<"Enter the number of terms in the array : ";
	cin>>n;
	cout<<"Enter the elements of the array\n";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int *x;
	x=maxmin(a,0,n-1);
	cout<<"Maximum element in the array is "<<x[1];
	cout<<"\nMinimum element in the array is "<<x[0];
	return 0;
}
