#include<iostream>
using namespace std;
int max(int a[],int n)
{
	int maximum=a[0];
	int pos=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>maximum)
		maximum=a[i];
	}
	return (maximum);
}
int min(int a,int b)
{
	if(a>b)
	return b;
	else return a;
}
void JSD(int d[], int p[],int n,int t[],int j[])
{
	int Dmax = max (d,n);
	int i,k;
	for(i=1;i<=min(n,Dmax);i++)
	{
		t[i]=-1;
	}
	for(i=0;i<n;i++)
	{
		k = min(n,d[i]);
		while(k>=1)
		{
			if(t[k]==-1)
			{
				t[k]=j[i];
				break;
			}
			k=k-1;
		}
	}
}
int main()
{
	int d[20],p[20],n,t[20];
	int job[20];
	int Dmax;
	cout<<"Enter the total number of jobs : ";
	cin>>n;
	cout<<"Enter the job number, profits and deadlines of each job (in decreasing order of profits)\n";	
	for(int i=0;i<n;i++)
	{
		cin>>job[i];
		cin>>p[i];
		cin>>d[i];
	}
	JSD(d,p,n,t,job);
	cout<<"The schedule is \n";
	Dmax=max(d,n);
	for(int i=1;i<=min(n,Dmax);i++)
	{
		cout<<"job "<<t[i]<<"      ";
	}
	return 0;
}		

