#include <stdio.h>
#include <stdlib.h>

// 1.) Написать программу, которая определяет, является ли введенная скобочная
// последовательность правильной. Примеры правильных скобочных
// выражений: (), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}),
// ([(]) для скобок вида [],(),{}. Входные данные: Указатель на массив char.
// Выходные данные: bool. True, если скобочная последовательность правильная,
// False если неправильная. Примеры:
// (2+(2*2)) - true
// {2/{5*(4+7)] - false
#define T char
#define true 1 == 1
#define false 1 != 1
typedef int boolean;

typedef struct NodeOne{
    T data;
    struct NodeOne* next;
} NodeOne;

typedef struct{
    NodeOne* head;
    int size;
} StackOne;

void initStack(StackOne* stack){
    stack -> head = NULL;
    stack -> size = 0;
}

boolean push(StackOne* stack, T value){
    NodeOne* new = (NodeOne*) malloc(sizeof(NodeOne));
    if(new == NULL){
        printf("Stack overflow\n");

        return false;
    }
    new -> data = value;
    new -> next = stack -> head;

    stack -> head = new;
    stack -> size++;

    return true;
}

T pop(StackOne* stack){
    if(stack -> size == NULL){
        printf("Stack is empty");

        return -1;
    }

    NodeOne* temp = stack -> head;
    T data = stack -> head -> data;
    stack -> head = stack -> head -> next;

    free(temp);
    stack -> size--;

    return data;
}

boolean isClosedBrackets(char bracket){
    if(bracket == ')'){
        return true;
    }
    if(bracket == ']'){
        return true;
    }
    if(bracket == '}'){
        return true;
    }
    else{
        return false;
    }
}

boolean checkBrackets(char* arr){
    StackOne* s = (StackOne*) malloc(sizeof(StackOne));
    initStack(s);

    for(int i = 0; *(arr + i) != '\0'; i++){
        printf("%c\n", *(arr + i));

        if(isClosedBrackets(*(arr + i))){
            printf("%c\n", s -> head -> data);

            if(*(arr + i) == s -> head -> data){
                printf("delete %c", pop(s));
            }
        }
        else{
            push(s, *(arr + i));
        }
    }
    if(s -> head == NULL){
        return true;
    }
    else{
        return false;
    }
}

void taskOne(){
    T brackets[100] = {"([])()"};
    char *ptr = brackets;

    if(checkBrackets(ptr)){
        printf("Bracket sequence is correct\n");
    }
    else{
        printf("Bracket sequence is not correct\n");
    }
}


//  2.) Создать функцию, копирующую односвязный список (без удаления первого списка).
//      Входные данные: OneLinkList* from - начало списка с которого производится копирование, OneLinkList* to - начало списка в которое производится копирование
//      Выходные данные: void

typedef struct NodeTaskTwo{
    int data;
    struct NodeTaskTwo* next;
} NodeTaskTwo;

typedef struct{
    NodeTaskTwo* head;
    int size;
} ListTaskTwo;

void initList(ListTaskTwo* list){
    list -> head = NULL;
    list -> size = 0;
}

void insertList(ListTaskTwo* list, int data){
    NodeTaskTwo* new = (NodeTaskTwo*) malloc(sizeof(NodeTaskTwo));
    new -> data = data;
    new -> next = NULL;

    NodeTaskTwo* current = list -> head;
    if(current == NULL){
        list -> head = new;
        list -> size++;
    }
    else{
        while(current -> next != NULL){
            current = current -> next;
        }
        current -> next = new;
        list -> size++;
    }
}

void duplicateList(ListTaskTwo* listOne, ListTaskTwo* listTwo){
    NodeTaskTwo* current = listOne -> head;
    if(current == NULL){
        printf("ListTaskTwo one is empty\n");

        return;
    }
    if(listTwo -> head != NULL){
        printf("ListTaskTwo two is not empty\n");

        return;
    }

    while(current != NULL){
        insertList(listTwo, current -> data);
        current = current -> next;
    }
}

void printNode(NodeTaskTwo* n){
    if(n == NULL){
        printf("[]");

        return;
    }

    printf("[%d] ", n -> data);
}

void printList(ListTaskTwo* list){
    NodeTaskTwo* current = list -> head;

    if(current == NULL){
        printNode(current);
    }
    else{
        do{
            printNode(current);
            current = current -> next;
        } while(current != NULL);
    }

    printf("Size: %d \n", list -> size);
}

void taskTwo(){
    ListTaskTwo* listOne = (ListTaskTwo*) malloc(sizeof(ListTaskTwo));
    ListTaskTwo* listTwo = (ListTaskTwo*) malloc(sizeof(ListTaskTwo));

    initList(listOne);
    initList(listTwo);

    insertList(listOne, 1);
    insertList(listOne, 10);
    insertList(listOne, 13);
    insertList(listOne, 35);
    insertList(listOne, 5);
    insertList(listOne, 7);

    printList(listOne);
    printList(listTwo);

    duplicateList(listOne, listTwo);
    printList(listOne);
    printList(listTwo);
}

// 3.) Реализуйте алгоритм, который определяет, отсортирован ли связный список.
//     Входные данные: OneLinkList* lst - начало списка с которого производится проверка отсортированности
//     Выходные данные: Bool
#define true 1 == 1
#define false 1 != 1
typedef int boolean;

typedef struct NodeTaskThree{
    int data;
    struct NodeTaskThree* next;
} NodeTaskThree;

typedef struct{
    NodeTaskThree* head;
    int size;
} ListTaskThree;

void initListThree(ListTaskThree* list){
    list -> head = NULL;
    list -> size = 0;
}

void insertListThree(ListTaskThree* list, int data){
    NodeTaskThree * new = (NodeTaskThree*) malloc(sizeof(NodeTaskThree));
    new -> data = data;
    new -> next = NULL;

    NodeTaskThree* current = list -> head;
    if(current == NULL){
        list -> head = new;
        list -> size++;
    }
    else{
        while(current -> next != NULL){
            current = current -> next;
        }
        current -> next = new;
        list -> size++;
    }
}

boolean checkListThreeSort(ListTaskThree* list){
    NodeTaskThree* current = list -> head;
    boolean check = false;

    if(list -> head == NULL ){
        printf("List is empty\n");

        return check;
    }

    if(list -> size < 2){
        printf("List have one element\n");

        return check;
    }
    else{
        while (current -> next != NULL){
            if(current -> data <= current -> next -> data){
                check = true;
            }
            else{
                check = false;
            }

            current = current -> next;
        }
    }

    return check;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortListThree(ListTaskThree* list){
    NodeTaskThree* currentUpper = list -> head;
    NodeTaskThree* currentDowner = list -> head;

    while(currentUpper != NULL){
        while(currentDowner -> next != NULL){
            if((currentDowner -> data) >= (currentDowner -> next -> data)){
                swap(&currentDowner -> data, &currentDowner -> next -> data);
            }
            currentDowner = currentDowner -> next;
        }
        currentUpper = currentUpper -> next;
        currentDowner = list -> head;
    }
}

void printNodeThree(NodeTaskThree* node) {
    if(node == NULL){
        printf("[]");

        return;
    }

    printf("[%d]", node -> data);
}

void printListThree(ListTaskThree* list){
    NodeTaskThree* current = list -> head;

    if(current == NULL){
        printNodeThree(current);
    }
    else{
        do{
            printNodeThree(current);
            current = current -> next;
        } while(current != 0);
    }

    printf(" Size: %d \n", list -> size);
}

void taskThree(){
    ListTaskThree* list = (ListTaskThree*) malloc(sizeof(ListTaskThree));

    initListThree(list);
    insertListThree(list, 3);
    insertListThree(list, 7);
    insertListThree(list, 15);
    insertListThree(list, 6);
    insertListThree(list, 21);
    insertListThree(list, 21);
    insertListThree(list, 3);
    printListThree(list);

    if(checkListThreeSort(list)){
        printf("List is sort\n");
    }
    else{
        printf("List is not sort\n");
    }

    sortListThree(list);
    printListThree(list);
    if(checkListThreeSort(list)){
        printf("List is sort\n");
    }
    else{
        printf("List is not sort\n");
    }
}


int main(int argc, char** argv){
    printf("Task One\n");
    taskOne();
    printf("Task two\n");
    taskTwo();
    printf("Task three\n");
    taskThree();

    return 0;
}