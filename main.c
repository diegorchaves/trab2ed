#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

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
