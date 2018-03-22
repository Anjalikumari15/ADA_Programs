#include<iostream>
using namespace std;
int p[100], rank[100];
//int z=0;
void makeset(int x)
{
	rank[x]=0;
	p[x]=x;
}
int findset(int x)
{
	if(p[x]==x)
	return x;
	else
	{
		return findset(p[x]);
	}
}
void setunion(int x,int y)
{
	int rep1,rep2;
	rep1=findset(x);
	rep2=findset(y);
	cout<<rep1<<"  "<<rep2<<endl;
	if(rep1==rep2)
	return;
	else
	{
		if(rank[rep1]>rank[rep2]);
		{
			p[rep2]=rep1;
			p[rep1]=rep1;
		}
		if(rank[rep1]<rank[rep2])
		{
			p[rep1]=rep2;
			p[rep2]=rep2;
		}
		else
		{
			p[rep2]=rep1;
			rank[rep1]++;
		}
	}
}
int main()
{
	int a,b,c,n;
	cout<<"Enter the range of numbers in disjoint set\n";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		p[i]=-20;
	}
	int ch;
	char ans;
	do
	{
	cout<<"Enter 1 to form sets\n";
	cout<<"Enter 2 to find representative\n";
	cout<<"Enter 3 to find union\n";
	cout<<"Enter your choice : ";
	cin>>ch;
	if(ch==1)
	{
		cout<<"Enter the representative element\n";
		cin>>a;
		makeset(a);
		cout<<"A set is formed with representative element as "<<a;
	}
	if(ch==2)
	{
		cout<<"Enter an element to find its representative : ";
		cin>>a;
		b=findset(a);
		cout<<"Representative of "<<a<<" is "<<b<<" \n ";
	}
	if(ch==3)
	{
		cout<<"Enter the two elements to find union : ";
		cin>>b>>c;
		setunion(b,c);
		for(int i=1;i<=n;i++)
		{	
			if(p[i]==-20)
			cout<<"Null"<<"  ";
			else
			cout<<p[i]<<"  ";
		}
	}cout<<"\nDo you want to perform more operations\n";
	cin>>ans;
}while(ans=='y');
	return 0;
}
