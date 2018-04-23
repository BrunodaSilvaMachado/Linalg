#include <linalg.h>

/**
*@title lerMatriz
*@descript 	lê uma matriz armazenada em um arquivo de texto
*
*
*
*/
double **lerMatriz(const char *arg, int *linha, int *coluna)
{
    double **m;
    int i,j;

    FILE *arq = fopen(arg,"r");

    if(arq == NULL)
    {
        printf("arquivo nao encontrado\n");
        exit(1);
    }

    fscanf(arq,"%d",linha);
    fscanf(arq,"%d",coluna);

    m = (double**)malloc((*linha) * sizeof(double*));

    for(i = 0; i < *linha; i++)
    {
        m[i] = (double*)malloc((*coluna) * sizeof(double));
    }

    for(i = 0; i < *linha; i++)
    {
        for(j = 0; j < *coluna; j++)
        {
            fscanf(arq,"%lf", &m[i][j]);
        }
    }
    fclose(arq);
    return m;

}
