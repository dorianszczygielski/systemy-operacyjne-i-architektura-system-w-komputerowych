/*

	© Dorian Szczygielski / Zachodniopomorski Uniwersytet Technologiczny w Szczecinie / Wydzia³ Elektryczny
	Systemy operacyjne i architektura systemów komputerowych
	lab_2 / zadanie_1

*/

#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

void catch_SIGINT(int signal_number)
{
  printf( "Przechwycilem sygnal!\n" );
}

int main(void)
{
    signal(SIGINT, catch_SIGINT);
    while (1)
    {
        printf("Dzialam dalej...\n");
        sleep(10);
    }

    return 0;
}
