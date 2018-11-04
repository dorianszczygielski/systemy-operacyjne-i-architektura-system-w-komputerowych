#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdbool.h>

int main()
{
    int input;
    bool me;
	int semafor = semget(ftok(".", 'a'), 2, IPC_CREAT | 0666);
    struct sembuf lock[2] = { {0, -1, 0}, {1, -1, 0} };
    struct sembuf unlock[2] = { {0, 1, 0}, {1, 1, 0} };
    
    semctl(semafor, 0, SETVAL, 1);
    semctl(semafor, 1, SETVAL, 1);
    
    while(true)
    {
        scanf("%d", &input);
        
        if(input == 1)
		{
			if(semctl(semafor, 0, GETVAL) == 1)
			{
				semop(semafor, &lock[0], 1);
				printf("\nSemaphore Locked (%d)\n\n", lock[0].sem_num + 1);
				me = true;
			}
			else if(semctl(semafor, 1, GETVAL) == 1)
			{
				semop(semafor, &lock[1], 1);
				printf("\nSemaphore Locked (%d)\n\n", lock[1].sem_num + 1);
				me = true;
			}
		}
		if(input == 2)
		{
			if(semctl(semafor, 0, GETVAL) == 0 && me == true)
			{
				semop(semafor, &unlock[0], 1);
				printf("\nSemaphore Unlocked (%d)\n\n", unlock[0].sem_num + 1);
				me = false;
			}
			else if(semctl(semafor, 1, GETVAL) == 0 && me == true)
			{
				semop(semafor, &unlock[1], 1);
				printf("\nSemaphore Unlocked (%d)\n\n", unlock[1].sem_num + 1);
				me = false;
			}
		}
    }
    
    semctl(semafor, (0 | 1), IPC_RMID);
    
    return 0;
}
