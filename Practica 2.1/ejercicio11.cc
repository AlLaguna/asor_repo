#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstring>

using namespace std;


int main(int argc, char *argv[])
{
    struct stat buf;
    char* path = argv[1];
    stat(path, &buf);
    if(S_ISREG(buf.st_mode)) //Es un fichero regular
    {
        int status1 = link(path, "fichero.hard");
        int status2 = symlink(path, "fichero.sym");
    }
    return 1;
}