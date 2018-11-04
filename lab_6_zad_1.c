#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main()
{
    int input;
	int semafor = semget(ftok(".", 'a'), 1, IPC_CREAT | 0666);
    struct sembuf lock = { 0, -1, 0 };
    struct sembuf unlock = { 0, 1, 0 };
    
    semctl(semafor, 0, SETVAL, 1);
    
    while(1)
    {
        scanf("%d", &input);
        
        if(input == 1)
        {
            semop(semafor, &lock, 1);
                printf("\nSemaphore Locked\n\n");
        }
        if(input == 2)
        {
            semop(semafor, &unlock, 1);
                printf("\nSemaphore Unlocked\n\n");
        }
    }
    
    semctl(semafor, 0, IPC_RMID);
    
    return 0;
}
