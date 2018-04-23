#include <linalg.h>

/**
*@title 		compararMatriz
*@descript 		compara se o conteudo de duas matrizes n x m são iguais
*@param m1		ponteiro para matriz
*@param m2		ponteiro para matriz
*@param linha 	numero de linhas da matriz
*@param coluna 	numero de colunas da matriz
*@return 		1 se igual, zero se diferente.
*
*/

int compararMatriz(double **m1, double **m2,int linha, int coluna)
{
    int i,j;

    for(i = 0; i < linha; i++)
    {
        for(j = 0; j < coluna; j++)
        {
            if(m1[i][j] != m2[i][j])
                return 0;
        }
    }
    return 1;
}
