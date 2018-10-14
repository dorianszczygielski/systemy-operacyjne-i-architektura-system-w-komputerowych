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
