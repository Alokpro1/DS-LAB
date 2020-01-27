#include <bits/stdc++.h>
  
using namespace std; 


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
int n,t=0,vr=0;
int m[50][50];
int x[10];
 

vector<int> adj1[55]; 
int main() 
{ 
    

    
      char c;
      n=1;
    do{
        if(n==1)
    cout<<"Ring topology\n";
     else if(n==2)
     cout<<"Tree topology \n ";
     else
     cout<<"Star topology \n";
   
    cout<<"enter the number of vertices:";
        int V;
        cin>>V;
        x[t]=vr;
        cout<<x[t]<<"d\n";
        
    switch (n)
    {
    case 1:
    {
        
        for(int i = vr;i<(vr+V-1);i++)
            {m[i][i+1]=1;
            m[i+1][i]=1;
            addEdge(adj1, i, i+1);
            }
            m[vr][vr+V-1]=1;
            m[vr+V-1][vr]=1;

            addEdge(adj1,vr,(vr+V-1));
        printGraph(adj1,vr,(vr+V));
        t++;
        vr+=V;
	x[t]=vr;
        break;
    }
    case 2:
    {
        int k;
        cout<<"Enter the no.of childs:";
        cin>>k;

        int r=0;
     //int E = V-1; 
        
        for(int i = 1;i<(V);i++)
        {
          
            addEdge(adj1, (r+vr), i+vr);
            m[(r+vr)][i+vr]=1;
            m[i+vr][r+vr]=1;
            if(i%k==0)
            r++;
        }
        printGraph(adj1,vr,(vr+V));
        t++;
        vr+=V;
x[t]=vr;
        break;
    }
    case 3:
       {
        for(int i = (1+vr);i<(vr+V);i++)
        {   
            addEdge(adj1, (0+vr), i);
            m[i][1+vr]=1;
        }   
        printGraph(adj1,vr,(vr+V));
        t++;
        vr+=V;
x[t]=vr;
        break;
       }
    default:
        cout<<"Wroung input\n";
        break;
    }
  
   n++;   
    }while(n<=3);

int x1=rand()%(x[1]-x[0]+1)+x[0];
 int x2=rand()%(x[2]-x[1]+1)+x[1];

int x3=rand()%(x[3]-x[2]+1)+x[2]-1;

cout<<x1<<"of 1st topology connects to "<<x2<<" 2nd topology\n"; 
addEdge(adj1, x1, x2);
 
cout<<x2<<"of 2nd topology connects to "<<x3<<" 3rd topology\n"; 
addEdge(adj1, x2, x3);
    cout<<"matrix is:\n";
    int i,j;
    for ( i = 0; i < vr; i++)
    {
        for ( j = 0; j < vr; j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<"\n";
        
    }
  
     printGraph(adj1,0,vr);
    
    return 0; 
} 
