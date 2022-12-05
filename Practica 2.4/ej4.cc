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

    int fd = open(argv[1], O_CREAT | O_WRONLY, 0666);

    if(fd == -1)
    {
        cout << "ERROR open()" << endl;
        exit(-1);
    }

	write(fd, argv[1], 1024);
	close(fd);

	return 0;
}
