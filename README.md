# Linalg

Linalg é uma simples biblioteca de algebra linear com o objetivo de fornecer os principais metodos de manipulação de matrizes e sistemas lineares

# Funções disponiveis

A seguir uma lista com todas as funções disponiveis para mais detalhes no codigo fonte disponiveis na pasta src

``` c
double **lerMatriz(const char *, int *, int *);
```
__Titulo:__ lerMatriz

__Descrição__: lê uma matriz armazenada em um arquivo de texto

``` c
void imprimeMatriz(double **, int , int );
```
__Titulo:__ imprimeMatriz

__Descrição__: imprime uma matriz m x n

``` c
double determinante(double **, int );
```
__Titulo:__ determinante

__Descrição__: recebe uma matriz quadrada de dimensão n calcula o determinante. Retorna o valor do determinante  

``` c
int triangularSuperior(double **, int , int );
```
__Titulo:__ triangularSuperior

__Descrição__: transforma uma matriz não ortogonal em uma matriz triangular superior.
obs: este metodo faz pivotamento da matriz durante o processo de escalonamento retornando o numero de linhas alteradas no final

``` c
int compararMatriz(double **, double ** ,int , int );
```
__Titulo:__ compararMatriz

__Descrição__: compara se o conteudo de duas matrizes n x m são iguais. Retorna um se igual, zero se diferente.

``` c
double *metodoJacobi(double **, int , int , double );
```
__Titulo:__ metodoJacobi

__Descrição__:  uma algoritmo iterativo para resolver sistemas de equações lineares. Resolvese o membro esquerdo da expressão em ordem a x ao usar metodo resultante da iteração anterior no membro direito, isso pode ser escrito como: x^(k + 1) = D^-1(b - RX^(k)).
Retorna um vetor de soluções da matriz informada 

``` c
double *metodoGauss(double **, int , int  );
```
__Titulo:__ metodoGauss

__Descrição__: É um procedimento usada para resolver sistemas de equações lineares. Ele consiste em aplicar sucessivas operações elementares num sistema de equações genericos até apresentar a forma triangular superior, que apresenta exatamente as mesmas soluções que o original, é então resolvida com emprego da substituição regressiva.
Retorna um vetor de soluções da matriz informada.

``` c
double **multiplicaMatriz(double **, double ** ,int , int );
```
__Titulo:__ multiplicaMatriz

__Descrição__: multiplica duas matrizes n x m. Retorna o produto das duas marizes

``` c
double **somaMatriz(double **, double ** ,int , int );
```
__Titulo:__ somaMatriz

__Descrição__: soma duas matrizes n x m. Retorna a soma das matrizes

``` c
double **diferencaMatriz(double **, double ** ,int , int );
```
__Titulo:__ diferencaMatriz

__Descrição__: calcula a diferença entre duas matrizes n x m. Retorna a diferença das matrizes

``` c
double **matrizNula(int , int );
```
__Titulo:__ matrizNula

__Descrição__: recebe uma dimensão de devolve uma matriz nula n x m

``` c
double **matrizInversa(double **, int , int );
```
__Titulo:__ matrizInversa

__Descrição__: esta função recebe uma matriz não nula, calcula e retorna a sua inversa

``` c
double **matrizIdentidade(int , int );
```
__Titulo:__ matrizIdentidade

__Descrição__: recebe uma dimensão de devolve uma matriz identidade n x m 

``` c
double **matrizTransposta(double **, int , int );
```
__Titulo:__ matrizTransposta

__Descrição__: calcula a transposta da matriz 

``` c
double normalize(double *,int );
```
__Titulo:__ normalize

__Descrição__: calcula a norma de um vetor

``` c
double *substituicaoRegressiva(double **, int );
```
__Titulo:__ substituicaoRegressiva

__Descrição__: tecnica de solução de sistemas lineares atraves de regresão


# Exemplos

para compilar os exemplos a seguir use:

>  gcc -L. -Wl,-rpath=. -o main main.c -llinalg -I./include

``` c
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

```

# Resultado

```

~~~~~~~~~~~~~~~ Solução do sistema da matriz 1 ~~~~~~~~~~~~~

10.000	-1.000	 2.000	 0.000	 6.000	
-1.000	11.000	-1.000	 3.000	25.000	
 2.000	-1.000	10.000	-1.000	-11.000	
 0.000	 3.000	-1.000	 8.000	15.000	
________

******************** Pelo metodo de Jacobi *****************


__roots__

x[1] = 1.00000
x[2] = 2.00000
x[3] = -1.00000
x[4] = 1.00000
x[5] = 0.00000
________

******************** Pelo metodo de Gauss ******************


__roots__

x[1] = 1.00000
x[2] = 2.00000
x[3] = -1.00000
x[4] = 1.00000
x[5] = 0.00000
________
Norma das raizes: 2.645751

******************** Triangularizando a matriz ******************

10.000	-1.000	 2.000	 0.000	 6.000	
 0.000	10.900	-0.800	 3.000	25.600	
 0.000	 0.000	 9.541	-0.780	-10.321	
 0.000	-0.000	 0.000	 7.111	 7.111	
________

~~~~~~~~~~~~~~~ Operações com matriz 2 ~~~~~~~~~~~~~

 2.000	 1.000	-1.000	 1.000	
 1.000	 1.000	 0.000	 3.000	
-1.000	 2.000	 3.000	-1.000	
 3.000	-1.000	-1.000	 2.000	
________
Determinante: 39.000000
 
******************** matriz inversa ********************

 0.333	 0.200	 0.133	-0.231	
 0.000	 0.600	 0.067	 0.077	
 0.000	 0.000	 0.333	 0.000	
 0.000	-0.000	-0.000	 0.385	
________
Determinante: 0.025641



Produto da matriz inversa com a matriz de entrada

 1.000	 0.000	 0.000	 0.000	
 0.000	 1.000	 0.000	 0.000	
 0.000	-0.000	 1.000	-0.000	
 0.000	 0.000	 0.000	 1.000	
________

~~~~~~~~~~~~~~~ Outras Matrizes ~~~~~~~~~~~~~


matriz identidade

 1.000	 0.000	 0.000	 0.000	
 0.000	 1.000	 0.000	 0.000	
 0.000	 0.000	 1.000	 0.000	
 0.000	 0.000	 0.000	 1.000	
________



matriz nula

 0.000	 0.000	 0.000	 0.000	
 0.000	 0.000	 0.000	 0.000	
 0.000	 0.000	 0.000	 0.000	
 0.000	 0.000	 0.000	 0.000	
________



```

# menções

@thadeupenna
