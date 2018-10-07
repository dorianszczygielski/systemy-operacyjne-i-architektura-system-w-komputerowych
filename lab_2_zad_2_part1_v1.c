
/*
	© Dorian Szczygielski / Zachodniopomorski Uniwersytet Technologiczny w Szczecinie / Wydział Elektryczny
	Systemy operacyjne i architektura systemów komputerowych
	lab_2 / zadanie_2
*/

#include <stdio.h>
#include <signal.h>
#include <stdbool.h>

void signalInfo() {
	puts("Signal is sended!");
}

int main(void) {

	int pid;
	printf("Signal PID: ");
	scanf("%d", &pid);
	
	kill(pid, SIGUSR1);
	signalInfo();
	while(true){}

return 0;
}
