#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <string.h>
// structure for message queue
struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
} message;

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
