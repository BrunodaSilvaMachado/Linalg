#include <linalg.h>

/**
*@title matrizNula
*@descript recebe uma dimensão de devolve uma matriz nula n x m
*@param linha numero de linhas da matriz
*@param coluna numero de colunas da matriz
*@return matriz nula n x m
*
*/

double **matrizNula(int linha, int coluna)
{
    double **nula;
    int i;

    nula = (double**)malloc(linha * sizeof(double));
    for(i = 0; i< linha; i++)
    {
        nula[i] = (double*)malloc((coluna) * sizeof(double));
        memset(nula[i],0,(coluna) * sizeof(double));
    }
    return nula;
}
