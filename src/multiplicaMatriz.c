#include <linalg.h>

/**
*@title 		multiplicaMatriz
*@descript 		multiplica duas matrizes n x m
*@param m1		ponteiro para matriz
*@param m2		ponteiro para matriz
*@param linha 	numero de linhas da matriz 1
*@param coluna 	numero de colunas da matriz 1
*@param coluna2 numero de colunas da matriz 2
*@return 		retorna o produto das duas marizes
*
*/

double **multiplicaMatriz(double **m1, double **m2,int linha, int coluna,int coluna2)
{
    double **m3;
    double sum;
    int i,j,k;

    m3 = (double**)malloc(linha * sizeof(double));
    for(i = 0; i< linha; i++)
    {
        m3[i] = (double*)malloc((coluna2) * sizeof(double));
    }

    for(k = 0; k < coluna2; k++)
    {
        
        for(i = 0; i < linha; i++)
        {
        	sum = 0;
        	for(j = 0; j < coluna; j++)
            	sum += m1[i][j]*m2[j][k];
            
            m3[i][k] = sum;
        }
        
    }

    return m3;
}
