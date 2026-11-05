#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

void main(){

const char *pipe="PIPE2";

 mkfifo(pipe, 0666);

   time_t t;
    int numero;
    srand((unsigned) time(&t));
    numero=rand() % 10;

    int fd = open(pipe, O_RDWR);

     if (write(fd, &numero, sizeof(numero)) == -1) {
        printf("Proceso fifo21 error al escribir en PIPE2\n");
    } else {
        printf("Proceso fifo21 numero %d enviado por PIPE2.\n", numero);
    }

    int factorial;
    if (read(fd, &factorial, sizeof(factorial)) > 0) {
        printf("Proceso fifo21 el factorial es: %d\n", factorial);
    } else {
        printf("Proceso fifo21 error al leer de PIPE02\n");
    }

    close(fd);

    exit(0);
}