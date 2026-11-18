#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int segundos = 0;

void alarma(int sig) {
    segundos += 5;
    printf("Han transcurrido %d segundos\n", segundos);
    alarm(5);
}

void main() {
    signal(SIGALRM, alarma);
    alarm(5);
    
    while(1) {
        pause();
    }
    
    exit(0);
}
