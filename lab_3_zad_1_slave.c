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
    //CHMOD
    msgid = msgget(key, 0666 | IPC_CREAT);

    // msgrcv to receive message
    //1 = msgtyp
    //0 = msgflg
    msgrcv(msgid, &message, sizeof(message), 1, 0);

    // display the message
    printf("I received the message: %s \n", message.mesg_text);

    // to destroy the message queue
    // IPC_RMID - Mark the segment to be destroyed
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
