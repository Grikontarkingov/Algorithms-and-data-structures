#include <stdio.h>
#include <stdlib.h>
#define N 6
#define true 1 == 1
#define false 1 != 1
typedef int boolean;

// 1.) Реализовать обход графа в глубину с использованием стека
// void depthTraversStack(int** matrix, int size)

int get2dInt(int** array, const int row, const int col) {
    return *((*(array + row)) + col);

}

void set2dInt(int** array, const int row, const int col, int value) {
    *((*(array + row)) + col) = value;
}

void print2dIntArray(int** array, const int row, const int col, int offset) {
    char format[7];
    sprintf(format, "%%%dd", offset);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf(format, get2dInt(array, i, j));
        }
        printf("\n");
    }
}

int** init2dIntArray(int** array, const int row, const int col) {
    array = (int**) calloc(sizeof(int*), row);
    for (int i = 0; i < row; ++i) {
        *(array + i) = (int*) calloc(sizeof(int), col);
    }
    return array;
}

void free2dIntArray(int** array, const int row, const int col) {
    for (int i = 0; i < row; ++i) {
        free(array[i]);
    }
    free(array);
}

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct{
    Node* head;
    int size;
} Stack;

void initStack(Stack* stack){
    stack-> head = NULL;
    stack->size = 0;
}

boolean pushStack(Stack* stack, int data){
    Node* temp = (Node*) malloc(sizeof (Node));
    if(temp == NULL){
        printf("Stack overflow\n");

        return false;
    }

    temp->data = data;
    temp->next = stack->head;

    stack->head = temp;
    stack->size++;

    return true;
}

int popStack(Stack* stack){
    if(stack->size == 0){
        printf("Stack is empty\n");

        return 0;
    }

    Node* temp = stack->head;
    int data = stack->head->data;
    stack->head = stack->head->next;

    free(temp);
    stack->size--;

    return data;
}

void depthTraversStack(int** matrix, int size, int st){
    Stack* stack = (Stack*) malloc(sizeof (Stack));
    initStack(stack);

    int visited[N] = {0};
    pushStack(stack, st);

    while (stack->size > 0){
        int index = popStack(stack);
        if(visited[index] == 1){
            continue;
        }

        printf("%d ", index);
        visited[index] = 1;

        for(int i = N - 1; i >= 0; --i) {
            if (get2dInt(matrix, index, i) == 1 && !visited[i]) {
                pushStack(stack, i);
            }
        }
    }

    free(stack);
}

void taskOne(){
    int** matrix = NULL;
    matrix = init2dIntArray(matrix, N, N);
    set2dInt(matrix, 0, 1, 1);
    set2dInt(matrix, 0, 2, 1);
    set2dInt(matrix, 1, 3, 1);
    set2dInt(matrix, 1, 4, 1);
    set2dInt(matrix, 1, 5, 1);
    set2dInt(matrix, 2, 5, 1);
    set2dInt(matrix, 3, 0, 1);
    set2dInt(matrix, 5, 4, 1);

    depthTraversStack(matrix, N * N, 0);
    printf("\n");
    depthTraversStack(matrix, N * N, 3);
    printf("\n");
    depthTraversStack(matrix, N * N, 1);
    printf("\n");
}

int main(const int argc, const char** argv){
    taskOne();

    return 0;
}