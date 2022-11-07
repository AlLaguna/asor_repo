#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;


int main()
{
    //el UID real y efectivo del usuario
    cout << "UID real: " << getuid() << endl;
    cout << "UID efectivo: " << geteuid() << endl;
    cout << "Nombre usuario: " << getenv("USER") << endl;
    cout << "Home: " << getenv("HOME") << endl;
    
    //Comprobar bit setuid
    //Comprobacion con un uid arbitrario (no 0 dado que suele pertenecer a root)
    int error = setuid(154);
    if(error == -1)
    {
        cout << "Bit setuid NO activado" << endl;
    }
    else
    {
        cout << "Bit setuid activado" << endl;
    }

    return 1;
}