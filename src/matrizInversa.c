#include "linalg.h"

/**
*
*@title 	matrizInversa
*@descript	esta função recebe uma matriz e calcula a sua inversa
*@param 	m 		ponteiro para matriz a ser invertida
*@param 	linha 	numero de linhas da matriz
*@param 	coluna 	numero de colunas da matriz
*@return 	retorna uma matriz inversa
*
*/

double **matrizInversa(double **m, int linha, int coluna)
{
    double **inversa;
    double **mcomp;
    double **maux;
    int i,j,k = 0;

    maux = (double**)malloc(linha * sizeof(double));
    mcomp = (double**)malloc(linha * sizeof(double));
    inversa = (double**)malloc(linha * sizeof(double));

    for(i = 0; i< linha; i++)
    {
        mcomp[i] = (double*)malloc((coluna + 1) * sizeof(double));
        maux[i] = (double*)malloc((2*coluna) * sizeof(double));
        inversa[i] = (double*)malloc((coluna) * sizeof(double));
    }

    //1° criar a matriz aumentada
    for(i = 0; i < linha; i++)
    {
        for(j = 0; j < coluna; j++)
        {
            maux[i][j] = m[i][j];
            maux[i][j + coluna] = (i == j)? 1: 0;
        }
    }
    //2° escalona a matriz para forma triangular superior
    triangularSuperior(maux,linha,2*coluna);
    if(determinante(m,linha) == 0)
    {
        puts("A matriz informada não possue inversa. Erro: SINGULAR_MATRIX\n");
        return m;
    }

    //3° copia a matriz aumentada para matriz compressão
    for(i = 0; i < linha; i++)
    {
        for(j = 0; j < coluna; j++)
        {
            mcomp[i][j] = maux[i][j];
        }
    }
    //4° calcula a inversa
    for(i = 0; i < linha; i++)
    {
        for(j = 0; j < linha; j++)
        {
            mcomp[j][coluna] = maux[j][coluna + k];
        }
        k++;
        inversa[i] = substituicaoRegressiva(mcomp,linha);
    }
    //5° transpoe a matiz inversa
    inversa = matrizTransposta(inversa,linha,coluna);
    //6° seja feliz :)
    return inversa;
}
