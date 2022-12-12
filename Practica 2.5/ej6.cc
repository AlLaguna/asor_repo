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

    bind(soc, res->ai_addr, res->ai_addrlen);

    listen(soc,3);


	struct sockaddr_storage cAddr;
	socklen_t cAddrLen = sizeof(cAddr);
	int cliente;
	char clienteHost[NI_MAXHOST];
	char clienteServicio[NI_MAXSERV];
	ssize_t recLen;
	char cBuf[128];

    while(true)
    {
        cliente = accept(soc, (struct sockaddr *) &cAddr, &cAddrLen);
        getnameinfo((struct sockaddr *) &cAddr, cAddrLen, clienteHost, NI_MAXHOST, clienteServicio, NI_MAXSERV, NI_NUMERICHOST | NI_NUMERICSERV);
		
        cout << "Conexxion: " << clienteHost << ":" << clienteServicio << endl;


        while (1)
		{
			recLen = recv(cliente, cBuf, 128, 0);
			if (recLen == 0)
			{
				break;
			}

            send(cliente, cBuf, strlen(cBuf), 0);

			
			memset(cBuf, 0, 128);
        }

        cout << "fin conexion con " << clienteHost << ":" << clienteServicio << endl;
    }
	
    return 0;
}
