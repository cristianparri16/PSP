#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h>
void main(){

     int fd[2]; 
     pid_t pid;
    
    
     pipe(fd); 
     
     
     pid = fork();

     if (pid==0)
     
     {
            close(fd[0]); 
            time_t t;
            int numero1,numero2;
            srand((unsigned) time(&t));

            numero1=rand() % 50;
            numero2=rand() % 50;
            int numeros[2]={numero1,numero2};   
                for(int e=0;e<2;e++){
                    write(fd[1], &numeros[e], sizeof(int));
                      
               }
            
               close(fd[1]);
                
     
     }
     
     else
     
     {
                int numero1,numero2;
                close(fd[1]); 
                
                
               read(fd[0], &numero1, sizeof(int));
                
                
                read(fd[0], &numero2, sizeof(int));
                close(fd[0]);
                wait(NULL);
                int suma=numero1+numero2;
                printf("%d + %d =%d\n",numero1,numero2,suma);
                int resta=numero1-numero2;
                printf("%d - %d =%d\n",numero1,numero2,resta);
                int multiplicacion=numero1*numero2; 
                printf("%d * %d =%d\n",numero1,numero2,multiplicacion);
                int division=numero1/numero2;
                printf("%d / %d =%d\n",numero1,numero2,division);  
     }
     exit(0);
     
}    
