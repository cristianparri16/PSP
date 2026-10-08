#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1,pid2, pid3, pid4, pid5, pid6;
    pid_t mi_abuelo; 
    
    pid2 = fork(); 
    
    if (pid2 == 0) {
        
        pid1 = getppid(); 
        
        pid3 = fork(); 
        
        if (pid3 == 0) {
            mi_abuelo = pid1; 
            pid_t pid_2 = getppid(); 
            
            pid5 = fork(); 
            if (pid5 == 0) {
                
                mi_abuelo = pid_2; 
                printf("Soy p5 Mi PID es %d y el PID de mi abuelo (P2) es %d\n", getpid(), mi_abuelo);
                exit(0);
            } else {
           
                wait(NULL); 
                printf("Soy p3 Mi PID es %d y el PID de mi abuelo (P1) es %d\n", getpid(), mi_abuelo);
                exit(0);
            }
            
        } else {
    
            pid4 = fork(); 
            
            if (pid4 == 0) {

              mi_abuelo = pid1; 
               pid_t pid_2 = getppid(); 
                
                pid6 = fork(); 
                if (pid6 == 0) {
                    
                    mi_abuelo = pid_2; 
                    printf("Soy Pp6 Mi PID es %d y el PID de mi abuelo (P2) es %d\n", getpid(), mi_abuelo);
                    exit(0);
                } else {
                    
                    wait(NULL); 
                    printf("Soy p4 Mi PID es %d y el PID de mi abuelo (P1) es %d\n", getpid(), mi_abuelo);
                    exit(0);
                }
                
            } else {
                wait(NULL);
                wait(NULL); 
                printf("Soy p2 Mi PID es %d\n", getpid());
                exit(0);
            }
        }
    } else {
        
        wait(NULL); 
        printf("Soy p1 Mi PID es %d\n", getpid());
    }

    exit(0);
}