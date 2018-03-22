#include<iostream>
using namespace std;
int p[30];
int rank[30];
struct edge
{
	int src;
	int dest;
	int weight;
};
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
void swap(edge &e1,edge &e2)
{
	int temp1,temp2,temp3;
	temp1=e1.src;
	e1.src=e2.src;
	e2.src=temp1;
	temp2=e1.dest;
	e1.dest=e2.dest;
	e2.dest=temp2;
	temp3=e1.weight;
	e1.weight=e2.weight;
	e2.weight=temp3;
}
void selsort(edge e[],int k)
{
	int i,j,min;
	for(i=0;i<k;i++)
	{
		min=i;
		for(j=i+1;j<k;j++)
		{
			if(e[i].weight>e[j].weight)
			{
				min=j;
				swap(e[i],e[j]);
			}
		}
	}
}
void MST_krushkals(int w[][10],int a[][10],int n,edge e[],int k)
{
	int i,j;
	edge e2[30];
	int k2=0;
	for(i=0;i<n;i++)
	{
		makeset(i);
	}
	selsort(e,k);
	for(i=0;i<k;i++)
	{
		if(findset(e[i].src)!=findset(e[i].dest))
		{
			e2[k2].src=e[i].src;
			e2[k2].dest=e[i].dest;
			e2[k2].weight=e[i].weight;
			k2++;
		//	a[e[i].src][e[i].dest]=w[e[i].src][e[i].dest];
		//	a[e[i].dest][e[i].src]=w[e[i].src][e[i].dest];
			setunion(e[i].src,e[i].dest);
		}
	}
	/*	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]>0)
			{
				cout<<" "<<a[i][j]<<"   ";
			}
			else
			{	
				cout<<a[i][j]<<"   ";
			}
		}
		cout<<endl;
	}     */
	for(i=0;i<k2;i++)
	{
		cout<<e2[i].src<<"-"<<e2[i].dest<<"    "<<e2[i].weight<<endl;
	}
}
int main()
{
	int n,a[10][10],w[10][10];
	int i,j;
	edge e[30];
	cout<<"Enter the number of vertices in the graph : ";
	cin>>n;
	cout<<"Enter the inputs for weight matrix \n";
	int k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>w[i][j];
		/*	if(i!=j)
			{
				a[i][j]=-1;
			}
			else
			{
				a[i][j]=0;
			}	*/
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i<j&&w[i][j]!=-1)
			{
				e[k].src=i;
				e[k].dest=j;
				e[k].weight=w[i][j];
				k++;
			}
		}
	}
	cout<<"The edges and their corresponding weights in the minimum spanning tree are \n";
	MST_krushkals(w,a,n,e,k);
	return 0;	
}
