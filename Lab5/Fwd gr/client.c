// Client side C/C++ program to demonstrate Socket programming 
#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#include <time.h> 
#define PORT 8080 

int main(int argc, char const *argv[]) 
{ 
	int sock = 0, valread; 
	struct sockaddr_in serv_addr; 
	char *hello = (char*)malloc(sizeof(char)*50); 
    int rt =rand()%14 +7;
    sprintf(hello,"%d",rt);
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
     clock_t ts; 
    ts = clock(); 
	send(sock , hello , strlen(hello) , 0 ); 
	printf("Hello message sent\n"); 
	if(valread = read( sock , buffer, 1024)) 
    {
        ts = clock() - ts; 
    double time_taken = ((double)ts)/CLOCKS_PER_SEC; // in seconds 
	printf("%s => %f\n",buffer,time_taken );
    } 
	return 0; 
} 
