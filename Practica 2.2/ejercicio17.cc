#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>

using namespace std;


int main(int numArg, const char *argv[])
{
    if(numArg != 2)
    {
        cout << "ERROR ARGUMENTOS" << endl;
    }
    else
    {
        DIR *directorio = opendir(argv[1]);

        if(directorio == NULL)
        {
            cout << "ERROR DIRECTORIO" << endl;
        }
        else{

            struct dirent *d;
            int tamaño = 0;
            while((d = readdir(directorio)) != NULL)
            {
                struct stat buf;
                stat(d->d_name, &buf);

                if(d->d_type == DT_DIR)//Directorio  /
                {
                    cout << "/ " << d->d_name << endl;
                }
                else if(d->d_type == DT_REG)//fichero regular con permiso de ejecucion
                {
                    if(buf.st_mode == S_IXUSR || buf.st_mode == S_IXOTH || buf.st_mode == S_IXGRP)
                    {
                        cout << "* " << d->d_name << endl;
                    }
                    else
                    {
                        cout << d->d_name << endl;
                    }
                }
                else if(d->d_type == DT_LNK) //Enlace simbolico ->
                {
                    char linkname[256];
                    ssize_t r = readlink(d->d_name, linkname, 256);
                    cout << d->d_name << " -> " << linkname << endl;
                }       
                
                tamaño = tamaño + buf.st_size;
            }
            cout << "tamanio: " << tamaño << endl;
        }
    }
    cout << endl;
}