#include <stdio.h>
#define INTLEN 4      // 4-byte de Entero solicitado en el enunciado
#define ASCLEN 1      // 1-byte caracter ASCII solicitado en el enuncuado

int main(int argc, char *argv[])
{
    FILE *fp;
    char caracter;
    int byte;

    if (argc < 2) {
        printf("wunzip: file1 [file2 ...]\n");
        return 1;
    }
    while (--argc > 0) {
        if ((fp = fopen(*++argv, "r")) == NULL)
            return 1;
        while (fread(&byte, INTLEN, 1, fp)) {// fread lee la linea
            fread(&caracter, ASCLEN, 1, fp);// convierte a ASCCI
            while (byte-- > 0)
                printf("%c", caracter);
        }
        fclose(fp);
    }
    return 0;
}
