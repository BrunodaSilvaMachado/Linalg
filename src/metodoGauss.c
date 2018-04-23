#include <linalg.h>

/**
*@title 	substituicaoRegressiva
*@descript 	tecnica de solução de sistemas numericos
*@param 	m 	ponteiro para uma matriz triangular superior
*@param		dim	dimensão da matriz
*@return	retorna um vetor de soluções da informada
*
*/

double *substituicaoRegressiva(double **m, int dim)
{
    double *root = (double*)malloc(dim * sizeof(double));
    double sum;
    int i,j,n;

    n = dim - 1;
    root[n] = m[n][dim]/(double)m[n][n];

    for(i = n - 1; i >= 0; i--)
    {
        sum = 0;

        for(j = i + 1; j <= n; j++ )
        {
            sum += m[i][j] * root[j];
        }

        root[i] = (m[i][dim] - sum)/(double)m[i][i];
    }
    return root;
}


/**
*@title 	substituicaoRegressiva
*@descript 	É um procedimento usada para resolver sistemas de equações lineares. Ele consiste em aplicar sucessivas operações elementares num
*			sistema de equações genericos até apresentar a forma triangular superior, que apresenta exatamente as mesmas soluções que o original, é então
*			resolvida com emprego da substituição regressiva.
*@param 	matriz 	ponteiro para uma matriz
*@param		linha numero de linhas da matriz
*@param		coluna numero de colunas da matriz
*@return	retorna um vetor de soluções da matriz informada
*
*/

double *metodoGauss(double **matriz, int linha, int coluna )
{
    triangularSuperior(matriz,linha,coluna);

    return substituicaoRegressiva(matriz,linha);
}
