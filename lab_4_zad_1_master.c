include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "FSM_actions.c"

struct mesg_buffer {
        long mesg_type;
        char mesg_text[255];
} message;

int main(void) {

        key_t key;
        int msgid;
        int result;

        printf("Your message: ");
        fgets(message.mesg_text, 255, stdin);
        result = parse(message.mesg_text);      

        if(result == 1 || result == 2) {
                key = ftok("uniquename", 66);
                msgid = msgget(key, 0666 | IPC_CREAT);
                message.mesg_type = 1;
                msgsnd(msgid, &message, sizeof(message), 0);
                if(result == 1) {
                printf("I sent name: %s\n", message.mesg_text);
                }
                if(result == 2) {
                printf("I sent surname: %s\n", message.mesg_text);
        }
        if(result == 0) {
                printf("I can't send message. Date is bad\n");
        }
return 0;
}
        
