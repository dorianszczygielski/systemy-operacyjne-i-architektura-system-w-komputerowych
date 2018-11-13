#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdbool.h>
#include <string.h>
#include <sys/shm.h>
 
int main()
{
    int input;
    bool me = false;
    char message[100];
    int semafor = semget(ftok(".", 'a'), 1, IPC_CREAT | 0666);
    struct sembuf lock = { 0, -1, 0 };
    struct sembuf unlock = { 0, 1, 0 };
   
    int shmid = shmget(ftok(".", 'A'), 1024, IPC_CREAT | 0666);
    char* shmpointer = shmat(shmid, NULL, 0);
   
    semctl(semafor, 0, SETVAL, 1);
 
    while(true)
    {
        printf("\n\nInput: ");
        scanf("%d", &input);
       
        if(input == 1)
        {
            semop(semafor, &lock, 1);
            printf("\nSemaphore Locked\n\n");
            printf("\nEnter Message: ");
           
            if(fgets(message, 100, stdin) != NULL)
            {
                fgets(message, 100, stdin);
            }
           
            strcpy(shmpointer, message);
            semop(semafor, &unlock, 1);
            me = true;
        }
        /*
        if(input == 2 && me == true)
        {
            semop(semafor, &unlock, 1);
            printf("\nSemaphore Unlocked\n\n");
            me = false;
        }
        */
    }
   
    shmdt(&shmpointer);
   
    semctl(semafor, 0, IPC_RMID);
   
    return 0;
}
