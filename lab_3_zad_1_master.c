#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// structure for message queue
struct mesg_buffer {
    long mesg_type;
    char mesg_text[255];
} message;

int main()
{
    key_t key;
    int msgid;

    //convert a pathname and a project identifier to a System V IPC
    // ftok to generate unique key
    key = ftok("uniquename", 66);

    // msgget creates a message queue
    // and returns identifier
    msgid = msgget(key, 0666 | IPC_CREAT);
    message.mesg_type = 1;

    printf("Your message: ");
    fgets(message.mesg_text, 255, stdin);

    // msgsnd to send message
    msgsnd(msgid, &message, sizeof(message), 0);

    // display the message
    printf("I sent a message: %s", message.mesg_text);

    return 0;
}
