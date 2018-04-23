/*
 * main.c
 *
 * Copyright 2018 Bruno da Silva Machado <brunosilvamachado@id.uff.br>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <linalg.h>

void imprimeRaiz(double *r, int dim)
{
    int i;

    puts("\n__roots__\n");

    for(i = 0; i < dim; i++)
    {
        printf("x[%d] = %6.5lf\n",i + 1,r[i]);
    }

    puts("________");
}

int main(int argc, char **argv)
{
    double **matriz;
    double *raiz;
    int linha,coluna;

    matriz = lerMatriz(argv[1],&linha,&coluna);
    imprimeMatriz(matriz,linha,coluna);

    puts("Solução do sistema\n");

    puts("Pelo metodo de Jacobi\n");
    raiz = metodoJacobi(matriz,linha,0);
    imprimeRaiz(raiz,coluna);

    puts("Pelo metodo de Gauss\n");
    raiz = metodoGauss(matriz,linha,coluna);
    imprimeRaiz(raiz,coluna);

    printf("Determinante: %lf\nNorma das raizes: %lf\n ",determinante(matriz,linha),normalize(raiz,coluna));

    puts("\nmatriz inversa\n");
    matriz = matrizInversa(matriz,linha,coluna);
    imprimeMatriz(matriz,linha,coluna);
    printf("Determinante: %lf\n",determinante(matriz,linha));
    puts("\n");

    puts("\nmatriz identidade\n");
    imprimeMatriz(matrizIdentidade(linha,coluna),linha,coluna);
    puts("\n");

    puts("\nmatriz nula\n");

    imprimeMatriz(matrizNula(linha,coluna),linha,coluna);
    puts("\n");

    for(; linha > 0; linha--)
        free(matriz[linha -1]);
    free(raiz);
    return 0;
}

