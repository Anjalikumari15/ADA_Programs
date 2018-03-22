#include<iostream>
using namespace std;
int mstset[30];
struct priority_queue
{
	int item;
	int p;
};
struct edge
{
	int src;
	int dest;
	int weight;
};
int extract_min(priority_queue pq[],int n)
{
	int c=0;
	priority_queue min=pq[0];
	int min_index=0;
	for(int i=1;i<n;i++)
	{
		if(pq[i].p<min.p)
		{
			min=pq[i];
			min_index=i;
		}
	}
	return(min_index);
}
void printMST(int par[],int n,int w[30][30])
{
	for(int i=1;i<n;i++)
	{
		cout<<par[i]<<"-"<<i<<"   "<<w[par[i]][i];
		cout<<endl;
	}
}
void MST_prim(int w[30][30],int par[],int key[],int n,edge e[],int k)
{
	int i,j;
	int u;
	for(i=0;i<n;i++)
	{
		key[i]=1000;
		par[i]=-1;	
		mstset[i]= 0;
	}
	key[0]=0;
	priority_queue pq[n];
	for(i=0;i<n;i++)
	{
		pq[i].item=i;
		pq[i].p=key[i];
	}
	i=0;
	while(i<n)
	{
		u=extract_min(pq,n);
		pq[u].p=50;
		mstset[u]=1;
		for(j=0;j<n;j++)
		{	
			int v=j;
			if(mstset[v]==0 && w[u][v]!=-1 && w[u][v]<key[v])
			{
				par[v]=u;
				key[v]=w[u][v];
				pq[v].p=w[u][v];
			}
		}
		i++;
	}
	printMST(par,n,w);
}
int main()
{
  int w[30][30], key[30], par[30],i,j,n;
  cout<<"Enter the no. of vertices in the graph : ";
  cin>>n;
  cout<<"Enter the inputs for weight matrix \n";
  for(i=0;i<n;i++)
  {
  	for(j=0;j<n;j++)
  	{
  		cin>>w[i][j];
	}
  }
  	edge e[30];
  	int k=0;
  cout<<"The edges and their weights in the minimum spanning tree are \n";
  MST_prim(w,par,key,n,e,k);
  return 0;  
}
