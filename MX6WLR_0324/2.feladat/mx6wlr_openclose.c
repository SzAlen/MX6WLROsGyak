#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <string.h>


int main()
{
    int fd, ret;
    char buf[32];

    buf[0]=0;

    //O_RDONLY- O_WRONLY --ezekbol valemyik kötelezo
    //O_APPEND - minden write utan a vegere pozicional
    //O_CREAT - létrehozás
    //O_TRUNC

    fd=open("mx6wlr.txt",O_RDWR);

    if(fd == -1){
        perror("open() hiba!");
        exit(-1);
    }



    ret = read(fd,buf,32); //ret:mennyit sikerült kiolvasni
    printf("read() ovalsott %d byetot, ami a kovetkezo %s\n",ret,buf);
    strcpy(buf,"MX6WLR;Szabo Alen;Programtervezo Info");

    ret=lseek(fd,0,SEEK_SET);
    printf("lseek() mondja: %d\n",ret);

    ret=write(fd,buf,25);
    printf("write() mondja %d\n",ret);



    close(fd);

    return 0;
}
