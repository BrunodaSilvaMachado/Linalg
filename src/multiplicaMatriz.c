#include <linalg.h>

/**
*@title 		multiplicaMatriz
*@descript 		multiplica duas matrizes n x m
*@param m1		ponteiro para matriz
*@param m2		ponteiro para matriz
*@param linha 	numero de linhas da matriz
*@param coluna 	numero de colunas da matriz
*@return 		retorna o produto das duas marizes
*
*/

double **multiplicaMatriz(double **m1, double **m2,int linha, int coluna)
{
    double **m3;
    double sum;
    int i,j;

    m3 = (double**)malloc(linha * sizeof(double));
    for(i = 0; i< linha; i++)
    {
        m3[i] = (double*)malloc((coluna) * sizeof(double));
    }

    for(i = 0; i < linha; i++)
    {
        sum = 0;
        for(j = 0; j < coluna; j++)
        {
            sum += m1[i][j]*m2[j][i];
        }
        m3[i][j] = sum;
    }

    return m3;
}
