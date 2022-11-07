#include <iostream>
#include <string>
#include <unistd.h>
#include <time.h>

using namespace std;


int main()
{
    time_t t;
    time(&t);
    tm *tiempo = localtime(&t);
    cout << tiempo->tm_year + 1900 << endl;

    return 1;
}