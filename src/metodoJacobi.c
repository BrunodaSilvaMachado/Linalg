#include "linalg.h"

/**
*@title 	metodoJacobi
*@descript 	é uma algoritmo iterativo para resolver sistemas de equações lineares. Resolvese o membro esquerdo da expressão em ordem a x ao usar metodo resultante da iteração anterior no membro direito, isso pode ser escrito como: x^(k + 1) = D^-1(b - RX^(k))
*@param 	matriz 	ponteiro para uma matriz
*@param		dim dimenção da matriz
*@param 	E valor da precisão procurada
*@return	retorna um vetor de soluções da matriz informada
*
*/

double *metodoJacobi(double **A, int dim, double E)
{
    double *y;
    double *x;
    int i,j;

    y = (double*)malloc(dim*sizeof(double));
    x = (double*)malloc(dim*sizeof(double));

    memset(y,0,dim*sizeof(double));

    if(E <= 0) E = 0.00001;//Precisão
    int m = 1000;//Numero máximo de iterações
    int ni = 0;//Contador de iterações
    int continuar = 1;

    while (continuar && ni < m)
    {
        for (i = 0; i < dim; i++)
        {
            double soma = 0;
            for (j = 0; j < dim; j++)
            {
                if (j != i)
                {
                    soma = soma + A[i][j]*y[j]/(double)A[i][i];
                }
                x[i] = (A[i][dim]/(double)A[i][i]) - soma;
            }
        }
        if (fabs(normalize(x,dim) - normalize(y,dim)) < E)
        {
            continuar = 0;
        }
        else
        {
            memcpy(y,x,dim*sizeof(double));
        }
        ni = ni + 1;
    }
    return y;
}
