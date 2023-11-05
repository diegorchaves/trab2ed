#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

Heap *heapCria (int tamanhoMax)
{
    Heap *h = (Heap*)malloc(sizeof(Heap));
    h->n = 0;
    h->nMax = tamanhoMax;
    h->v = (int*)malloc(tamanhoMax * sizeof(int));
    return h;
}

void troca (Heap *raiz, int indiceFilho, int indicePai)
{
    int tmp = raiz->v[indicePai];
    raiz->v[indicePai] = raiz->v[indiceFilho];
    raiz->v[indiceFilho] = tmp;
}

void sobe (Heap *raiz, int indiceFilho)
{
    int indicePai = (indiceFilho-1)/2;
    while (indiceFilho >= 0)
    {
        if (raiz->v[indicePai] >= raiz->v[indiceFilho])
        {
            break;
        }        
        else
        {
            troca (raiz, indiceFilho, indicePai);
            indiceFilho = indicePai;
            indicePai = (indiceFilho-1)/2;
        }
    }
}

int heapVazia (Heap *raiz)
{
    return (raiz->n == 0);
}

void heapLibera (Heap *raiz)
{
    if (raiz != NULL) 
    {
        if (raiz->v != NULL) 
        {
            free(raiz->v);
            raiz->v = NULL;
        }
        free(raiz);
    }
}

void heapInsere (Heap *raiz, int novoValor)
{
    if (raiz->n == raiz->nMax)
    {
        printf ("Heap cheio, impossivel inserir.\n");
    }
    raiz->v[raiz->n] = novoValor;
    raiz->n++;
    sobe (raiz, raiz->n-1);
}

void desce (Heap *raiz, int indicePai)
{
    int indiceFilhoEsq = (2 * indicePai + 1);
    while (indiceFilhoEsq < raiz->n)
    {
        int indiceFilhoDir = (2 * indicePai + 2);
        if ((indiceFilhoDir < raiz->n) && (raiz->v[indiceFilhoDir] > raiz->v[indiceFilhoEsq]))
        {
            indiceFilhoEsq = indiceFilhoDir;
        }
        if (raiz->v[indicePai] > raiz->v[indiceFilhoEsq])
        {
            break;
        }
        troca (raiz, indicePai, indiceFilhoEsq);
        indicePai = indiceFilhoEsq;
        indiceFilhoEsq = (2 * indicePai + 1);
    }
}

void heapRetira (Heap *raiz)
{
    if (heapVazia (raiz))
    {
        printf ("Heap vazia.\n");
        return;
    }
    int valorRetirado = raiz->v[0];
    raiz->n--;
    raiz->v[0] = raiz->v[raiz->n];
    desce (raiz, 0);
}

void heapImprime (Heap *raiz, int indice)
{
    if (heapVazia(raiz))
    {
        printf ("Heap vazia.\n");
        return;
    }
    if (indice < raiz->n)
    {
        printf ("No %d: ", raiz->v[indice]);
        int esq = 2 * indice + 1;
        int dir = 2 * indice + 2;
        if (esq < raiz->n)
        {
            printf ("filho esq: %d, ", raiz->v[esq]);
        }
        else
        {
            printf ("filho esq: vazio, ");
        }
        if (dir < raiz->n)
        {
            printf ("filho dir: %d.\n", raiz->v[dir]);
        }
        else
        {
            printf ("filho dir: vazio.\n");
        }
        heapImprime (raiz, esq);
        heapImprime (raiz, dir);
    }
}

void heapBusca (Heap *raiz, int valorProcurado)
{
    if (heapVazia(raiz))
    {
        printf ("Heap vazia.\n");
        return;
    }
    for (int i = 0; i < raiz->n; i++)
    {
        if (raiz->v[i] == valorProcurado)
        {
            printf ("Valor encontrado no indice %d.\n", i);
            return;
        }
    }
    printf ("Valor nao encontrado.\n");
}