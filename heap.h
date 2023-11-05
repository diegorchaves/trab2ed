typedef struct heap
{
    int n;
    int nMax;
    int *v;
} Heap;

Heap *heapCria (int tamanhoMax);
void troca (Heap *raiz, int indiceFilho, int indicePai);
void desce (Heap *raiz, int indicePai);
void sobe (Heap *raiz, int indiceFilho);
int heapVazia (Heap *raiz);
void heapLibera (Heap *raiz);
void heapInsere (Heap *raiz, int novoValor);
void heapRetira (Heap *raiz);
void heapImprime (Heap *raiz, int indice);
void heapBusca (Heap *raiz, int valorProcurado);