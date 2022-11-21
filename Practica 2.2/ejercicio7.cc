#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;


int main()
{
    umask(0027);
    int ret = open("./prueba", O_RDWR | O_CREAT);

    return 1;
}