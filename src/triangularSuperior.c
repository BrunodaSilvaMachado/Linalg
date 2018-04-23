#include <linalg.h>

/**
*@title 	triangularSuperior
*@descript 	transforma uma matriz não ortogonal em uma matriz
*			triangular superior
*@param 	v	vetor numerico
*@param		linha numero de linhas da matriz
*@param		coluna numero de colunas da matriz
*@return 	retorna o numero de linhas alteradas pelo pivotamento
*
*/

int triangularSuperior(double **m, int linha, int coluna)
{
    int i,j,k,l,troca,cont = 0;
    double n;

    double *aux;

    aux = (double*)malloc((coluna) * sizeof(double));

    for(i = 0; i < linha; i++)
    {

        troca = -1;
        for(l = i; l < linha; l++)
        {
            if(m[i][i] < fabs(m[l][i]))
            {
                troca = l;
            }
        }

        if(troca != -1)
        {
            memcpy(aux, m[troca], coluna * sizeof(double));
            memcpy(m[troca], m[i], coluna * sizeof(double));
            memcpy(m[i], aux, coluna * sizeof(double));
            cont++;
        }

        for(j = i + 1; j < linha; j++)
        {
            n = m[j][i]/(double)m[i][i];

            for(k = 0; k < coluna; k++)
            {
                m[j][k] = m[j][k] - n * m[i][k];
            }
        }
    }
    return cont;
}
