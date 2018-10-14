#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct mesg_buffer {
    long msgtype;
    int number;
} msgbuffer_t;


int main() {
  key_t key;
  int msgid;
	
  msgbuffer_t sendbuf = { 0 };
  sendbuf.msgtype = 1;
  printf("Your number: ");
  fgets(msgbuffer_t.number, 100, stdin);
  sendbuf.number = &number;

  msgbuffer_t recvbuf = { 0 };
  msgbuffer_t recvbuf2 = { 0 };
  msgid = msgget(key, 0666 | IPC_CREAT);

  msgsnd(msgid, &sendbuf, (sizeof(msgbuffer_t) - sizeof(long)), 1);
  msgsnd(msgid, &sendbuf, (sizeof(msgbuffer_t) - sizeof(long)), 1);

  msgrcv(msgid, &recvbuf, (sizeof(msgbuffer_t) - sizeof(long)), 1, 0);
  msgrcv(msgid, &recvbuf2, (sizeof(msgbuffer_t) - sizeof(long)), 1, 0);

  printf("SLAVE1 RESULT (a+1): %d\n", recvbuf.number);
  printf("SLAVE2 RESULT (a*2): %d\n", recvbuf2.number);

  return 0;
}

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <string.h>
// structure for message queue

int main()
{
    key_t key;
    int msgid;

    // ftok to generate unique key
    key = ftok("uniquename", 65);

    // msgget creates a message queue
    // and returns identifier
    msgid = msgget(key, 0666 | IPC_CREAT);
    message.mesg_type = 1;

    printf("Your message: ");
    fgets(message.mesg_text, 100, stdin);

    // msgsnd to send message
    msgsnd(msgid, &message, sizeof(message), 0);

    // display the message
    printf("Data send is: %s", message.mesg_text);
    printf("Oczekiwanie na sygnal ACK...\n\n");

    char recvmsg[100] = { 0 };

    while(strcmp(recvmsg, "ACK") !=0) {

        msgrcv(msgid, &message, sizeof(message), 1, 0);
        sprintf(recvmsg, "%s", message.mesg_text);

    }
    printf("Odebrano potwierdzenie (ACK)\n\n");

    return 0;
}
