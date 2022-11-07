#include <iostream>
#include <string>
#include <unistd.h>
#include <time.h>

using namespace std;


int main()
{
    char buff[255];
    time_t t;
    time(&t);
    tm *tiempo = localtime(&t);
    
    //"lunes, 29 de octubre de 2018, 10:34"
    strftime(buff, 255, "%A, %d de %B de %Y, %H:%M", tiempo);


    cout << buff << endl;

    return 1;
}