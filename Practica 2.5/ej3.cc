#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/time.h>
#include <time.h>

using namespace std;

int main(int argc, char *argv[])
{
    struct addrinfo hints;
	struct addrinfo *res;
	struct addrinfo *res1;

    
    hints.ai_family = AF_UNSPEC;    
	hints.ai_socktype = SOCK_DGRAM; 
	hints.ai_protocol = 0;    


    hints.ai_flags = AI_PASSIVE;      
	hints.ai_canonname = NULL;
	hints.ai_addr = NULL;
	hints.ai_next = NULL;

    getaddrinfo(argv[1], argv[2], &hints, &res);
    

    int soc = socket(res->ai_family, res->ai_socktype, res->ai_protocol);	

    ssize_t send = sendto(soc, argv[3], sizeof(argv[3]), 0, res->ai_addr, res->ai_addrlen);

    struct sockaddr_storage cAddr;
    socklen_t cAddrLen = sizeof(cAddr);
		
	char buf[128];
		
	recvfrom(socket_d, buf, BUFFER_SIZE, 0, (struct sockaddr *) &cAddr, &cAddrLen);

		
	cout << buf << endl;
    
    return 0;
}
