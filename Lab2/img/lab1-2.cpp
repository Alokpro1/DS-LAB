#include <bits/stdc++.h> 
  
using namespace std; 

void Edge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 
  

void Graph(vector<int> adj[], int V) 
{ 
cout<<"Adjacency list:"<<endl;
vector<int>::iterator ptr; 
for(int i=1;i<=V;i++)
{
cout<<"Node: "<<i<<" ->";
for(ptr = adj[i].begin();ptr<adj[i].end();ptr++)
cout<<*ptr<<" ";

cout<<"  "<<"Degree:"<<adj[i].size();

cout<<"\n"; 
}
} 

int main() 
{ 
    
    cout<<"Enter no.of vertices\n";
int V;
cin>>V;
     
    vector<int> adj1[V + 1]; 
      for(int i = 2;i<=	V;i++)
      Edge(adj1, 1, i);   
    Graph(adj1,V);
    return 0; 
} 
