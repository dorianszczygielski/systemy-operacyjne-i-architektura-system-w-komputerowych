/*

	Š Dorian Szczygielski / Zachodniopomorski Uniwersytet Technologiczny w Szczecinie / Wydział Elektryczny
	Systemy operacyjne i architektura systemów komputerowych
	lab_2 / zadanie_1

*/

#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

void catch_SIGUSR1(int signal_number)
{
  printf("Przechwycilem sygnal!\n" );
}

int main(void)
{
    signal(SIGUSR1, catch_SIGUSR1);
    while (true)
    {
        printf("Dzialam dalej...\n");
        sleep(10);
    }

    return 0;
}
