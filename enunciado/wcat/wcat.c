#include <stdio.h> // libreria para el desarrollo de operaciones de entrada y de salida 
#include <stdlib.h> // libreria para el control de procesos y memoria dinamica

int main(int argc, char *argv[]) {
  
  char line[1000]; 
  
  FILE *iF;
    while(--argc >0){
     iF = fopen(*++argv, "r");
  
  	if (iF == NULL) {
          printf("wcat: cannot open file\n");
          exit(1);
        }

         while(fgets(line, 1000, iF)!=NULL) {
          printf("%s",line);
       } 
   fclose(iF);
  
  }
  exit(0);
}
