#include <stdio.h>
#include <stdlib.h>

#define PAI(i) ((i-1)/2)
void max_heapify(int *vet, int i, int f)
{
    int aux = vet[i];
    int j = (i * 2) + 1;
    while( j <= f )
    {
        if( j < f )
        {
            if( vet[j] < vet[j + 1] )
            {
                j = j + 1;
            }
        }
        if( aux < vet[j])
        {
            vet[i] = vet[j];
            i = j;
            j = (2 * i) + 1;
        }else
            j = f + 1;
    }
    vet[i] = aux;
}

void heapSort(int *vet, int n)
{
    int i, aux;
    for( i = (n-1)/2; i >= 0; i--)
    {
        max_heapify(vet, i, n-1);
    }
    for( i = n-1; i >= 1; i-- )
    {
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        max_heapify(vet, 0, i-1);
    }
}

void inserir_chave(int *vet,int index, int chave, int *n)
{
    vet[*n] = chave;
    (*n)++;
    max_heapify(vet,index,*n);
    heapSort(vet,*n);
}

int main()
{
    int n = 0;
    int num = 0;
    int tam;
    printf("Digite tamanho vetor: ");
    scanf("%d",&tam);
    int *vet = (int*) malloc((tam) * sizeof(int));


    for(int i=0; i < tam; i++)
    {
        printf("Digite um num: ");
        scanf("%d",&num);
        inserir_chave(vet,i,num,&n);
    }

    printf("\n\nDepois: \n");


    for(int i=0; i < n; i++)
    {
        (i > 0) ? 
         printf("P[%d] index[%d]: (%d) \n", PAI(i),i,vet[i])
        :printf("      Raiz[%d]: (%d) \n", i,vet[i]);
        
    }

    free(vet);
    return 0;
}
