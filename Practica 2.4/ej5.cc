#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{

    int fd1 = open("./fifo1", O_RDONLY | O_NONBLOCK);
    int fd2 = open("./fifo2", O_RDONLY | O_NONBLOCK);
    

    fd_set fd;
	FD_ZERO(&fd);
	FD_SET(fd1, &fd);
	FD_SET(fd2, &fd);


    int maxFD = 0;
    if(fd1 > fd2) 
        maxFD = fd1;
    else maxFD = fd2;

    timeval timeV = {
		.tv_sec = 10,
		.tv_usec = 0
	};

    int sel = select(maxFD, &fd, NULL, NULL, &timeV);

    if (sel)
	{
		char buf[256];

		if (FD_ISSET(fd1, &fd))
		{
			read(fd1, buf, 256);
			cout << "FIFO1 " << buf << endl;
		}
		else if (FD_ISSET(fd2, &fd))
		{
			read(fd2, buf, 256);
			cout << "FIFO2 " << buf << endl;
		}
	}
	else
	{
		cout << "TIMEOUT" << endl;
    }

    close(fd1);
    close(fd2);
    return 0;
}
