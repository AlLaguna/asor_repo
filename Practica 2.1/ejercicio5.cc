#include <sys/utsname.h>
#include <iostream>
#include <string>
using namespace std;


int main()
{
    utsname msg;
    uname(&msg);

    cout << (string)msg.sysname << endl;
    cout << (string)msg.nodename << endl;
    cout << (string)msg.release << endl;
    cout << (string)msg.version << endl;
    cout << (string)msg.machine << endl;
    cout << (string)msg.domainname << endl;

    return 1;
}