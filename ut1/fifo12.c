#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

void main(){

    const char *fifo1 = "FIFO1";
    const char *fifo2 = "FIFO2";

    int fd1 = open(fifo1, O_RDONLY);
    int numero;
    if (read(fd1, &numero, sizeof(numero)) > 0) {
        printf(" Proceso fifo12 numero recibido de FIFO1: %d\n", numero);
    } else {
        printf("Proceso fifo12 error al leer de FIFO1\n");
        close(fd1);
        exit(EXIT_FAILURE);
    }

    int fact = 1;
    for (int i = 1; i <= numero; i++) {
        fact *= i;
    }

    int fd2 = open(fifo2, O_WRONLY);

    if (write(fd2, &fact, sizeof(fact)) == -1) {
        printf("Proceso fifo12 error al escribir en FIFO2\n");
    } else {
        printf("Proceso fifo12 factorial calculado %d enviado por FIFO2.\n", fact);
    }

    close(fd1);
    close(fd2);

exit(0);

}