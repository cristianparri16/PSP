#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid,mi_pid,pid_padre;

  pid=fork();
    if(pid==0){
        mi_pid=getpid();
        pid_padre=getppid();
        if(mi_pid%2==0){
            printf(" P2 mi pid es=%d y el de mi padres es= %d\n",mi_pid,pid_padre);

        }else{
            printf("P2 mi pid es=%d\n",mi_pid);
        }
        
    }else{
        pid= fork();
        if(pid==0){
            pid=fork();
            if(pid==0){
               mi_pid=getpid();
                pid_padre=getppid(); 
                if(mi_pid%2==0){
                    printf(" P4 mi pid es=%d y el de mi padres es= %d\n",mi_pid,pid_padre);

                }else{
                    printf("P4 mi pid es=%d\n",mi_pid);
                }
            }else{        
                wait(NULL);
                mi_pid=getpid();
                pid_padre=getppid();
                if(mi_pid%2==0){
                    printf(" P3 mi pid es=%d y el de mi padres es= %d\n",mi_pid,pid_padre);

                }else{
                printf("P3 mi pid es=%d\n",mi_pid);
                 }
            }
        }else{
            wait(NULL);
            wait(NULL);
            mi_pid=getpid();

            printf("P1 mi pid es=%d\n",mi_pid);
        }
    }     
    exit(0);
}

 
