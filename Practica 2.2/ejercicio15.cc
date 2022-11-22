#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>
#include <string.h>
using namespace std;


int main()
{
    int fd = open("prueba", O_RDWR);
    int ret = lockf(fd, 0, 0);
    if(ret >= 0)
    {
        cout << time(NULL) << endl;
        sleep(10);
    }
    else
    {
        perror(strerror(ret));
    }
    
    return 0;
}