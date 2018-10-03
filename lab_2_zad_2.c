/*

	© Dorian Szczygielski / Zachodniopomorski Uniwersytet Technologiczny w Szczecinie / Wydział Elektryczny
	Systemy operacyjne i architektura systemów komputerowych
	lab_2 / zadanie_2

*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

void catch_SIGUSR1(int signal)
{
        printf("Parent: Cought signal %d!\n",signal);
        wait(0);
}

int main(void)
{
        signal(SIGUSR1,catch_SIGUSR1);

        if (!fork()) {
                printf("Child running...\n");
                sleep(2);
                printf("Child sending SIGUSR1...\n");
                kill(getppid(),SIGUSR1);
                sleep(5);
                printf("Child exitting...\n");
                return 0;
        }
        printf("Parent running, PID=%d. Press ENTER to exit.\n",getpid());
        getchar();
        printf("Parent exitting...\n");
        return 0;
}
