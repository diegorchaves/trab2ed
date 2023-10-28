#include <stdio.h>
#include <stdlib.h>

typedef struct heap
{
    int n;
    int nMax;
    int *v;
} Heap;

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
    while (indiceFilho >= 0)                                    // itera enquanto nao chegar na raiz
    {
        if (raiz->v[indicePai] >= raiz->v[indiceFilho])        // se o valor do pai for maior ou igual
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
    free (raiz->v);
    free (raiz);
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

void heapRetira (Heap *raiz)
{
    if (heapVazia (raiz))
    {
        printf ("Heap vazia.\n");
        return;
    }
    int valorRetirado = raiz->v[0];
    raiz->n--;  // decrementa o numero de elementos.
    raiz->v[0] = raiz->v[raiz->n]; // coloca na raiz a ultima folha
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

void menu (Heap *h)
{
    while (1)
    {
        int opcao;
        printf ("Digite a opcao desejada: \n");
        printf ("1) Inserir\n2) Remover\n3) Imprimir\n4) Sair\n");
        scanf ("%d", &opcao);
        switch (opcao)
        {
            case 1:
                int valorNovo;
                printf ("Digite o valor para inserir: ");
                scanf ("%d", &valorNovo);
                heapInsere (h, valorNovo);
                break;
            case 2:
                heapRetira (h);
                break;
            case 3:
                heapImprime (h, 0);
                break;
            case 4:
                heapLibera (h);
                return;
        }
    }
}

int main ()
{
    int tamanhoHeap;
    Heap *h = NULL;
    printf ("Digite o tamanho maximo da heap: ");
    scanf ("%d", &tamanhoHeap);
    h = heapCria (tamanhoHeap);
    menu (h);
}