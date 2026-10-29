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


  
    pid_t pid = fork();

    if (pid == 0) {
        int entrada;
        char letra;
        close(pipe1[0]); 
        close(pipe2[1]);
        printf("dame los numeros de tu DNI\n");
        scanf("%d",&entrada) ;
           write(pipe1[1], &entrada, sizeof(entrada));
            read(pipe2[0],&letra,sizeof(letra));
            printf("la letra es %c\n",letra);
        
        close(pipe1[1]);
        close(pipe2[0]);
    }
    else {
       
        close(pipe1[1]); 
        close(pipe2[0]); 
        int dni;
        read(pipe1[0], &dni, sizeof(dni));
        char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";
            
        dni %= 23;
        write(pipe2[1], &letra[dni], sizeof(letra[dni]));
              
        close(pipe1[0]);
        close(pipe2[1]);

        wait(NULL); 
    }

    exit(0);
}