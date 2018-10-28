#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <memory.h>
#include <stdlib.h>
 
int main()
{
    printf("Podaj PID MASTERA:  \n");
    char pid[4];
    scanf("%s", pid);
    char *sciezka;
    sciezka =  "/proc/";
    char *sciezka2;
    sciezka2 = "/fd/3";
   
    char * str3 = (char *) malloc(1 + strlen(sciezka)+ strlen(sciezka2) + strlen(pid));
    char tekst[120];
    strcat(str3, sciezka);
    strcat(str3, pid);
    strcat(str3, sciezka2);
    printf("%s\n", str3);
    int fd = open(str3, O_RDONLY);
    read(fd, tekst, 100);
    printf("%s\n", tekst);
    close(fd);
 
 
 
    return 0;
}
