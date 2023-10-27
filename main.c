#include <stdio.h>
#include <stdlib.h>

typedef struct heap
{
    int n;
    int nMax;
    float *v;
} Heap;

Heap *heapCria (int tamanhoMax)
{
    Heap *h = (Heap*)malloc(sizeof(Heap));
    h->n = 0;
    h->nMax = tamanhoMax;
    h->v = (float*)malloc(tamanhoMax * sizeof(float));
    return h;
}

static void troca (Heap *raiz, int indiceFilho, int indicePai)
{
    float tmp = raiz->v[indicePai];
    raiz->v[indicePai] = raiz->v[indiceFilho];
    raiz->v[indiceFilho] = tmp;
}

static void sobe (Heap *raiz, int indiceFilho)
{
    int indicePai = (indiceFilho-1)/2;
    while (indiceFilho > 0)                                    // itera enquanto nao chegar na raiz
        if (raiz->v[indicePai] >= raiz->v[indiceFilho])        // se o valor do pai for maior ou igual
        {
            break;
        }        
        else
        {
            troca (raiz, indicePai, indiceFilho);
            indiceFilho = indicePai;
        }
    
}

int heapVazia (Heap *raiz)
{
    return (raiz->n == 0);
}

void heapLibera (Heap *raiz)
{
    free (raiz->v);
    free (raiz);
}

void heapInsere (Heap *raiz, float novoValor)
{
    if (raiz->n == raiz->nMax)
    {
        printf ("Heap cheio, impossivel inserir.\n");
    }
    raiz->v[raiz->n++] = novoValor;
    sobe (raiz, raiz->n-1);
}

static void desce (Heap *raiz, int indicePai)
{
    int indiceFilhoEsq = (2 * indicePai + 1);
    while (indiceFilhoEsq < raiz->n) // enquanto estiver nos limites da heap
    {
        int indiceFilhoDir = (2 * indicePai + 2);
        if ((indiceFilhoDir < raiz->n) && (raiz->v[indiceFilhoDir] > raiz->v[indiceFilhoEsq]))
        {
            indiceFilhoEsq = indiceFilhoDir;    // troca os filhos de lugar, se necessario
                                                // para o maior ficar na esquerda.
        }
        if (raiz->v[indicePai] > raiz->v[indiceFilhoEsq])   // se o pai for maior que o maior filho, break
        {
            break;
        }
        troca (raiz, indicePai, indiceFilhoEsq);
        indicePai = indiceFilhoEsq;
        indiceFilhoEsq = (2 * indicePai + 1);
    }
}

float heapRetira (Heap *raiz)
{
    float valorRetirado = raiz->v[0];
    raiz->n--;  // decrementa o numero de elementos.
    raiz->v[0] = raiz->v[raiz->n]; // coloca na raiz a ultima folha
    desce (raiz, 0);
}

void heapImprime (Heap *raiz, int indice)
{
    if (indice < raiz->n)
    {
        printf ("No %.0f: ", indice);
        int esq = 2 * indice + 1;
        int dir = 2 * indice + 2;
        if (esq < raiz->n)
        {
            printf ("filho esq: %.0f, ", raiz->v[esq]);
        }
        else
        {
            printf ("filho esq: vazio, ");
        }
        if (dir < raiz->n)
        {
            printf ("filho dir: %.0f.\n", raiz->v[dir]);
        }
        else
        {
            printf ("filho dir: vazio.\n");
        }
        heapImprime (raiz, esq);
        heapImprime (raiz, dir);
    }
}

void heapBusca (Heap *raiz, float valorProcurado)
{
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

int main ()
{

}