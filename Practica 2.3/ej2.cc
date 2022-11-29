#include <stdio.h>
#include <iostream>

#include <unistd.h>
#include <sched.h>
#include <sys/types.h>

using namespace std;

int main()
{
    struct sched_param stSched;

    int r = sched_getscheduler(getpid());

    cout << "politica: " << r << endl;

    int r2 = sched_getparam(getpid(), &stSched);

    cout << "prioridad: " << stSched.sched_priority << endl;
    return 0;
}