#include <stdio.h>
#include <stdlib.h>
// pai (i) (((i)-1)/2)
// esq (i) (2*(i)+1)
// dir (i) (2*(i)+2)

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

int main ()
{

}