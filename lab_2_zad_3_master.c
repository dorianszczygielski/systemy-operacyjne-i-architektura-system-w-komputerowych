
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int waiting = 1;
int slave_pid = 0;

void signal_handler(int sig) {
  printf("I received response.\n");
  waiting = 0;
}

int main(int argc, char** argv) {
  printf("%d\n", getpid());

  signal(SIGUSR1, signal_handler);

  printf("slave_pid: ");
  scanf("%d", &slave_pid);

  kill(slave_pid, SIGUSR1);
  while(waiting) sleep(1);

  return 0;
}

