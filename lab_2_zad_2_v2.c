/*

	© Dorian Szczygielski / Zachodniopomorski Uniwersytet Technologiczny w Szczecinie / Wydział Elektryczny
	Systemy operacyjne i architektura systemów komputerowych
	lab_2 / zadanie_2

*/

#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void catch_SIGUSR1(int signal)
{
        printf("PARENT: I recived signal number %d!\n", signal);
        wait(0);
}

int main(void)
{
        signal(SIGUSR1, catch_SIGUSR1);

        if (!fork()) {
                printf("CHILD: I'm running...\n");
                sleep(2);
                printf("CHILD: I'm sending SIGUSR1...\n");
                kill(getppid(), SIGUSR1);
                sleep(5);
                printf("CHILD: I'm exitting...\n");
                return 0;
        }
	
	if (fork() < 0) {
	    perror("Error Fork");
	    exit(1);
	}
	
        printf("PARENT: I'm running, PID=%d. Press ENTER to exit.\n", getpid());
        getchar();
        printf("PARENT: I'm exitting...\n");
  return 0;
}
