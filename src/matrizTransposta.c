#include <linalg.h>

/**
*@title matrizTransposta
*@descript calcula a transposta da matriz
*@param 	matriz 	ponteiro para uma matriz
*@param		linha numero de linhas da matriz
*@param		coluna numero de colunas da matriz
*@return 	matriz transposta
*
*/

double **matrizTransposta(double **m, int linha, int coluna)
{
    double **t;
    int i,j;

    t = (double**)malloc(coluna * sizeof(double*));

    for(i = 0; i < coluna; i++)
    {
        t[i] = (double*)malloc(linha * sizeof(double));
    }
    for(i = 0; i < linha; i++)
    {
        for(j = 0; j < coluna; j++)
        {
            t[j][i] = m[i][j];
        }
    }
    return t;
}
