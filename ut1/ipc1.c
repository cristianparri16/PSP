#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>

void main() {
pid_t pid;
int fd[2]; 
 pipe(fd);
char buffer[30];
pid = fork();

  if (pid == 0 )   
  {        
      
        close(fd[1]); 
        printf("El hijo lee el PIPE \n");
        read(fd[0], buffer, sizeof(buffer));
        printf("\t Mensaje leido del pipe: %s \n", buffer);
        close(fd[0]);
   
  }
  else     
  { 
    time_t hora;
    char *fecha ;
    time(&hora);
    fecha = ctime(&hora) ;
    close(fd[0]); 
    printf("El padre escribe en el PIPE...\n");
    write(fd[1],fecha,strlen(fecha)); 
    close(fd[1]); 
    wait(NULL);
  }
   exit(0);
}