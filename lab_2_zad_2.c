/*

	© Dorian Szczygielski / Zachodniopomorski Uniwersytet Technologiczny w Szczecinie / Wydział Elektryczny
	Systemy operacyjne i architektura systemów komputerowych
	lab_2 / zadanie_2

*/

#include <stdio.h>
#include <signal.h>
void catch_SIGINT(int signal_number);

int main (void) {

   signal(SIGINT, catch_SIGINT);

   printf("Wysylam sygnal...\n");
   raise(SIGINT);

   printf("Wychodze...\n");

   return(0);
}

void catch_SIGINT(int signal_number) {
   printf("Przechwycilem sygnal!\n");
}
