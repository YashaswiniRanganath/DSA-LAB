/*
Design and implement a priority queue data structure using a binary heap that supports all the basic operations of a queue, including enqueue dequeue and peek
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

typedef struct MinHeap {
    int arr[MAX_SIZE];
    int size;
} MinHeap;

MinHeap* createMinHeap() {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    return minHeap;
}

void enqueue(MinHeap* minHeap, int value) {
    if (minHeap->size >= MAX_SIZE) {
        return;
    }

    int* arr = minHeap->arr;
    int current = ++minHeap->size;
    arr[current] = value;

    while (current > 1 && arr[current] < arr[current / 2]) {
        swap(&arr[current], &arr[current / 2]);
        current /= 2;
    }
}

int dequeue(MinHeap* minHeap) {
    if (minHeap->size == 0) {
        return -1;
    }

    int* arr = minHeap->arr;
    int front = arr[1];
    arr[1] = arr[minHeap->size--];

    int current = 1;

    while (1) {
        int leftChild = current * 2;
        int rightChild = leftChild + 1;
        int smallest = current;

        if (leftChild <= minHeap->size && arr[leftChild] < arr[smallest]) {
            smallest = leftChild;
        }

        if (rightChild <= minHeap->size && arr[rightChild] < arr[smallest]) {
            smallest = rightChild;
        }

        if (smallest == current) {
            break;
        }

        swap(&arr[current], &arr[smallest]);
        current = smallest;
    }

    return front;
}

int peek(MinHeap* minHeap) {
    if (minHeap->size == 0) {
        return -1;
    }
    return minHeap->arr[1];
}

int main() {
    int capacity, query;
    scanf("%d", &capacity);

    MinHeap* priorityQueue = createMinHeap();

    while (scanf("%d", &query) != EOF) {
        if (query == 1) {
            int element;
            scanf("%d", &element);
            enqueue(priorityQueue, element);
        } else if (query == 2) {
            int front = dequeue(priorityQueue);
            if (front != -1) {
                printf("%d\n", front);
            }
        } else if (query == 3) {
            int front = peek(priorityQueue);
            if (front != -1) {
                printf("%d\n", front);
            }
        }
    }

    free(priorityQueue);

    return 0;
}
