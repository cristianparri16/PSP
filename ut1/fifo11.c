#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>


void main(){

const char *fifo1 = "FIFO1";
    const char *fifo2 = "FIFO2";
   

    mkfifo(fifo1, 0666);
    mkfifo(fifo2, 0666);

     time_t t;
    int numero;
    srand((unsigned) time(&t));
    numero=rand() % 10;

    int fd1 = open(fifo1, O_WRONLY);

    if (write(fd1, &numero, sizeof(numero)) == -1) {
        printf("Proceso fifo11 error al escribir en FIFO1\n");
    } else {
        printf("Proceso fifo11: Número %d enviado por FIFO1.\n", numero);
    }

    int fd2 = open(fifo2, O_RDONLY);

    int factorial;
    if (read(fd2, &factorial, sizeof(factorial)) > 0) {
        printf("Proceso fifo11 el factorial es: %d\n", factorial);
    } else {
        printf("Proceso fifo11 error al leer de FIFO2\n");
    }

    close(fd1);
    close(fd2);
    exit(0);
      




    
    



}



