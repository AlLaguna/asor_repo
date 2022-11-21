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

//Para asegurarnos de que no afecta la mascara puesta anteriormente, simplemente vale on cerrar yvolver a abrir la consola antes de ejecutar el programa
