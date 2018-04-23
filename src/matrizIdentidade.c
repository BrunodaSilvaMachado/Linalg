#include <linalg.h>

/**
*@title matrizIdentidade
*@descript recebe uma dimensão de devolve uma matriz identidade
*@param linha numero de linhas da matriz
*@param coluna numero de colunas da matriz
*@return matriz identidade n x m
*
*/

double **matrizIdentidade(int linha, int coluna)
{
    double **identidade;
    int i;

    identidade = (double**)malloc(linha * sizeof(double));
    for(i = 0; i< linha; i++)
    {
        identidade[i] = (double*)malloc((coluna) * sizeof(double));
        memset(identidade[i],0,(coluna) * sizeof(double));
        identidade[i][i] = 1;
    }
    return identidade;
}
