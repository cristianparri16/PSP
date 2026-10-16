#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 

void main(){

     int fd[2]; 
     int numeros[]={3,4,79};
     pid_t pid;
    
    
     pipe(fd); 
     
     
     pid = fork();

     if (pid==0)
     
     {
                close(fd[1]); 
                int numero,suma;
               char caracter;  
                for(int e=0;e<sizeof(numeros)/sizeof(numeros[1]);e++){
                    read(fd[0], &numero, sizeof(int));
                    printf("Numero a sumar: %d\n", numero);
                    suma += numero;
                    
               }
               read(fd[0],&caracter,sizeof(char));

               printf("Recibido carácter %c\n",caracter);
               printf("la suma total es de %d",suma);
               close(fd[0]);
                
     
     }
     
     else
     
     {
               
                close(fd[0]); 
                for(int e=0;e<sizeof(numeros)/sizeof(numeros[1]);e++){
                write(fd[1], &numeros[e], sizeof(int)); 
                } 
                write(fd[1],"+",sizeof(char));
                close(fd[1]);
                wait(NULL); 
                   
     }
     exit(0);
     
}    
