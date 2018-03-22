#include<iostream>
using namespace std;
struct knapsack
{
	float w;
	float v;
	float x;
};
void swap(knapsack &k1, knapsack &k2)
{
	float temp1,temp2;
	float temp3;
	temp1=k1.w;
	k1.w=k2.w;
	k2.w=temp1;
	temp2=k1.v;
	k1.v=k2.v;
	k2.v=temp2;
	temp3=k1.x;
	k1.x=k2.x;
	k2.x=temp3;
}
void selsort(knapsack arr[],int n)
{
	int i, j, min;
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[i].x<arr[j].x)
			{
				min=j;
				swap(arr[i],arr[j]);
			}
		}
	}
}
void fractional_knapsack(knapsack arr[],int n,int c)
{
	float profit=0.0;
	for(int i=0;i<n;i++)
	{
		arr[i].x=(float)arr[i].v/arr[i].w;
	}
	selsort(arr,n);
/*	for(int k=0;k<n;k++)
	{
		cout<<arr[k].w<<"    "<<arr[k].v<<"   "<<arr[k].x;	
		cout<<endl;	
	}
*/	int i=0;
	while(c>0)
	{
		if(arr[i].w<=c)
		{
			profit=(float)profit+arr[i].v;
			c=c-arr[i].w;
		}
		else if(c<arr[i].w)
		{
			float d= arr[i].v/arr[i].w;
			profit= (float)profit+ d*c;
			break;
		}
		i++;
	}
	cout<<"Total profit = "<<(float)profit;
}
int main()
{
	int c,n,i;
	cout<<"Enter the total capacity of knapsack : ";
	cin>>c;
	cout<<"Enter the total number of items : ";
	cin>>n;
	knapsack arr[n];
	cout<<"Enter the values and weights of the items respectively ";
	for(i=0;i<n;i++)
	{
		cin>>arr[i].v;
		cin>>arr[i].w;
	}
	fractional_knapsack(arr,n,c);
	return 0;
}
