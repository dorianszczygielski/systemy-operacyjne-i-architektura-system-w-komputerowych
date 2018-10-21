#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

struct mesg_buffer {
        long mesg_type;
        char mesg_text[255];
} message;

int main(void) {

        key_t key;
        int msgid;

        key = ftok("uniquename", 60);
        msgid = msgget(key, 0666 | IPC_CREAT);
        msgrcv(msgid, &message, sizeof(message), 1, 0);
        if(message.mesg_text[1] == 'N') {
        printf("Received name is %s \n", message.mesg_text);
        }
        if(message.mesg_text[1] == 'S') {
        printf("Received surname is %s \n", message.mesg_text);
        }
        msgctl(msgid, IPC_RMID, NULL);

return 0;
}
