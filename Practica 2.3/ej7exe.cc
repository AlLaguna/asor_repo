#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;
int main(int argc, char *argv[])
{
	pid_t pid = fork();
	
    if(pid == 0)
    {
        execvp(argv[1], argv + 1);
        cout << "ejecutado execvp" << endl;
		
    }
    else
    {	
		waitpid(pid, NULL, 0);
		cout << "termino" << endl;
	}
	
	return 0;
}