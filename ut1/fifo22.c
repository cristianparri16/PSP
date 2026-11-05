#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    const char *pipe= "PIPE2";

    int fd = open(pipe, O_RDWR);

    int numero;
    if (read(fd, &numero, sizeof(numero)) > 0) {
        printf("Proceso fifo22 Número recibido de PIPE2: %d\n", numero);
    } else {
        printf("Proceso fifo22 error al leer de PIPE2\n");
        close(fd);
        exit(EXIT_FAILURE);
    }


    int fact = 1;
    for (int i = 1; i <= numero; i++) {
        fact *= i;
    }

    if (write(fd, &fact, sizeof(fact)) == -1) {
        printf("Proceso fifo22 error al escribir en PIPE2\n");
    } else {
        printf("Proceso fifo22 factorial calculado %d enviado por PIPE2.\n", fact);
    }

    close(fd);

    exit(0);

}