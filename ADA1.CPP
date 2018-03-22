#include<iostream.h>
#include<conio.h>
void merge(int a[],int s1,int e1,int s2,int e2)
{
	int i=0;
	int FS=s1;
	int FE=e2;
	int result[100],j;
	while(s1<=e1&&s2<=e2)
	{
		if(a[s1]<a[s2])
		{
			result[i]=a[s1];
			i++;
			s1++;
		}
		else
		{
			result[i]=a[s2];
			i++;
			s2++;
		}
	}
	if(s2>e2)
	{
		for(j=s1;j<=e1;j++)
		{
			result[i]=a[j];
			i++;
		}
	}
	if(s1>e1)
	{
		for(j=s2;j<=e2;j++)
		{
			result[i]=a[j];
			i++;
		}

	}
	int k=0;
	for(j=FS;j<=FE;j++)
	{
		a[j]=result[k];
		k++;
	}
}
void mergesort(int a[],int first,int last)
{
	int mid;
	if(first<last)
	{
		mid=(first+last)/2;
		mergesort(a,first,mid);
		mergesort(a,mid+1,last);
		merge(a,first,mid,mid+1,last);
	}
}
void main()
{
	clrscr();
	int a[100],n,i;
	cout<<"Enter the size of Array : ";
	cin>>n;
	cout<<"Enter the elements of Array\n";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int f=0;
	int l=n-1;
	cout<<"Sorted array is \n";
	mergesort(a,f,l);
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"  ";
	}
	getch();
}
