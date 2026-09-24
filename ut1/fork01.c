#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid, pid_hijo, pid_padre;
  
  

  pid = fork();

  if (pid == 0 ) 
  {   
    pid_hijo=getpid();
    pid_padre=getppid();    
    printf("Soy el proceso hijo \n mi pip es =%d \n el pid de mi padre es=%d \n",pid_hijo,pid_padre);	  
    
 
  }
  else    
  { 
  pid_hijo = wait(NULL); 
   
  pid_padre=getppid(); 
   printf("Soy el proceso padre \n  mi pip es=%d \n mi hijo tenia el pid=%d\n proceso hijo ha terminado",pid_hijo,pid_padre);          
  }
   exit(0);
}

