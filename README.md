# Linalg

Linalg é uma simples biblioteca de algera linear com o objetivo de fornecer os pricipais metodos de manipulação de matrizes e sistemas lineares

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

>  gcc -Wall -L. -Wl,-rpath=.\bin -llinalg -o main main.c -I./include

``` c
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
    return 0;
}

```

# menções

@thadeupenna
