#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;


int main()
{
    cout << "Informacion configuracion del sistema: " << endl;
    cout << "- Longitud maxima de argumentos: " << sysconf(_SC_ARG_MAX) << endl;
    cout << "- Numero maximo de hijos: " << sysconf(_SC_CHILD_MAX) << endl;
    cout << "- Numero maximo de ficheros abiertos: " << sysconf(_SC_OPEN_MAX) << endl;
   

    return 1;
}