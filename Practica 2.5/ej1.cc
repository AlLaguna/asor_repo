#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

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

   getaddrinfo(argv[1], NULL, &hints, &res);
   char host[NI_MAXHOST];
   for (res1 = res; res1 != NULL; res1 = res1->ai_next)
   {
       getnameinfo(res1->ai_addr, res1->ai_addrlen, host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
       cout << host << ": " << res1->ai_family << " " << res1->ai_socktype << endl;
   }

    return 0;
}
