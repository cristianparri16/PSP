#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid, mi_pid, pid_padre;
    int suma;

    
    pid = fork();

    if (pid == 0) {        
        
        pid = fork();
        
        if (pid == 0) {
           
            pid = fork();
            
            if (pid == 0) {
                
                mi_pid = getpid();
                pid_padre = getppid();
                suma = mi_pid + pid_padre;
                printf("Soy el p4 mi pid es %d y el de mi padre es %d y la suma es = %d\n", mi_pid, pid_padre, suma);
            } else {
                
                wait(NULL); 
                mi_pid = getpid();
                pid_padre = getppid();
                suma = mi_pid + pid_padre;
                printf("Soy el p3 mipid es %dy el de mi padre es %d y la suma es = %d\n", mi_pid, pid_padre, suma);
            }
        } else {
            
            wait(NULL); 
            
            mi_pid = getpid();
            pid_padre = getppid();
            suma = mi_pid + pid_padre;
            printf("Soy el p2 mi pid es %dy el de mi padre es %d y la suma es = %d\n", mi_pid, pid_padre, suma);
        }
    } else { 
       
        wait(NULL); 
        mi_pid = getpid();
        pid_padre = getppid();
        suma = mi_pid + pid_padre;
        printf("Soy el p1 mi pid es %d y el de mi padre es %d y la suma es = %d\n", mi_pid, pid_padre, suma);          
    }

    exit(0);
}