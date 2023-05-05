#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void Merge(int *A, int p, int q, int r){
    // Defensive programing

    assert(A != NULL && p >= 0 && q >= 0 && r >=0);

    int size1 = q-p+1; // inclure le dernier élément
    int size2 = r-q;

    int *A1 = malloc(sizeof(int)*size1);
    int *A2 = malloc(sizeof(int)*size2);

    if (A1 == NULL || A2 == NULL)
        abort();

    for(int i = 0; i<size1; i++){
        A1[i] = A[p+i];
    }

    for(int i = 0; i<size2; i++){
        A2[i] = A[q+i+1]; // exclure le premier élément
    }

    int i=p, j=0, k=0; // initialisez i à p
    for(; j<size1 && k<size2; i++){ // continuez tant que les deux tableaux ont des éléments
        if (A1[j] <= A2[k])
        {
           A[i] = A1[j];
           j++;
        }
        else{
            A[i] = A2[k];
            k++;
        }
    }

    // copiez les éléments restants de A1 dans A
    for(; j<size1; i++, j++){
        A[i] = A1[j];
    }

    // copiez les éléments restants de A2 dans A
    for(; k<size2; i++, k++){
        A[i] = A2[k];
    }
    
}



void MergeSort(int *A, int p, int r){
    // Defensive programing 

    assert(A != NULL && p>=0 && r>=0);

    if (p < r)
    {
        int q = (p+r)/2;
        MergeSort(A, p, q);
        MergeSort(A, q+1, r);
        Merge(A, p, q, r);
    }
}


int main(int argc, char const *argv[])
{
    /*
    * Getting a random size of the array 
    */

    int N =  9; // rand() is random function, it exists in stdlib

    int *Array = malloc(sizeof(int)*N); // allocate an array of size N

    /*
    * Chek if the allocation is done successfully
    */

    if (Array == NULL){
        printf("No memory space !");
        exit(0);
    }

    /*
    * Filling the array randomly
    */
    for(int i = 0; i < N; i++){
        Array[i] = rand()%100;
    }

    /*
    * Call Merge sort procudure 
    */

    printf("A ----------- \n");
    for(int i=0; i<N; i++){
        printf("%d ",Array[i]);
    }

    printf("\n");
    MergeSort(Array, 0, N-1);
//    MergeSort(Array, 0, N-1);


    printf("\nA ----------- \n");
    for(int i=0; i<N; i++){
        printf("%d ",Array[i]);
    }

    return 0;
}
