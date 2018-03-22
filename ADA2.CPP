#include<iostream.h>
#include<conio.h>
void swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
int pivot_list(int a[],int first,int last)
{
	int pvalue=a[first];
	int ppoint=first;
	for(int i=first+1;i<=last;i++)
	{
		if(a[i]<pvalue)
		{
			ppoint++;
		    //	int temp=a[ppoint];
		     //	a[ppoint]=a[i];
		      //	a[i]=a[ppoint];
		      swap(a[ppoint],a[i]);
		}
	}
	swap(a[first],a[ppoint]);
	return(ppoint);
}
int* quicksort(int a[],int first,int last)
{
	int pivot;
	if(first<last)
	{
		pivot=pivot_list(a,first,last);
		quicksort(a,first,pivot-1);
		quicksort(a,pivot+1,last);
	}
	return(a);
}
void main()
{
	clrscr();
	int a[100],n,i;
	cout<<"Enter the size of array : ";
	cin>>n;
	cout<<"Enter the elements of array\n";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"Sorted array is \n";
	int f=0;
	int l=n-1;
	quicksort(a,f,l);
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"  ";
	}
	getch();
}