#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/time.h>

using namespace std;


int main()
{
    timeval inicio;
    gettimeofday(&inicio, NULL);
    
    for(int i = 0; i < 1000000;i++);

    timeval fin;
    gettimeofday(&fin, NULL);

    cout << fin.tv_usec - inicio.tv_usec << endl; 

    return 1;
}