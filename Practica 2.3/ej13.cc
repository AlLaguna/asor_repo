#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <iostream>
using namespace std;
volatile int stop = 0;

static void handler(int signo);

int main(int argc, char *argv[])
{	
	
	sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGUSR1);
    sigprocmask(SIG_UNBLOCK, &mask, NULL);
	

	struct sigaction s;
	s.sa_handler = handler;
    sigaction(SIGUSR1, &s, NULL);
	
    
	int i = 0;
	int time = atoi(argv[1]);

	while (i < time && !stop)
	{
		sleep(1);
		i++;
	}

	// Check and delete the executable
	if (stop)
	{
		cout << "STOP" << endl;
	}
	else
	{
		cout << "Borrando..";
		unlink(argv[0]);
    
	}

	return 0;
}

static void handler(int signal)
{
	if (signal == SIGUSR1)
		stop = 1;
}