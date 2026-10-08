#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid1,pid2,pid3,pid4,pid5;
  int acumulado=getpid();
  

  pid2 = fork();

  if (pid2 == 0 )   {        
   	  pid5=fork();
      if(pid5==0){
        if(getpid()%2==0){
            acumulado+=10;
        }else{
            acumulado-=100;
        }
        printf("p4 pidpadre modificado %d\n",acumulado);

      }else{
        wait(NULL);
        if(getpid()%2==0){
            acumulado+=10;
        }else{
            acumulado-=100;
        }
        printf("p2 pidpadre modificado %d\n",acumulado);
       }
   
  }
  else     
  { 
    pid3=fork();
    if (pid3 == 0 )   {        
        pid5=fork();
        if(pid5==0){
             if(getpid()%2==0){
            acumulado+=10;
        }else{
            acumulado-=100;
        }
        printf("p5 pidpadre modificado %d\n",acumulado);
        }
      }else{
        wait(NULL);
        if(getpid()%2==0){
            acumulado+=10;
        }else{
            acumulado-=100;
        }
        printf("p3 pidpadre modificado %d\n",acumulado);
       }
    wait(NULL);
   
            
  }
   exit(0);
}

