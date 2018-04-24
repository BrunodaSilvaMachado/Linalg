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
    double **matriz,**matriz2,**inv;
    double *raiz;
    int linha,coluna,linha2,coluna2;

    if (argc < 2){
        puts("Entre com duas matizes:Ex: ./main matriz.dat matriz2.dat\n"); 
        return 1;
    }


    puts("\n~~~~~~~~~~~~~~~ Solução do sistema da matriz 1 ~~~~~~~~~~~~~\n");
    
    matriz = lerMatriz(argv[1],&linha,&coluna);
    imprimeMatriz(matriz,linha,coluna);

    puts("\n******************** Pelo metodo de Jacobi *****************\n");
    raiz = metodoJacobi(matriz,linha,0);
    imprimeRaiz(raiz,coluna);

    puts("\n******************** Pelo metodo de Gauss ******************\n");
    raiz = metodoGauss(matriz,linha,coluna);
    imprimeRaiz(raiz,coluna);
    
    printf("Norma das raizes: %lf\n",normalize(raiz,coluna));

    puts("\n******************** Triangularizando a matriz ******************\n");
    triangularSuperior(matriz,linha,coluna);
    imprimeMatriz(matriz,linha,coluna);

    puts("\n~~~~~~~~~~~~~~~ Operações com matriz 2 ~~~~~~~~~~~~~\n");
    
    matriz2 = lerMatriz(argv[2],&linha2,&coluna2);
    imprimeMatriz(matriz2,linha2,coluna2);
    
    printf("Determinante: %lf\n ",determinante(matriz2,linha2));

    puts("\n******************** matriz inversa ********************\n");
    inv = matrizInversa(matriz2,linha2,coluna2);
    imprimeMatriz(inv,linha2,coluna2);
    printf("Determinante: %lf\n",determinante(inv,linha2));
    puts("\n");
    
    puts("\nProduto da matriz inversa com a matriz de entrada\n");
    imprimeMatriz(multiplicaMatriz(matriz2,inv,linha2,coluna2,coluna2),linha2,coluna2);

    puts("\n~~~~~~~~~~~~~~~ Outras Matrizes ~~~~~~~~~~~~~\n");
    
    puts("\nmatriz identidade\n");
    imprimeMatriz(matrizIdentidade(linha2,coluna2),linha2,coluna2);
    puts("\n");

    puts("\nmatriz nula\n");

    imprimeMatriz(matrizNula(linha2,coluna2),linha2,coluna2);
    puts("\n");
    

    for(; linha > 0; linha--)
        free(matriz[linha -1]);
    for(; linha2 > 0; linha2--){
        free(matriz2[linha2 -1]);
        free(inv[linha2 -1]);
    }
    return 0;
}

