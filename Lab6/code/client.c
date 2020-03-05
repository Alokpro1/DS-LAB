// Client side C/C++ program to demonstrate Socket programming 
#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#include <time.h> 
#define PORT 3000 

int main(int argc, char const *argv[]) 
{ 
	int sock = 0, valread; 
	struct sockaddr_in serv_addr; 
	char *hello = (char*)malloc(sizeof(char)*50); 
   

   
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
    struct tm* local; 
    time_t t = time(NULL); 
  
    
    local = localtime(&t); 
  
     
    char *stime=asctime(local); 
    send(sock , stime , strlen(stime) , 0 ); 
	printf("Request sent\n"); 


	if(valread = read( sock , buffer, 1024)) 
    {
        int x;
        sscanf(buffer,"%d",&x);

        int i, Number, count, Minimum=1, Maximum=x,f=0; 

  
 
  
        for(Number = Minimum; Number <= Maximum; Number++)
        {
            count = 0;
            for (i = 2; i <= Number/2; i++)
            {
                if(Number%i == 0)
                {
  	                count++;
  	                break;
                }
            }
            if(count == 0 && Number != 1 )
            {
                printf(" %d \n", Number);
                f++;
            }  
            
        }
        printf("\n");

         
        sprintf(hello,"%d",f);
        send(sock , hello , strlen(hello) , 0 ); 

    } 
	return 0; 
} 
