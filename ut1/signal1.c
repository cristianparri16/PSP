#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>


void fin(int sig) {
    time_t hora;
    time(&hora);
    printf("Fin del proceso %d: %s\n", getpid(), ctime(&hora));
    exit(0);
}

void main() {
    time_t hora;
    signal(SIGINT, fin);
    time(&hora);
    printf("Inicio del proceso %d: %s\n", getpid(), ctime(&hora));
    sleep(20);
    exit(0);
}