// Server side C/C++ program to demonstrate Socket programming 
#include <bits/stdc++.h>
#include <iostream> 

/* fstream header file for ifstream, ofstream, 
fstream classes */
#include <fstream> 

#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <malloc.h>
#include <time.h>


using namespace std; 
#define PORT 3000 

    map <int,pair<int,int> > cache;
	map <int,pair<int,int> > ::iterator it;
	queue <int> fifo;
int main(int argc, char const *argv[]) 
{ 
	int server_fd, new_socket, valread; 
	struct sockaddr_in address; 
	int opt = 1; 
	int addrlen = sizeof(address); 
	char buffer[1024] = {0}; 
	//char *hello = (char*)malloc(sizeof(char)*50); //

	char *status = (char*)malloc(sizeof(char)*50);  


	 

	

	
	
	// Creating socket file descriptor 
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
	{ 
		perror("socket failed"); 
		exit(EXIT_FAILURE); 
	} 
	
	// Forcefully attaching socket to the port 8080 
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
												&opt, sizeof(opt))) 
	{ 
		perror("setsockopt"); 
		exit(EXIT_FAILURE); 
	} 
	address.sin_family = AF_INET; 
	address.sin_addr.s_addr = INADDR_ANY; 
	address.sin_port = htons( PORT ); 
	
	// Forcefully attaching socket to the port 8080 
	if (bind(server_fd, (struct sockaddr *)&address, 
								sizeof(address))<0) 
	{ 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	} 
	if (listen(server_fd, 3) < 0) 
	{ 
		perror("listen"); 
		exit(EXIT_FAILURE); 
	} 
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
					(socklen_t*)&addrlen))<0) 
	{ 
		perror("accept"); 
		exit(EXIT_FAILURE); 
	} 

    /////////////////////
    int time=0;
	while(true)
	{
    //////////////////////////
    


			int idt,id,data,x;
			valread = read( new_socket , buffer, 1024); 
            sscanf(buffer,"%d",&id);
			//cout<<"req=>"<<id<<endl;
		
			cout<<"<==Stack==>"<<endl;
            pair<int,int> itr;
			for(it=cache.begin();it!=cache.end();++it)
			{
				cout<<it->first<<"::";
                itr=it->second;
                cout<<"data: "<<itr.first<<" pr: "<<itr.second<<endl;
			}
			it=cache.find(id);
            if(it != cache.end())
			{
				x=1;
    			sprintf(status,"%d",x);
				send(new_socket , status , strlen(status) , 0 );
                itr=it->second;
                int y=itr.first;
                cache.erase(id);
                cache.insert({id,pair<int,int>(y,time)});
                time++;
			}
			else
			{
				// Creation of ifstream class object to read the file 
				ifstream fin; 

	// by default open mode = ios::in mode 
	
				string line;

				fin.open("sample.txt"); 
				while (fin) { 

				// Read a Line from File 
					getline(fin, line); 
					stringstream geek(line); 
        			int idf,flag=0;

        			geek >> idf;
					if(idf==id)
					    flag=1; 
				
					if(flag==1)
					{
						getline(fin, line); 
						stringstream geek(line);
						geek >> data;
						break;
					}
				} 
				fin.close(); 



				if(cache.size()<3)
				{

					cout<<"id@"<<id<<"data"<<data<<endl;
					cache.insert({id, pair<int,int>(data,time)});
                    time++;

					//cout<<cache.size();
					
				}
				else
				{
                    int idd,t=785;
                    pair<int,int> itr;
					for(it=cache.begin();it!=cache.end();++it)
                    {
                        itr=it->second;
                        if(itr.second<t)
                           {
                               idd=it->first;
                               t=itr.second;
                           }
                    }
                    cache.erase(idd);
					cache.insert({id,pair<int, int>( data,time)});
                    time++;
				}
				 x=0;
    			sprintf(status,"%d",x);
				send(new_socket , status , strlen(status) , 0 );
               //cout<<"="<<x<<endl;
			}
			fflush(stdin);
			   






	}



    
	return 0; 
} 
