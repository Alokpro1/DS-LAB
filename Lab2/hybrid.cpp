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
cout<<"\n"; 
}
} 
int n,t=0,vr=0;
int m[50][50];

vector<int> adj1[55]; 
int main() 
{ 
    

    
      char c;
    do{
    cout<<"Enter type of topology\n1.Ring topology \n2.Tree topology \n3.Star topology \n";
    cin>>n;
    cout<<"enter the number of vertices:";
        int V;
        cin>>V;
        
        
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
        break;
       }
    default:
        cout<<"Wroung input\n";
        break;
    }
  
    cout<<"want to continue(y/n):";
    cin>>c;
    }while(c=='y');


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
    
    
    return 0; 
} 
