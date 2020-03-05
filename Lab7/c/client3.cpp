#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h> 
#define PORT 8080 

struct data
{
	int num;
	int data;
	int time;
};
   
int main(int argc, char const *argv[]) 
{ 
    int sock = 0, valread; 
    
    struct sockaddr_in serv_addr; 
    
    
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
    
    int *hello;
    //printf("After conversion: %s\n", b);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
	printf("\nConnection Failed \n"); 
	return -1; 
    }
    
   struct data buffer;
    //printf("Time before sending message to server: \n%s\n\n", ctime(&t));
    
    //fifo
    clock_t t1, t2;
    t1 = clock();
    for(int l = 0; l<50; l++)
    {
    	int a = rand()%10 +1;
    	printf("Number to be sent: %d\n", a); 
    	send(sock , &a , sizeof(a) , 0 ); 
    	
    
    	valread = read( sock , &buffer, sizeof(buffer)); 
    	printf("%d\t%d\n", buffer.num, buffer.data);
    	
    }
    t2 = clock() - t1;
    printf("\nTOTAL DELAY FOR FIFO: %f\n",((float)t2)/CLOCKS_PER_SEC);
    
    //lru
    t1 = clock();
    for(int l = 0; l<100; l++)
    {
    	int a = rand()%10 +1;
    	printf("Number to be sent: %d\n", a); 
    	send(sock , &a , sizeof(a) , 0 ); 
    	
    
    	valread = read( sock , &buffer, sizeof(buffer)); 
    	printf("%d\t%d\n", buffer.num, buffer.data);
    	
    }
    t2 = clock() - t1;
    printf("\nTOTAL DELAY FOR LRU: %f\n",((float)t2)/CLOCKS_PER_SEC);
    
} 

