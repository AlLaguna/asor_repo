#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <signal.h>
#include <string.h>
#include <string>
#include <unistd.h>
using namespace std;
int main(int argc, char *argv[])
{
	sigset_t mascara;

    if (sigaddset(&mascara, SIGINT) == -1)
	{
		perror("sigaddset()");
	}

	if (sigaddset(&mascara, SIGTSTP) == -1)
	{
		perror("sigaddset()");
	}

	if (sigemptyset(&mascara) == -1)
	{
		perror("sigemptyset()");
	}

	
	
	char * segs = getenv("SLEEP_SECS");
	
	sleep(atoi(segs));

	
	sigset_t pend;
	sigemptyset(&pend);
	if (sigpending(&mascara) == -1)
	{
		perror("sigpending()");
		exit(EXIT_FAILURE);
	}

	if (sigismember(&pend, SIGINT))
	{
		printf("Recibida la señal SIGINT.\n");
	}

	if (sigismember(&pend, SIGTSTP))
	{
		cout << "SIGTSTP" << endl;

		if (sigdelset(&mascara, SIGINT) == -1)
		{
			perror("sigdelset()");
			exit(EXIT_FAILURE);
		}

	}
	
	cout << "Desbloqueada" << endl;
	
	return 0;
}