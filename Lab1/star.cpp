#include <bits/stdc++.h> 
  
using namespace std; 

// A utility function to add an edge in an 
// undirected graph. 
void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 
  
// A utility function to print the adjacency list 
// representation of graph 
void printGraph(vector<int> adj[], int V) 
{ 
cout<<"the adjacency list is:"<<endl;
vector<int>::iterator ptr; 
for(int i=1;i<=V;i++)
{
cout<<"node "<<i<<" ->";
for(ptr = adj[i].begin();ptr<adj[i].end();ptr++)
cout<<*ptr<<" ";
cout<<"\n"; 
}
} 

int main() 
{ 
    // Graph 1 
    cout<<"enter the number of vertices\n";
int V;
cin>>V;
     //int E = V-1; 
    vector<int> adj1[V + 1]; 
      for(int i = 2;i<=	V;i++)
      addEdge(adj1, 1, i);   
    printGraph(adj1,V);
    return 0; 
} 
