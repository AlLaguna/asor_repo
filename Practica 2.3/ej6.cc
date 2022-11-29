#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;
void atributos()
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
}
int main()
{
	pid_t pid;
	pid = fork();

	if (pid == 0)
	{
		cout << "proceso hijo: " << getpid() << ", " << getppid() << endl;

        chdir("/tmp");

		atributos();
	}
	else
	{
		cout << "proceso padre: " << getpid() << endl;

		atributos();
		
		// We wait for the child to finish before the father. If not, the child is assigned PPID 1.
		waitpid(pid, NULL, 0);
	}
	
	return 0;
}

