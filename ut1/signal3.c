#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>

void escribirArchivo(int sig) {
    time_t hora;
    time(&hora);

    FILE *archivo = fopen("salidas.txt", "a");
    fprintf(archivo, "Señal recibida a las: %s", ctime(&hora));
    fclose(archivo);
}

void main() {
    signal(SIGINT, escribirArchivo);

    while(1) {
        sleep(1);
    }

  exit(0);
}