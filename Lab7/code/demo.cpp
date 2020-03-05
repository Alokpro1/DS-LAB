// CPP code to illustrate 
// Queue in Standard Template Library (STL) 
#include <iostream> 
#include <queue> 

using namespace std; 

void showq(queue <pair<int,int> > gq) 
{ 
	queue <pair<int,int> > g = gq; 
	while (!g.empty()) 
	{ 
		cout << '\t' << g.front(); 
		g.pop(); 
	} 
	cout << '\n'; 
} 

int main() 
{ 
	queue <pair<int,int> > gquiz; 
	gquiz.push(pair<int, int>(2, 3)); 
	gquiz.push(pair<int, int>(27, 37)); 
	gquiz.push(pair<int, int>(25, 43)); 

	cout << "The queue gquiz is : "; 
	showq(gquiz); 

	cout << "\ngquiz.size() : " << gquiz.size(); 
	cout << "\ngquiz.front() : " << gquiz.front(); 
	cout << "\ngquiz.back() : " << gquiz.back(); 

	cout << "\ngquiz.pop() : "; 
	gquiz.pop(); 
	showq(gquiz); 

	return 0; 
} 
