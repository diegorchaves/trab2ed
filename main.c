#include <stdio.h>
#include <stdlib.h>
#define pai (i) (((i)-1)/2)
#define esq (i) (2*(i)+1)
#define dir (i) (2*(i)+2)

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

void heapInsere (Heap *raiz, float novoValor)
{
    if (raiz->n == raiz->nMax)
    {
        printf ("Heap cheio, impossivel inserir.\n");
    }
    raiz->v[raiz->n++] = novoValor;
    sobe (raiz, raiz->n-1);
}

int main ()
{

}