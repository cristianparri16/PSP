#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>

void sonarAlarma(int sig) {
    time_t hora;
    time(&hora);
    printf("Señal de alarma recibida a las: %s", ctime(&hora));
}

void main() {
    int veces, segundos;

    printf("cuantas veces sonara la alarma?:\n");
    scanf("%d", &veces);
    printf("aada cuantos segundos se repetira la alarma?:\n");
    scanf("%d", &segundos);

    signal(SIGALRM, sonarAlarma);
    printf("alarma activada\n");

    for (int i = 0; i < veces; i++) {
        alarm(segundos);
        pause();
    }
    printf("alarma desactivada\n");
    exit(0);
}