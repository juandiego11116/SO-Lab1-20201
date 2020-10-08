#include<stdio.h>
#include<string.h>

void lectura(FILE *, char *);
int main(int argc, char *argv[])
{
    FILE *fp;
	//buscamos si la informacion ingresada es correcta
    if (argc < 2) {
        printf("wgrep: searchterm [file ...]\n");
        return 1;
    }


    if (argc == 2)
        lectura(stdin, argv[1]);
    	   else {
             for (int i = 2; i < argc; i++) {
               if ((fp = fopen(argv[i], "r")) == NULL) {
                 printf("wgrep: cannot open file\n");
                 return 1;
                }
                lectura(fp, argv[1]);
                fclose(fp);
             }   
          }
    return 0;
}


void lectura(FILE *f, char *p) 
{
    char *buf = NULL;
    size_t n = 0;
    // utlizamos la funcion strstr para comparar el contenido del archivo con la palabra
    while (getline(&buf, &n, f) != -1)
        if (strstr(buf, p) != NULL) 
            printf("%s", buf);
}
