#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
pid_t pid,pid_padre;

pid=fork();

if(pid==0){
    sleep(10);
    printf("despierto\n");
    

}else{
    pid=fork();
    if(pid==0){
        pid=getpid();
        pid_padre=getppid();
        printf("Soy el proceso 3 mi pid es =%d y el de mi padre=%d\n",pid,pid_padre);
        
    
    }else{
        wait(NULL);
        wait(NULL);
    }



}




exit(0);


}
