#include <iostream>
#include <string>
#include <unistd.h>
#include <time.h>

using namespace std;


int main()
{
    cout << time(NULL) << endl;
    return 1;
}