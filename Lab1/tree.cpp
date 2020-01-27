#include <bits/stdc++.h>
  
using namespace std; 


void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 
  

void printGraph(vector<int> adj[], int V) 
{ 
cout<<"the adjacency list is:"<<endl;
vector<int>::iterator ptr; 
for(int i=0;i<V;i++)
{
cout<<"node "<<i<<" ->";
for(ptr = adj[i].begin();ptr<adj[i].end();ptr++)
cout<<*ptr<<" ";
cout<<"\n"; 
}
} 

int main() 
{ 
    
    cout<<"enter the number of vertices\n";
int V;
cin>>V;
int k;
cin>>k;

int r=0;
     //int E = V-1; 
    vector<int> adj1[V + 1]; 
      for(int i = 1;i<	V;i++)
      {
          
        addEdge(adj1, r, i);
        cout<<r<<" -"<<i<<endl; 
        if(i%k==0)
            r++;
      }
   printGraph(adj1,V);
    return 0; 
} 
