#include <linalg.h>

/**
*@title 	determinante
*@descript 	recebe uma matriz quadrada de dimensão n calcula o determinante
*@param 	m	ponteiro para matriz
*@param		dim	dimensão da matriz quadrada
*@return	retorna o valor do determinante
*
*/

double determinante(double **m, int dim)
{
    double det = 1;
    int i,t;

    t = triangularSuperior(m,dim,dim);

    for(i = 0; i < dim; i++)
    {
        det *= m[i][i];
    }

    return pow(-1,t) * det;
}
