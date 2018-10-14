#include "common.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>

int main(int argc, char** argv) {
  msgbuffer_t buf;
  int qid = msgget(OPEN_QUEUE, MSGFLAGS);
  msgrcv(qid, &buf, MSGBUF_SZ, 1, MSGFLAGS);
  printf("%d\n", buf.number);

  msgbuffer_t sendbuf = { 0 };
  sendbuf.msgtype = 1;
  sendbuf.number = buf.number * 2;

  usleep(100);
  msgsnd(qid, &sendbuf, MSGBUF_SZ, 1);
  return 0;
}
