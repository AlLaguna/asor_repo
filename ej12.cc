#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile int sigtint_counter = 0;
volatile int sigtstp_counter = 0;
using namespace std;
static void handler(int signum)
{
	switch (signum)
	{
		case SIGINT:
			sigtint_counter++;
			break;
		case SIGTSTP:
			sigtstp_counter++;
			break;
	}
}

int main(int argc, char *argv[])
{
	struct sigaction s;

	sigemptyset(& s.sa_mask);
	s.sa_flags = SA_RESTART; 


	s.sa_handler = handler;

    sigaction(SIGINT, &s, NULL);
    sigaction(SIGTSTP, &s, NULL);
	
	sigset_t mask;
    sigfillset(&mask);
    sigdelset(&mask, SIGINT);
	sigdelset(&mask, SIGTSTP);

	while (sigtint_counter + sigtstp_counter < 10)
	{
		sigsuspend(&mask);
	}
    cout <<"sigtint_counter: " << sigtint_counter << endl;
    cout << "sigtstp_counter: " << sigtstp_counter << endl; 
	return 0;
}

