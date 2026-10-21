#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>

void main() {
    int pipe1[2]; 
    int pipe2[2]; 
    pipe(pipe1);
    pipe(pipe2);


    time_t t;
    int numeroAleatorio;
    srand((unsigned) time(&t));
    pid_t pid = fork();

    if (pid == 0) {
    
        close(pipe1[1]); 
        close(pipe2[0]);

        int numero;
        read(pipe1[0], &numero, sizeof(numero));
        int factorial = 1;
        for (int i = 1; i <= numero; i++) {
            factorial = factorial * i;
        }
   
        write(pipe2[1], &factorial, sizeof(factorial));

        close(pipe1[0]);
        close(pipe2[1]);
    }
    else {
       
        close(pipe1[0]); 
        close(pipe2[1]); 

        numeroAleatorio = rand() % 11; 
        printf("el proceso padre genera el numero %d en el pipe1\n", numeroAleatorio);

        write(pipe1[1], &numeroAleatorio, sizeof(numeroAleatorio));

        int resultado;
        
        read(pipe2[0], &resultado, sizeof(resultado));
        printf("el factoorial calculado por el proceso hijo: %d != %d\n", numeroAleatorio, resultado);

        
        close(pipe1[1]);
        close(pipe2[0]);

        wait(NULL); 
    }

    exit(0);
}