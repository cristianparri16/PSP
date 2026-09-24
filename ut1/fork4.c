#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid, pid_hijo1,pid_hijo2,pid_padre;
  
  pid = fork();

  if (pid == 0 )   
  { 
    pid_hijo1=getpid();
    pid_padre=getppid();       
    printf(" soy el proceso 2  mi pid=%d  el de mi padre es=%d\n",pid_hijo1,pid_padre);  
    pid_hijo1=sleep(3);

    exit(0);
  }
  else     
  { 
   pid = fork();
        if(pid==0){
            pid_hijo2=getpid();
            pid_padre=getppid();
            printf("soy el proceso 3 mi pid es = %d  el de mi padre es =%d \n",pid_hijo2,pid_padre);
            pid_hijo2=sleep(1);
            exit(0);
        }else{
            wait(NULL); 
            wait(NULL);
        }
   pid_padre=getpid();
   printf("Soy el proceso padre mi pid es =%d  pid de mi hijo1=%d  pid hijo2=%d",pid_padre,pid_hijo1,pid_hijo2);          
  }

  
  printf("todos mis hijos han finalizado");

   exit(0);
}