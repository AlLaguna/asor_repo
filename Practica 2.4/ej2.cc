#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <iostream>
#include <fcntl.h>
using namespace std;

int main()
{

    //  0 -> lectura  ||  1 -> escritura

    int tuberiaPH[2];
	int tuberiaHP[2];

    pid_t pid;

    if(pipe(tuberiaPH) == -1)
    {
        cout << "ERROR tuberiaPH" << endl;
        exit(-1);
    }
    if(pipe(tuberiaHP) == -1)
    {
        cout << "ERROR tuberiaHP" << endl;
        exit(-1);
    }

    pid = fork();
    if(pid == -1)
    {
        cout << "ERROR fork()";
        exit(-1);
    }

    if(pid == 0) //HIJO
    {

        //Se cierran los extremos que no se vayan a utilizar
        close(tuberiaPH[1]);
        close(tuberiaHP[0]);

        char buff[1024];

        int numMsg = 0;
        while(numMsg < 10)
        {
            read(tuberiaPH[0], &buff, 1024);
            numMsg++;
            cout << "Recibido: " << buff << endl;
            sleep(1);
            if(write(tuberiaHP[1], "l", 1)==-1)
            {
                cout << "ERROR";
            } 
        }

        write(tuberiaHP[1], "q", 1);


    }
    else //PADRE
    {

        //Se cierran los extremos que no se vayan a utilizar
        close(tuberiaPH[0]);
        close(tuberiaHP[1]);

        char buff[1024];
        char buff1[1] = {'l'};//PAra leer la confirmacion de lectura del hijo
        
        while(buff1[0] != 'q')
        {
            read(STDIN_FILENO, &buff, 1024);

            
            write(tuberiaPH[1], buff, 1024);

            
            read(tuberiaHP[0], buff1, 1);
        }

        close(tuberiaPH[1]);
        close(tuberiaHP[0]);
        cout << "Finalizado padre: " << buff1 << endl;
    }


    return 1;
}
