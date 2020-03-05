/*Design a random topoogy of 10 nodes. Determine the degree of each node randomly(Max:3)
For each node detremine the neighbouring nodes, randomly based on degree. Determine whether the topology is connected or not.
Display the adjacency matrix and determine the path for all possible pairs of nodes.

*/



// Floyd-warshal Algo has been used.
#include <bits/stdc++.h>
  
using namespace std; 

int u=0;//u=total no of edges
int V;//current topology no of vertex
int m[10][10];//adjacent matrix of hybrid topology

vector<int> adj1[10]; //adjacent list of hybrid topology

void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 
  

void printGraph(vector<int> adj[],int k, int V) 
{ 
    cout<<"the adjacency list is:"<<endl;
    vector<int>::iterator ptr; 
    for(int i=k;i<V;i++)
    {
        cout<<"node "<<i<<" ->";
        for(ptr = adj[i].begin();ptr<adj[i].end();ptr++)
            cout<<*ptr<<" ";
        cout<<"Degree:"<<adj[i].size();
        cout<<"\n"; 
    }
} 

void print(int i,int j,int temp[])
{
    if(temp[j]<0)
    {
        return;
    }
    else if(i==temp[j])
    {
        return;
    }
    else
    {
        print(i,temp[j],temp);
        printf("-->%d",temp[j]);
    }
}

void spath(int p,int q,int node,int edge)
{
    int i,j,k;

    
    

    int dist[node][node];
    int parent[node][node];

    for(i=0;i<node;i++)
    {
        for(j=0;j<node;j++)
        {
            parent[i][j]=-1;
            if(i==j)
                dist[i][j]=0;
            else
                dist[i][j]=1000;
        }
    }




    

    for ( i = 0; i < node; i++)
    {
        for ( j = 0; j < node; j++)
        {
            if(m[i][j]!=0)
            {
                dist[i][j]=m[i][j];
                parent[i][j]=i;
            }
        }
        
        
    }


    for(i=0;i<node;i++)
    {
        for(j=0;j<node;j++)
        {
            for(k=0;k<node;k++)
            {
                if((dist[j][i]+dist[i][k])<dist[j][k])
                {
                    dist[j][k]=dist[j][i]+dist[i][k];
                    if(i>=1)
                        parent[j][k]=parent[i][k];
                }
            }
        }
    }
    
    
    int temp[node];
    for(k=0;k<node;k++)
        temp[k]=parent[p][k];

        
    cout<<"The minimum distance from"<<p<<" to "<<q<< "is: "<<dist[p][q]<<" and path is: ";
    print(p,q,temp);
    cout<<"==>"<<q<<"\n";
        
    

}


void trand(int n)
{
    for(int i=0;i<n;++i)
    {
        int x1=rand()%10;
        if(adj1[x1].size()<3 && i!=x1)
         {
            addEdge(adj1, x1, i);
            int f=rand()%100;
            m[(x1)][i]=f;
            m[i][x1]=f;
            u+=2;
         }
    }
}

int main() 
{ 
    

    
     
    
    
        
        cin>>V;
        
        trand(V);
    
  
   
    

    
  

   




    cout<<"matrix is:\n";
   
    int i,j;
    for ( i = 0; i < V; i++)
    {
        for ( j = 0; j < V; j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<"\n";
        
    }
  
    //  printGraph(adj1,0,vr);

     
    //spath(x1,x2,V,u);
    return 0; 
} 
