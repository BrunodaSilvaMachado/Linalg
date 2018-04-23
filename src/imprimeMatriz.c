#include <linalg.h>

/**
*@title imprimeMatriz
*@descript imprime uma matriz m x n
*@param 	m 		ponteiro para matriz a ser invertida
*@param 	linha 	numero de linhas da matriz
*@param 	coluna 	numero de colunas da matriz
*/

void imprimeMatriz(double **m, int linha, int coluna)
{
    int i,j;

    for(i = 0; i < linha; i++)
    {
        for(j = 0; j < coluna; j++)
        {
            printf("%6.3lf\t",m[i][j]);
        }
        puts("");
    }
    puts("________");
}
