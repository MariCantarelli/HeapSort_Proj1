#include <stdio.h>

// Função para fazer o "Desce-Heap"
void desceHeap(int A[], int n, int i) {
    int f;
    while (2 * i <= n) {
        f = 2 * i;
        if (f < n && A[f + 1] > A[f]) {
            f = f + 1;
        }
        if (A[i] < A[f]) {
            int temp = A[i];
            A[i] = A[f];
            A[f] = temp;
            i = f;
        } else {
            i = n + 1; // sair do loop
        }
    }
}

// Função para construir o heap
void constroiHeap(int A[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        desceHeap(A, n, i);
    }
}

// Heap-Sort
void heapSort(int A[], int n) {
    constroiHeap(A, n);
    for (int i = n; i >= 2; i--) {
        int temp = A[1];
        A[1] = A[i];
        A[i] = temp;
        desceHeap(A, i - 1, 1);
    }
}

// Função para imprimir o vetor
void imprimeVetor(int A[], int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    // Vetor começa no índice 1 para manter o padrão do heap dos slides
    int A[] = {0, 20, 15, 17, -2, 8, 11, 3, 9, 29, 1}; // A[0] é fictício
    int n = 10; // número de elementos reais

    printf("Vetor original:\n");
    imprimeVetor(A, n);

    heapSort(A, n);

    printf("Vetor ordenado com Heap-Sort:\n");
    imprimeVetor(A, n);

    return 0;
}
