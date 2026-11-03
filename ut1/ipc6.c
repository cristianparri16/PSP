#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
    int pipe1[2]; 
    int pipe2[2];
    int pipe3[2];
    int pipe4[2]; 
    
    pipe(pipe1);
    pipe(pipe2);
    pipe(pipe3);
    pipe(pipe4);
    
    int numero1 = 0;
    int numero2 = 0;
    int multiplicacion = 0;
    int suma = 0;

    pid_t pid = fork();

    if (pid == 0) {
        
        close(pipe1[1]);
        close(pipe3[0]);

        read(pipe1[0], &numero1, sizeof(numero1));
        read(pipe1[0], &numero2, sizeof(numero2));
        
        suma = numero1 + numero2;
        write(pipe3[1], &suma, sizeof(suma));
        close(pipe1[0]);
        close(pipe3[1]);
        
    } else {

        pid_t pid2 = fork();

        if (pid2 == 0) {
            
            close(pipe2[1]);
            close(pipe4[0]);
          
            read(pipe2[0], &numero1, sizeof(numero1));
            read(pipe2[0], &numero2, sizeof(numero2));
            
            multiplicacion = numero1 * numero2;
            write(pipe4[1], &multiplicacion, sizeof(multiplicacion));

            close(pipe2[0]);
            close(pipe4[1]);
            
        } else {
            
            close(pipe1[0]);
            close(pipe2[0]);
            close(pipe3[1]);
            close(pipe4[1]);

            printf("dame un numero\n");
            scanf("%d", &numero1);
            printf("dame otro numero\n");
            scanf("%d", &numero2);

            write(pipe1[1], &numero1, sizeof(numero1));
            write(pipe1[1], &numero2, sizeof(numero2));
            close(pipe1[1]);

            write(pipe2[1], &numero1, sizeof(numero1));
            write(pipe2[1], &numero2, sizeof(numero2));
            close(pipe2[1]);

            read(pipe4[0], &multiplicacion, sizeof(multiplicacion));
            read(pipe3[0], &suma, sizeof(suma));

            close(pipe4[0]);
            close(pipe3[0]);

            wait(NULL);
            wait(NULL);

            printf("la suma de los numeros es %d \n", suma);
            printf("la multiplicacion de los numero es %d\n", multiplicacion);
        }
    }

    exit(0);
}