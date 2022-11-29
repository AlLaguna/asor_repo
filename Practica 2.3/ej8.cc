#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <fcntl.h>

using namespace std;

int main(int argc, char *argv[])
{
	pid_t pid;
	pid = fork();

    if (pid == 0)
	{
		cout << "proceso hijo";

		int fd = open("/dev/null", O_RDONLY);
		dup2(fd, 0);

		int fd1 = open("/tmp/daemon.out", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(fd1, 1);

		int fd2 = open("/tmp/daemon.err", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(fd2, 2);

        execvp(argv[1], argv + 1);
	}
	else
	{
		waitpid(pid, NULL, 0);
		cout << "PAdre" << endl;
	}
	
	return 0;
}