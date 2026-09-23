#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid, pid_hijo,pid_padre;
  
  

  pid = fork();

  if (pid == 0 )   
  {        
    printf("Cristian \n");	  
   
  }
  else     
  { 
   pid_hijo = wait(NULL); 
   pid_padre=getpid();
   printf("Soy el proceso padre\n mi pid es =%d \n pid de mi hijo=%d",pid_padre,pid_hijo);          
  }
   exit(0);
}

