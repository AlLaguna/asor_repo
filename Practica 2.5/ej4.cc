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

    cout << "En escucha" << endl;

    char cliente[NI_MAXHOST];
	char servicio[NI_MAXSERV];
    char buf[8];
    ssize_t l;
	time_t t;
	size_t time_bytes;
	struct tm *tm;
	char mensaje[128];

    struct sockaddr_storage cAddr;
	socklen_t cAddrLen = sizeof(cAddr);

    fd_set set;
	FD_SET(0, &set); 		
	FD_SET(soc, &set); 	

    while(true)
    {

        select(soc, &set, NULL, NULL, NULL);
    
        if (FD_ISSET(0, &set))
		{
			int bytes = read(0, buf, 128);
			cout << bytes << " por stdi" << endl;
		}
        else
		{
			
			l = recvfrom(soc, buf, 8, 0, (struct sockaddr *) &cAddr, &cAddrLen);			

			getnameinfo((struct sockaddr *) &cAddr, cAddrLen, cliente, NI_MAXHOST, servicio, NI_MAXSERV, NI_NUMERICHOST | NI_NUMERICSERV);
		    cout << l << "bytes de " << cliente << " con servicio " << servicio << ": " << buf << endl;
        }


        t = time(NULL);
		tm = localtime(&t);

        if (buf[0] == 't')
		{
			time_bytes = strftime(mensaje, 128, "%T", tm);

            if (FD_ISSET(0, &set))
			{
				cout << mensaje << endl;
			}
			else
			{
			    sendto(soc, mensaje, time_bytes + 2, 0, (struct sockaddr *) &cAddr, cAddrLen);
            }
		}
        else if (buf[0] == 'd')
		{
			time_bytes = strftime(mensaje, 128, "%F", tm);
			
            if (FD_ISSET(0, &set))
			{
				cout << mensaje << endl;
			}
			else
			{
			    sendto(soc, mensaje, time_bytes + 2, 0, (struct sockaddr *) &cAddr, cAddrLen);
            }
			
		}
        else if (buf[0] == 'q')
		{
			cout << "EXIT" << endl;
			
			exit(EXIT_SUCCESS);
		}
    }
    
    return 0;
}
