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


	connect(soc, res->ai_addr, res->ai_addrlen);



    while(true)
    {

        char msg[128];
        fgets(msg, 128, stdin);

        send(soc, msg, sizeof(msg), 0);

        if (msg != "Q")
		{		
			char buf[128];
			
			/* Recibir la respuesta. */
			recv(soc, buf, 128, 0);
			
			cout << "Respuesta: " << msg << endl;
		}
		else
		{
			close(soc);
			return 0;
		}
        
    }


    return 0;
}
