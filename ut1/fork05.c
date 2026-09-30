#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid,pid_hijos,pid_padre;

  pid =fork();

  if (pid ==0){

        pid =fork();

        if(pid ==0){
           pid_padre= getppid();
           pid_hijos=getpid();

           printf("Soy el proceso 3 mi pid es=%d y el de mi padre es =%d \n",pid_hijos,pid_padre);
           exit(0);

        }else {
            wait(NULL);
            pid_hijos=getpid();
            pid_padre= getppid();
            printf("Soy el proceso 2 mi pid es =%d y el de mi padre es=%d \n",pid_hijos,pid_padre);
            exit(0);
        }

  }else {
    wait(NULL);
    pid_padre=getpid();
    printf("soy el proceso 1 mi pip es=%d y el de mi hijo es=%d",pid_padre,pid);

  }
  

  

   exit(0);
}

