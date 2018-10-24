#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd;
    char message[255]
    char * myfifo = "/tmp/myfifo";

    fgets(message, 255, stdin);
    /* create the FIFO (named pipe) */
    mkfifo(myfifo, 0666);

    /* write text to the FIFO */
    fd = open(myfifo, O_WRONLY);

    write(fd, message, sizeof(message));
    close(fd);

    /* remove the FIFO */
    unlink(myfifo);

    return 0;
}
