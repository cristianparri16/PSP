#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid,mi_pid;
  int suma=0;

  
  pid = fork();

  if(pid ==0){
    for(int i =1;i<=100;i++){
        suma+=i;
    }
    mi_pid=getpid();
    printf("mi pid es=%d y la suma 1 al 100 su resultado es=%d\n",mi_pid,suma);
  }else {
    pid =fork();
    if(pid ==0){
        for (int i = 101; i <= 200; i++) {
            suma += i;
        }
        
        mi_pid=getpid();
        printf(" mi pid es=%d y la suma del 101 al 200 su resultado es=%d\n",mi_pid,suma);
    }else{
        wait(NULL);
        wait(NULL);
        printf("Todos los calculos han finalizado\n");
    }
  }

 
   exit(0);
}

