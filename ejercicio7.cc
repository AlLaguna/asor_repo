#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;


int main()
{
    // . hace referencia al directorio actual donde se ejecute
    cout << "Informacion configuracion del sistema de ficheros: " << endl;
    cout << "- Numero maximo de enlaces: " << pathconf(".",_PC_LINK_MAX) << endl;
    cout << "- Tamaño maximo de una ruta " << pathconf(".",_PC_PATH_MAX) << endl;
    cout << "- Tamaño maximo nombre de un fichero: " << pathconf(".",_PC_NAME_MAX) << endl;
   

    return 1;
}