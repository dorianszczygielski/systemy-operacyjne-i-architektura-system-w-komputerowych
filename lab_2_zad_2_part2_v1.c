
/*
	© Dorian Szczygielski / Zachodniopomorski Uniwersytet Technologiczny w Szczecinie / Wydział Elektryczny
	Systemy operacyjne i architektura systemów komputerowych
	lab_2 / zadanie_2
*/

include <stdio.h>
#include <signal.h>
#include <stdbool.h>
#include <unistd.h>

void signalInfo(int signal_number) {
	puts("I catch SIGUSR1.");
}

int main(void) {

	printf("My PID is: %d\n", getpid());
	signal(SIGUSR1, signalInfo);
	while(true){;}

return 0;
}
