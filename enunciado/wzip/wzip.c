#include <stdio.h>
#define INTLEN 4      // 4-byte de Entero solicitado en el enunciado
#define ASCLEN 1      // 1-byte caracter ASCII solicitado en el enuncuado

void write(int, char, FILE*);

int main(int argc, char *argv[])
{
    char caracter,compara = '\0';// \0 se utliza para representar caracter null en ascci
				// carater= variable que usaremos para leer el caracter estraido recien del archivo
      				// compara= variable utilizada para comparar el carater ya almacenado
    FILE *fp;
    int contador;

    if (argc < 2) {
        printf("wzip: file1 [file2 ...]\n");
        return 1;
    }
    while (--argc > 0) {
        if ((fp = fopen(*++argv, "r")) == NULL)
            return 1;
        while ((caracter = getc(fp)) != EOF) {//GETC retorna un carater desde la linea; EOF parametro booleano para el cierre de ciclos
            if (caracter == compara)
                contador++;
            else {
                if (compara != '\0')
                    write(contador, compara, stdout);
                compara = caracter;
                contador = 1;
            }
        }
        fclose(fp);
    }
    write(contador, compara, stdout);
    return 0;
}

/*
   funcion utilizada para escribir un entero de 4 bytes en binario con un numero ASCCI de 1 byte
 */
void write(int contador, char caracter, FILE *ff)
{
    fwrite(&contador, INTLEN, 1, ff);
    fwrite(&caracter, ASCLEN, 1, ff);
}
