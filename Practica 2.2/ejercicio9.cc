//
#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/sysmacros.h>

using namespace std;


int main()
{
    struct stat buf;
    int fd = open("./prueba", O_RDWR | O_CREAT);
    int ret = fstat(fd, &buf);
    cout << "Major: " << major(buf.st_dev) << endl;
    cout << "Minor: " << minor(buf.st_dev) << endl;
    cout << "Num inodo: " << buf.st_ino << endl;
    cout << "Tipo fichero: " << buf.st_mode << endl;
    cout << "Ultima vez: " << (string)buf.st_atim << endl;
    return 1;
}