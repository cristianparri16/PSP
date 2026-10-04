#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

   printf("P1 empezando\n");
    pid = fork();
    if (pid == 0) {
        printf("P2 empezando\n");
        sleep(5);
        printf("P2 terminando\n");
        
    } else {
        
        pid = fork();
        if (pid == 0) {
            printf("P3 empezando\n");
            sleep(2);
            printf("P3 terminando\n");
            
        } else {
            
            pid = fork();
            if (pid == 0) {
                printf("P4 empezando\n");
                sleep(4);
                printf("P4 terminando\n");          
                
            } else {
                wait(NULL);
                wait(NULL);
                wait(NULL);
                printf("P1 terminando");
            }
        }
    } 
    exit(0);
}

//a) Sí. El orden será P3 (2s), luego P4 (4s) y por último P2 (5s).

//b) aleatorio sin el sleep(), el sistema operativo decidira el orden  y cambiara en cada ejecución.
