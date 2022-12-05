#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

    //pipe() necesita como argumento: representa ambos extremos de la tuberia
    //0 = read || 1 = write
    int tuberia[2];

    pid_t pid;

    if(pipe(tuberia) == -1)
    {
        cout << "ERROR pipe()" << endl;
        exit(-1);
    }

    pid = fork();

    if(pid == -1)
    {
        cout << "ERROR fork()" << endl;
        exit(-1);
    }

    //PADRE
    if(pid == 0)
    {
        close(tuberia[0]); //Cierra el otro extremo "Nota: Antes de ejecutar el comando correspondiente, deben cerrarse todos los descriptores no necesarios."
        dup2(tuberia[1], STDOUT_FILENO); //old, new

        execlp(argv[1], argv[1], argv[2], NULL); //Ejecuta el 2ndo comando 
    }
    else //HIJO
    {
        close(tuberia[1]);
        dup2(tuberia[0], STDIN_FILENO); //

        execlp(argv[3], argv[3], argv[4], NULL); //Ejecuta el 2ndo comando 
    }

    return 0;

}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

    //pipe() necesita como argumento: representa ambos extremos de la tuberia
    //0 = read || 1 = write
    int tuberia[2];

    pid_t pid;

    if(pipe(tuberia) == -1)
    {
        cout << "ERROR pipe()" << endl;
        exit(-1);
    }

    pid = fork();

    if(pid == -1)
    {
        cout << "ERROR fork()" << endl;
        exit(-1);
    }

    //PADRE
    if(pid == 0)
    {
        close(tuberia[0]); //Cierra el otro extremo
        dup2(tuberia[1], STDOUT_FILENO); //old, new

        execlp(argv[1], argv[1], argv[2], NULL); //Ejecuta el 2ndo comando 
    }
    else //HIJO
    {
        close(tuberia[1]);
        dup2(tuberia[0], STDIN_FILENO); //

        execlp(argv[3], argv[3], argv[4], NULL); //Ejecuta el 2ndo comando 
    }

    return 0;

}
