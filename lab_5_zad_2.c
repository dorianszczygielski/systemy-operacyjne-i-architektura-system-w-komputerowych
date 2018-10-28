#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#define KOM "Message to parent\n"
int main()
{
    int potok_fd[2], count;
    char bufor[BUFSIZ];
    pipe(potok_fd);
    write(potok_fd[1], KOM, strlen(KOM));
    fcntl(potok_fd[0], F_SETFL, O_NONBLOCK);
    while ((count = read(potok_fd[0], bufor, BUFSIZ)) > 0)
        write(1, bufor, count);
    return 0;
}
