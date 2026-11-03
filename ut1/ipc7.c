#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void main(){    
    int pipe1[2]; 
    int pipe2[2];
    int pipe3[2];
    int pipe4[2]; 
    
    pipe(pipe1);
    pipe(pipe2);
    pipe(pipe3);
    pipe(pipe4);

    int calificaciones[10]={};
    int media = 0;
    int maxima = 0;
    int aprobados = 0;
    int suspensos = 0;
    pid_t pid = fork();

    if(pid == 0){
        close(pipe1[0]);
        close(pipe3[1]);
        close(pipe2[0]); 
        close(pipe2[1]);
        close(pipe4[0]); 
        close(pipe4[1]);

        read(pipe3[0], calificaciones, sizeof(calificaciones));
        
        for(int i = 0; i < 10; i++){
            media += calificaciones[i];
            if(maxima < calificaciones[i]){
                maxima = calificaciones[i];
            }
        }
        media = media / 10;
        write(pipe1[1], &media, sizeof(media));
        write(pipe1[1], &maxima, sizeof(maxima));

        close(pipe1[1]);
        close(pipe3[0]);
        
    }else{
        pid_t pid2 = fork();
        if(pid2 == 0){
            close(pipe2[0]);
            close(pipe4[1]);
            close(pipe1[0]); 
            close(pipe1[1]);
            close(pipe3[0]); 
            close(pipe3[1]);

            read(pipe4[0], calificaciones, sizeof(calificaciones));
            
            for(int i = 0; i < 10; i++){
                if(calificaciones[i] >= 5){
                    aprobados += 1;
                }else{
                    suspensos += 1;
                }
            }

            write(pipe2[1], &aprobados, sizeof(aprobados));
            write(pipe2[1], &suspensos, sizeof(suspensos));

            close(pipe2[1]);
            close(pipe4[0]);
            
        }else{
            close(pipe1[1]);
            close(pipe2[1]);
            close(pipe3[0]);
            close(pipe4[0]);

            for(int i = 0; i < 10; i++){
                printf("dame la calificacion del %d alumno \n", i + 1);
                scanf("%d", &calificaciones[i]);
            }

            write(pipe3[1], calificaciones, sizeof(calificaciones));
            write(pipe4[1], calificaciones, sizeof(calificaciones));

            close(pipe3[1]);
            close(pipe4[1]);

            read(pipe1[0], &media, sizeof(media));
            read(pipe1[0], &maxima, sizeof(maxima));
            read(pipe2[0], &aprobados, sizeof(aprobados));
            read(pipe2[0], &suspensos, sizeof(suspensos));

            close(pipe1[0]);
            close(pipe2[0]);

            wait(NULL);
            wait(NULL);

            printf("la nota maxima es %d\n", maxima);
            printf("la media d elas notas es %d\n", media);
            printf("el numero de aprobados es %d\n", aprobados);
            printf("el numero de suspensos es %d\n", suspensos);
        }
    }
    exit(0);
}
