/*Write a program to create a hybrid topology by randomly connecting one from tree ,star and ring topology.Using
rand() function select two nodes from the hybrid toplogy and print the shortest path and the total weight.
use rand() to give weight b/w the vertices*/



// Floyd-warshal Algo has been used.
#include <bits/stdc++.h>
  
using namespace std; 

int n=1,t=0,vr=0,u=0;//n=current type of topology,t=************,vr=total no of vertices,u=total no of edges
int V;//current topology no of vertex
int m[50][50];//adjacent matrix of hybrid topology
int x[10];//prefix sum of each toplogy 
vector<int> adj1[55]; //adjacent list of hybrid topology

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

void Ring()
{
    for(int i = vr;i<(vr+V-1);i++)
        {
                int f=rand()%100;
                m[i][i+1]=f;
                m[i+1][i]=f;
                addEdge(adj1, i, i+1);
                u+=2;
        }
        int f=rand()%100;
        m[vr][vr+V-1]=f;
        m[vr+V-1][vr]=f;
        u+=2;

        addEdge(adj1,vr,(vr+V-1));
        printGraph(adj1,vr,(vr+V));
        t++;
        vr+=V;
	    x[t]=vr;
}

void Tree()
{
        int k;
        cout<<"Enter the no.of childs:";
        cin>>k;

        int r=0;
        //int E = V-1; 
        
        for(int i = 1;i<(V);i++)
        {
          
            addEdge(adj1, (r+vr), i+vr);
            int f=rand()%100;
            m[(r+vr)][i+vr]=f;
            m[i+vr][r+vr]=f;
            u+=2;
            if(i%k==0)
            r++;
        }
        printGraph(adj1,vr,(vr+V));
        t++;
        vr+=V;
        x[t]=vr;
}

void Star()
{
    for(int i = (1+vr);i<(vr+V);i++)
        {   
            addEdge(adj1, (0+vr), i);
            int f=rand()%100;
            m[i][1+vr]=f;
            m[1+vr][i]=f;
            u+=2;
        }   
        printGraph(adj1,vr,(vr+V));
        t++;
        vr+=V;
        x[t]=vr;
}

int main() 
{ 
    

    
     
    do{
        if(n==1)
            cout<<"Ring topology \n";
        else if(n==2)
            cout<<"Tree topology \n";
        else
            cout<<"Star topology \n";

    
        
        cin>>V;
        x[t]=vr;
        cout<<x[t]<<"d\n";
        
    switch (n)
    {
    case 1:
        Ring();
        break;
    case 2:
        Tree();   
        break;
    
    case 3:
        Star();
        break;

    default:
        cout<<"Wroung input\n";
        break;
    }
  
   n++;
    }while(n<=3);

    int x1=rand()%(x[1]-x[0]+1)+x[0];
    int x2=rand()%(x[2]-x[1]+1)+x[1];
    cout<<x1<<" of 1st topology connects to "<<x2<<" of 2nd topology\n"; 
    addEdge(adj1, x1, x2);
    m[x1][x2]=rand()%100;
    m[x2][x1]=rand()%100;

    int x3=rand()%(x[3]-x[2]+1)+x[2];
    x2=rand()%(x[2]-x[1]+1)+x[1];
    cout<<x2<<" of 2nd topology connects to "<<x3<<" of 3rd topology\n"; 
    addEdge(adj1, x2, x3);
    m[x2][x3]=rand()%100;
    m[x3][x2]=rand()%100;




    cout<<"matrix is:\n";
    u+=2;
    int i,j;
    for ( i = 0; i < vr; i++)
    {
        for ( j = 0; j < vr; j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<"\n";
        
    }
  
    //  printGraph(adj1,0,vr);

     
    spath(x1,x2,vr,u);
    return 0; 
} 
