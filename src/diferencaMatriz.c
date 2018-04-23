#include <linalg.h>

/**
*@title			diferencaMatriz
*@descript		calcula a diferença entre duas matrizes n x m.
*@param m1		ponteiro para matriz
*@param m2		ponteiro para matriz
*@param linha 	numero de linhas da matriz
*@param coluna 	numero de colunas da matriz
*@return 		Retorna a diferença das matrizes
*
*/

double **diferencaMatriz(double **m1, double **m2,int linha, int coluna)
{
    double **m3;
    int i,j;

    m3 = (double**)malloc(linha * sizeof(double));
    for(i = 0; i< linha; i++)
    {
        m3[i] = (double*)malloc((coluna) * sizeof(double));
    }

    for(i = 0; i < linha; i++)
    {
        for(j = 0; j < coluna; j++)
        {
            m3[i][j] = m1[i][j] - m2[j][i];
        }
    }

    return m3;
}
