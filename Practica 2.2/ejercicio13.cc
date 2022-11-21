#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


using namespace std;


int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDWR);
    int fd1 = open(argv[2], O_RDWR);
    dup2(fd, 2); //stderr
    dup2(fd, 1); //stdout
    cout << "Holaaa" << endl << "Esto es una prueba de redicreccion" << endl;
}

//Depende del orden en el que se redireccionan de izq a der
