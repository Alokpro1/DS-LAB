#include <iostream>
#include <fstream>
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <time.h>
#define PORT 8000

using namespace std;

struct data
{
	int num;
	int data;
	int time;
};

int main(int argc, char const *argv[]) 
{ 
	struct data arr[3];
	int delim = 0;
	
	struct data arr2[3];
	int delim2 =0;
	
	fstream fd;
	fd.open("number.txt", ios::out);
	int l;
	for(l=0; l<100; l++)
	{
		fd<<l+1<<" "<<rand()%100 + 101<<endl;
	}
	
    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    int buffer;
    char *hello ; 
       
    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
       
    // Forcefully attaching socket to the port 8080 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
       
    // Forcefully attaching socket to the port 8080 
    if (bind(server_fd, (struct sockaddr *)&address,  sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    if (listen(server_fd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 
    ///FIFO
    int hit_fifo =0;
    struct data tsend;
    int j;
    int time = 0;
    arr[0].num = 34;
    int h =0;
    int next =0;
    for(int l = 0; l<50; l++)
    {
   	valread = read( new_socket , &buffer, sizeof(buffer));
   	h =0;
   	for(j=0; j<delim; j++)
   	{
   		if(arr[j].num == buffer)
   		{
   			hit_fifo++;
   			h = 1;
   			break;
   		}
   	}
   	if(h == 0)     ////miss
   	{
   	    fd.clear();
	    fd.seekg(0, fd.beg);
	    int a, b;
	    while(fd>>a>>b)
	    {
	    	if(a == buffer)
	    	{
	    		break;
	    	}
	    }
	    if(delim<3)
	    {
	    	arr[delim].num = a;
	    	arr[delim].data = b;
	    	delim++;
	    }
	    else
	    {
	    	arr[next].num = a;
	    	arr[next].data = b;
	    	next= (next+1)%3;
	    }
	    tsend.num = a;
	    tsend.data =  b;
   		
   	}
   	else
   	{
   		tsend.num = arr[j].num;
   		tsend.data = arr[j].data;
   		delim++;
   	}
    
    	send(new_socket , &tsend , sizeof(tsend) , 0 ); 
    }
    
    
    //lru 
    int hit_lru =0;
    time = 0;
    for(int l = 0; l<100; l++)
    {
   	valread = read( new_socket , &buffer, sizeof(buffer));
   	h=0;
   	for(j=0; j<delim2; j++)
   	{
   		if(arr2[j].num == buffer)
   		{
   			hit_lru++;
   			h= 1;
   			break;
   		}
   	}
   	if(h == 0)
   	{
		fd.clear();
		fd.seekg(0, fd.beg);
		int a, b;
		while(fd>>a>>b)
		{
			if(a == buffer)
			{
				break;
			}
		}
		if(delim2 <3)
		{
			arr2[delim2].num = a;
			arr2[delim2].data = b;
			arr2[delim2].time = time;
			delim2++;
			time++;
		}
		else
		{
			int z;
			int min = 10000;
			int min_z;
			for(z=0; z<delim; z++)
			{
				if(arr2[z].time < min)
				{
					min = arr2[z].time;
					min_z = z;
				}
			}
			arr2[min_z].num = a;
			arr2[min_z].data = b;
			arr2[min_z].time = time;
			time++;
		}
		tsend.num = a;
		tsend.data = b;
	}
	else
	{
		tsend.data = arr2[j].data;
		tsend.num = arr2[j].num;
	}
    	send(new_socket , &tsend , sizeof(tsend) , 0 ); 
    }
    printf("Hit ratio for\n(i)FIFO: %d\n(ii)LRU: %d\n",hit_fifo, hit_lru);
    fd.close();
     
    return 0; 
} 


