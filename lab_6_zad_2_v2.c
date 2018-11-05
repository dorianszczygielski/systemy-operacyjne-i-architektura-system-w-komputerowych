#include <stdio.h>      // Input/Output
#include <unistd.h>     // Time management (usleep)
#include <pthread.h>    // Threads management
#include <sys/sem.h>    // Semaphores management

#define PERMS 0660  // -rw permissions for group and user

int semId;

int initSem(int semId, int semNum, int initValue) {
    return semctl(semId, semNum, SETVAL, initValue);
}

/* An operation list is structured like this : 
*   { semphore index, operation, flags }
* The operation is an integer value interpreted like this :
*   >= 0 : Rise the semaphore value by this value. 
*       This trigger the awakening of semaphores waiting for a rise.
*   == 0 : Wait for the semaphore to be at value 0.
*    < 0 : Substract abs(value) to the semaphore. 
*       If then the semaphore is negative, wait for a rise.
*/

// Try to take a resource, wait if not available
int P(int semId, int semNum) {
    // Operation list of 1 operation, taking resource, no flag
    struct sembuf operationList[1];
    operationList[0].sem_num = semNum;
    operationList[0].sem_op = -1;
    operationList[0].sem_flg = 0;
    return semop(semId, operationList, 1);
}

// Release a resource
int V(int semId, int semNum) {
    // Operation list of 1 operation, releasing resource, no flag
    struct sembuf operationList[1];
    operationList[0].sem_num = semNum;
    operationList[0].sem_op = 1;
    operationList[0].sem_flg = 0;
    
    return semop(semId, operationList, 1);
}

void* funcA(void* nothing) {
    printf("Thread A try to lock 0...\n");
    P(semId, 0);        // Take resource/semaphore 0 of semID 
    printf("Thread A locked 0.\n");
    
    usleep(50*1000);  // Wait 50 ms
    
    printf("Thread A try to lock 1...\n");
    P(semId, 1);        // Take resource/semaphore 1 of semID 
    printf("Thread A locked 1.\n");

    V(semId, 0);        // Release resource/semaphore 0 of semID
    V(semId, 1);        // Release resource/semaphore 1 of semID
    return NULL;
}

void* funcB(void* nothing) {
    printf("Thread B try to lock 1...\n");
    P(semId, 1);        // Take resource/semaphore 0 of semID 
    printf("Thread B locked 1.\n");
    
    usleep(5*1000);  // Wait 50 ms
    
    printf("Thread B try to lock 0...\n");
    P(semId, 0);        // Take resource/semaphore 1 of semID 
    printf("Thread B locked 0.\n");

    V(semId, 0);        // Release resource/semaphore 0 of semID
    V(semId, 1);        // Release resource/semaphore 1 of semID
    return NULL;
}

// Main function
int main(int argc, char* argv[]) {
    int i;          // Iterator
    
    // We create a set of 2 semaphores    
    // ftok generates a key based on the program name and a char value
    // This avoid to pick an arbitrary key already existing
    semId = semget(ftok(argv[0], 'A'), 2, IPC_CREAT | PERMS);
    
    // Set the semaphore at index 0 to value 1 (= available for use)
    initSem(semId, 0, 1);
    // Set the semaphore at index 1 to value 1 (= available for use)
    initSem(semId, 1, 1);
    
    pthread_t thread[2];    // Array of threads
        
    pthread_create(&thread[0], NULL, funcA, NULL);
    pthread_create(&thread[1], NULL, funcB, NULL);

    // Wait until threads are all complete
    for (i = 0 ; i < 2 ; i++) {
        pthread_join(thread[i], NULL);
    }   
    printf("This is not printed in case of deadlock\n");
    // Free the semaphores
    semctl(semId, 0, IPC_RMID, 0);
    semctl(semId, 1, IPC_RMID, 0);
    return 0;
}
