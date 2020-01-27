#include<iostream>
using namespace std;
int vertArr[20][20]; //the adjacency matrix initially 0
int count = 0;
void displayMatrix(int v) 
{
   int i, j;
   for(i = 0; i < v; i++) {
      for(j = 0; j < v; j++) {
         cout << vertArr[i][j] << " ";
      }
      cout << endl;
   }
}
void add_edge(int u, int v) 
{ //function to add edge into the matrix
   vertArr[u][v] = 1;
   vertArr[v][u] = 1;
}
int input()
{
	int number;
	cin>>number;
	return number;
}
int main() 

{

	cout<<"Enter the Type of Network Toplogy"<<endl;
	cout<<"1. Ring Topology " <<endl;
	cout<<"2. Star Topology " <<endl;
	cout<<"3. Tree Topology " <<endl;
	cout<<"4. Hypercube Topology " <<endl;
	char ch;
	ch = input();
	switch(ch)
	{
	case 1 : {
		int v = 5; //there are 6 vertices in the graph
		add_edge(0, 1);
		add_edge(0, 4);
		add_edge(1, 2);
		add_edge(1, 0);
		add_edge(2, 1);
		add_edge(2, 3);
		add_edge(3, 4);
		add_edge(3, 2);
		add_edge(4, 3);
		add_edge(4, 0);
		displayMatrix(v);
		break;
		}
	case 2 : {
		int v = 5; //there are 6 vertices in the graph
		add_edge(0, 1);
		add_edge(0, 2);
		add_edge(0, 3);
		add_edge(0, 4);
		add_edge(0, 5);
		displayMatrix(v);
		break;
		}
	case 3 : {
		int v = 7; //there are 6 vertices in the graph
		add_edge(0, 1);
		add_edge(0, 2);
		add_edge(1, 3);
		add_edge(1, 4);
		add_edge(2, 5);
		add_edge(2, 6);
		displayMatrix(v);
		break;
		}
	case 4 : {
		int v = 12; //there are 6 vertices in the graph
		add_edge(0, 1);
		add_edge(0, 3);
		add_edge(0, 4);
		add_edge(1, 0);
		add_edge(1, 2);
		add_edge(1, 5);
		add_edge(2, 1);
		add_edge(2, 3);
		add_edge(2, 6);
		add_edge(3, 0);
		add_edge(3, 2);
		add_edge(3, 7);
		add_edge(4, 0);
		add_edge(4, 5);
		add_edge(4, 7);
		add_edge(5, 1);
		add_edge(5, 4);
		add_edge(5, 6);
		add_edge(6, 2);
		add_edge(6, 5);
		add_edge(6, 7);
		add_edge(7, 3);
		add_edge(7, 4);
		add_edge(7, 6);
		displayMatrix(v);
		break;
		}
	default: cout<<"Wrong Output"<<endl;
	}
	return 0;
}
