#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int segundos = 0;

void manejar_alarma(int sig) {
    segundos += 5;
    printf("Han transcurrido %d segundos\n", segundos);
    alarm(5);
}

void main() {
    signal(SIGALRM, manejar_alarma);
    alarm(5);
    
    while(1) {
        pause();
    }
    
    exit(0);
}