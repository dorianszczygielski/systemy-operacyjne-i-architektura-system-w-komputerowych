#include <unistd.h>
#include <stdio.h>
#include <string.h>
 
int main()
{
    int fd[2];
    pipe( fd );
    char tekst[120];
    while(1)
    {
        scanf("%s", tekst);
        write (fd[1], tekst, strlen ( tekst + 1 ));
        close(fd[1]);
    }
 
 
    return 0;
}
