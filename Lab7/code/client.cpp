// Client side C/C++ program to demonstrate Socket programming 
#include <bits/stdc++.h>
#include <iostream> 

#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#include <time.h> 
#include <malloc.h>
using namespace std; 
using namespace std::chrono; 
#define PORT 3000 

int main(int argc, char const *argv[]) 
{ 
	int sock = 0, valread; 
	struct sockaddr_in serv_addr; 
	//char *hello = (char*)malloc(sizeof(char)*50); 
   
    char *id=(char*)malloc(sizeof(char)*50);
   
	char buffer[1024] = {0}; 
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
	{ 
		printf("\n Socket creation error \n"); 
		return -1; 
	} 

	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(PORT); 
	
	// Convert IPv4 and IPv6 addresses from text to binary form 
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
	{ 
		printf("\nInvalid address/ Address not supported \n"); 
		return -1; 
	} 

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
	{ 
		printf("\nConnection Failed \n"); 
		return -1; 
	} 
    ////////////////////////////////
    // struct tm* local; 
    // time_t t = time(NULL); 
  
    
    // local = localtime(&t); 
  
     
    // char *stime=asctime(local); 
    // send(sock , stime , strlen(stime) , 0 ); 
	// printf("Request sent\n"); 
    ////////////////////////////////////////////////////////
    /*======================================*/
    auto start = high_resolution_clock::now();
        int i=0,count=100;
        int hit=0,miss=0;
       srand(time(0));
        for ( i = 0; i < count; i++)
        {
            
            int idr=rand()%100;
            sprintf(id,"%d",idr);
            cout<<"req=>"<<idr;
            send(sock , id , strlen(id) , 0 );
            int x;
          int valread = read( sock , buffer, 1024);
            sscanf(buffer,"%d",&x);
            cout<<"res=>"<<x<<endl;
            if(x==0)
                miss++;
            else
                hit++;
          
        }
        

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " milliseconds"<<endl;
          cout<<"Frame: 3"<<endl; 
         cout<<" Hit: "<<hit<<endl;
         cout<<" Miss: "<<miss<< endl; 
        



        // sprintf(id,"%d",f);
        // send(sock , id , strlen(id) , 0 );


	
        // printf("\n");

         
        // sprintf(hello,"%d",f);
        // send(sock , hello , strlen(hello) , 0 ); 

     
	return 0; 
} 
