//
// Created by simao on 24/10/2019.
//

#ifndef ED2_MIN_HEAP_H
#define ED2_MIN_HEAP_H

//
// Created by simao on 24/10/2019.
//

#include <stdio.h>
#include <stdlib.h>

int pai (int i) {
    return (i - 1)/2;
}

int esquerda (int i) {
    return (i * 2) + 1;
}

int direita (int i) {
    return (i * 2) + 2;
}

void trocar (int V[], int a, int b) {
    int aux = V[a];
    V[a] = V[b];
    V[b] = aux;
}

void imprimir (int V[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
}


void min_heapify (int V[], int size, int i) {
    int e = esquerda (i);
    int d = direita (i);
    int menor;
    if ( (e < size) && (V[e] < V[i]) ) {
        menor = e;
    }
    else {
        menor = i;
    }
    if ( (d < size) && (V[d] < V[menor]) ) {
        menor = d;
    }
    if (menor != i) {
        trocar (V, i, menor);
        min_heapify (V, size, menor);
    }
}

void build_min_heap (int V[], int size) {
    int i;
    for( i= (size/2)-1 ; i >= 0 ; i--){
        min_heapify(V,size,i);
    }
}

void heap_decrease_key (int v[], int i, int chave, int size) {
    if (chave > v[i]){
        printf("erro");
        return;
    }
    v[i] = chave;
    while((i>0)&& v[pai(i)]> v[i]) {
        trocar(v,i,pai(i));
        i=pai(i);
    }
}
int heap_minimum(int v[]){
    return v[0];
}


int heap_extract_min(int v[], int size){
    if(size < 1){
        printf("heap underflow");
    }
    int min = heap_minimum(v);
    v[0] = v[size-1];
    size--;
    min_heapify(v,size,0);
    return min;
}

void min_heap_insert(int v[],int size,int chave){
    size = size+1;
    v[size-1] = 99999;
    heap_decrease_key(v,size-1,chave,size);

}

int main () {

    int size = 10;

    int v[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

    imprimir (v, size);

    build_min_heap(v,size);

    printf ("After build_min_heap: \n");

    imprimir (v, size);

    heap_extract_min(v,size);
    size--;
    printf ("After heap_extract min: \n");
    imprimir (v, size);

    heap_decrease_key(v,size-1,1,size);
    printf("after heap_decrease_key\n");
    imprimir (v, size);

    min_heap_insert(v,size,0);
    printf("after min_heap_insert\n");
    size++;
    imprimir(v,size);
    return 0;
}



#endif //ED2_MIN_HEAP_H
