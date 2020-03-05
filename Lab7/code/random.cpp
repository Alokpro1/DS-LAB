/* File Handling with C++ using ifstream & ofstream class object*/
/* To write the Content in File*/
/* Then to read the content of file*/
#include <bits/stdc++.h>
#include <iostream> 

/* fstream header file for ifstream, ofstream, 
fstream classes */
#include <fstream> 

using namespace std; 
using namespace std::chrono; 
// Driver Code 
int main() 
{ 
	// Creation of ofstream class object 
	ofstream fout; 

	string line; 

	// by default ios::out mode, automatically deletes 
	// the content of file. To append the content, open in ios:app 
	// fout.open("sample.txt", ios::app) 
	fout.open("sample.txt"); 

	// Execute a loop If file successfully opened 
     auto start = high_resolution_clock::now();
	while (fout) { 

		// Read a Line from standard input 
		//getline(cin, line); 
        int i=0,count=100;
        for ( i = 0; i < count; i++)
        {
            fout << i << endl;
            int data=rand()%(1200-1100)+1100;
            fout << data << endl;

        }
        line ="-1";

		// Press -1 to exit 
		if (line == "-1") 
			break; 

		// Write line in file 
		fout << line << endl; 
	} 

	// Close the File 
	fout.close(); 

	// Creation of ifstream class object to read the file 
	ifstream fin; 

	// by default open mode = ios::in mode 
	fin.open("sample.txt"); 

	// Execute a loop until EOF (End of File) 
	while (fin) { 

		// Read a Line from File 
		getline(fin, line); 

		// Print line in Console 

        stringstream geek(line); 
        int x;

        geek >> x; 
		cout << line << endl; 
	} 
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

	// Close the file 
	fin.close(); 

	return 0; 
} 
