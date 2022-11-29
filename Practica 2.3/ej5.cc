#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sched.h>
#include <sys/resource.h>
#include <iostream>

using namespace std;

int main (int argc, char *argv[])
{
	int max;
	pid_t pid;
    pid_t ppid;
    pid_t pgid; 
    pid_t sid;

	pid = getpid();
	ppid = getppid();
	pgid = getpgid(pid);
	sid = getsid(pid);
		
	// Get maximun amount of files that can be opened by the process
	struct rlimit rl;
    getrlimit(RLIMIT_NOFILE, &rl);

	max = rl.rlim_cur;
	
    cout << "pid: " << pid << endl;
    cout << "ppid: " << ppid << endl;
    cout << "pgid: " << pgid << endl;
    cout << "sid: " << sid << endl;
    cout << "Maximo: " << max << endl;
	
	return 0;
}
