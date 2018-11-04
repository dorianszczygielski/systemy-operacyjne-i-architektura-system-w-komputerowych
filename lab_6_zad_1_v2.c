#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <semaphore.h>

int main()
{
	int wait = 1;
	sem_t *mysemp;
	int oflag = O_CREAT, sts;
	mode_t mode = 0644;
	const char semname[] = "mysem";
	unsigned int value = 1;

	mysemp = sem_open(semname, oflag, mode, value);
	int control;
	
	while(wait) {
		scanf("%d", &control);
		
		if (control == 1) {
			sts = sem_trywait(mysemp);
			if (sts == 0) {
				printf("Przejęto semafor.\n");
			}

			else if (errno == EAGAIN) {
				while (sts != 0) {
					sts = sem_trywait(mysemp);
					if (sts == 0)
						printf("Przejęto semafor.\n");
				}
			}

			else perror("Niepowodzenie.\n");
		}

		if (control == 2) {
			sts = sem_post(mysemp);
			if (sts == 0)
				printf("Odblokowano semafor.\n");
			else perror("Niepowodzenie.\n");
		}

		if (control == 3) {
			sem_close(mysemp);
			sem_unlink("mysem");
			wait = 0;
		}
	}

return 0;

}
