#include <linalg.h>

/**
*@title 	normalize
*@descript 	calcula a norma de um vetor
*@param 	v	vetor numerico
*@param		dim comprimento do vetor
*@return 	retorna a norma do vetor
*
*/

double normalize(double *v,int dim)
{
    int i;
    double sum = 0;
    for(i = 0; i < dim; i++)
    {
        sum += v[i] * v[i];
    }

    sum = sqrt(sum);

    return sum;
}
