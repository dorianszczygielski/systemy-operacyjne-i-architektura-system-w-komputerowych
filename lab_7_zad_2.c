#include <stdio.h>
#include <stdbool.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/types.h>
 
int main()
{
key_t key = ftok(".", 'c');
int semid = semget(key, 3, IPC_CREAT | 0666);
struct sembuf lock[3] = { {0, -1, 0}, {1, -1, 0}, {2, -1, 0} };
struct sembuf unlock[3] = { {0, 1, 0}, {1, 1, 0}, (2, 1, 0) };
 
char input;
semctl(semid, 0, SETVAL, 1);
semctl(semid, 1, SETVAL, 1);
semctl(semid, 2, SETVAL, 1);
 
while(true)
{
scanf("%c", &input);
 
    if(input == 1) {
        semop(semid, lock, 1);
        printf("\nSemaphore Locked\n");
    }
     if(input == 2) {
        semop(semid, lock, 2);
		semop(semid, lock+1, 2);
        printf("\n2 Semaphores Locked\n");
    }
 
    if(input == 3) {
        semop(semid, lock, 3);
		semop(semid, lock+1, 3);
		semop(semid, lock+2, 3);
        printf("\n3 Semaphores Locked\n");
	}
 
    if(input == 'a') {
        semop(semid, unlock, 1);
        printf("\nSemaphore Unlocked\n");
    }
 
    case 's':
        semop(semid, unlock, 2);
		semop(semid, unlock+1, 2);
        printf("\n2 Semaphores Unlocked\n");
        break;
 
    case 'd':
        semop(semid, unlock, 3);
		semop(semid, unlock+1, 3);
		semop(semid, unlock+2, 3);
        printf("\n3 Semaphores Unlocked\n");
    }
}
 
}
 
semctl(semid, 0, IPC_RMID);
semctl(semid, 1, IPC_RMID);
semctl(semid, 2, IPC_RMID);
 
return 0;
}
