#include "common.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(int argc, char** argv) {
  msgbuffer_t sendbuf = { 0 };
  sendbuf.msgtype = 1;
  sendbuf.number = atoi(argv[1]);

  msgbuffer_t recvbuf = { 0 };
  msgbuffer_t recvbuf2 = { 0 };
  int qid = msgget(OPEN_QUEUE, MSGFLAGS);

  msgsnd(qid, &sendbuf, MSGBUF_SZ, 1);
  msgsnd(qid, &sendbuf, MSGBUF_SZ, 1);

  msgrcv(qid, &recvbuf, MSGBUF_SZ, 1, MSGFLAGS);
  msgrcv(qid, &recvbuf2, MSGBUF_SZ, 1, MSGFLAGS);

  printf("SLAVE1 RESULT (a+1): %d\n", recvbuf.number);
  printf("SLAVE2 RESULT (a*2): %d\n", recvbuf2.number);

  return 0;
}

struct myMessage {
long type;
int a;
} msgSnd, msgRcv1, msgRcv2;

int main() {

key_t key;
int msgid;
int pid;

printf("Write your number: ");
scanf("%d", &msgSnd.a);

printf("Slave first pid: ");
scanf("%d", &pid);


msgSnd.type = pid;

key = ftok("./", 20);
msgid = msgget(key, 0666 | IPC_CREAT);
msgsnd(msgid, &msgSnd, sizeof(msgSnd), 0);

printf("Slave second pid: ");
scanf("%d", &pid);
msgSnd.type = pid;
msgsnd(msgid, &msgSnd, sizeof(msgSnd), 0);

msgrcv(msgid, &msgRcv1, sizeof(msgRcv1), 1, 1);
printf("\n\n First number: %d\n\n", msgRcv1.a);

msgrcv(msgid, &msgRcv2, sizeof(msgRcv2), 2, 2);
printf("\n\n First number: %d\n\n", msgRcv2.a);

msgctl(msgid, IPC_RMID, NULL);

return 0;
}
