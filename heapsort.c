#define PAI(i) ((i-1)/2)		            //Pai de i er i-1 divido por 2
#define F_ESQ(i) (2*i+1)                    //Filho esquerdo de i
#define F_DIR(i) (2*i+2)                    //Filho direito de i


void troca(int *x, int *y)
{
    int z = *x;
    *x = *y;
    *y = z;
}

int irmao(int index, int n)
{
    if(index != n)
    {
        if(index % 2 != 0)
            index = index+1;
    }else 
        if (index % 2 == 0)
        {
            index = index-1;
        }

    return index; 
}

void inserir_chave(int *arr,int index, int chave)
{
    int n;
    if(index == 0)
    {
        arr[index] = chave;
    }
    while(index > 0)
    {
        if( arr[index] >= arr[irmao(index,n)] )
        {
            if( arr[index] > arr[PAI(index)] )
            {
                troca( &arr[index] , &arr[PAI(index)] );
                index = PAI(index);
            } 
        }else 
            if (arr[irmao(index,n)] > arr[PAI(index)])
            {
                troca( &arr[irmao(index,n)], &arr[PAI(index)] );
                index = PAI(index);
            }
                
    }
}


void heap_sort(int *arr)
{
    int n;
    troca( &arr[n], &arr[0]);
    n--;


}