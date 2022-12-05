#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>

using namespace std;

int main(int argc, char const *argv[])
{

    //  0 -> lectura  ||  1 -> escritura

    if(mkfifo("./fifo", S_IRWXU | S_IRWXG | S_IRWXO) == -1)
    {
        cout << "ERROR mkfifo()" << endl;
        exit (-1);
    }

    int fd = open("./fifo", O_WRONLY);
    if(fd == -1)
    {
        cout << "ERROR open()" << endl;
    }

    write(fd, argv[1], 1024);

    struct stat s;
    fstat(fd, &s);

    cout << s.st_mode << endl;
    cout << s.st_size << endl;
    cout << s.st_dev<< endl;
    cout << s.st_uid << endl;
     cout << s.st_gid << endl;


    
}
