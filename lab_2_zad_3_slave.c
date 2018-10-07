#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int waiting = 1;
int master_pid = 0;

void signal_handler(int signal) {
  printf("Got signal, exiting.\n");

  kill(master_pid, SIGUSR1);
  waiting = 0;
}

int main(int argc, char** argv) {
  printf("%d\n", getpid());
  signal(SIGUSR1, signal_handler);

  if(argc != 2) {
    printf("Provide master process PID.\n");
    return -1;
  }

  master_pid = atoi(argv[1]);
  printf("Waiting for signal...\n");

  while(waiting) sleep(1);

  return 0;
}

