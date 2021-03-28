#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1.) Описать очередь с приоритетным исключением
#define SIZE 10

// Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.
#define T int
#define true 1 == 1
#define false 1 != 1
#define SIZEBINARY 64


//1.) Описать очередь с приоритетным исключением
typedef struct{
	int pr;
	int data;
} Node;

Node* arr[SIZE];
int head;
int tail;
int items;

void init(){
	for(int i = 0; i < SIZE; i++){
		arr[i] = NULL;
	}

	head = 0;
	tail = 0;
	items = 0;
}

Node* findMax(){
	Node* temp = arr[head];
	for(int i = 1; i < tail; i++){
		if((arr[i] -> pr) > (temp -> pr)){
			temp = arr[i];
		}
	}

	return temp;
}

void insert(int pr, int data){
	Node* node = (Node*) malloc(sizeof(Node));
	node -> pr = pr;
	node -> data = data;

	if(items == SIZE){
		printf("Queue is full\n");
		free(node);
	}
	else{
		arr[tail++] = node;
		items++;
	}
}

void rem(){
	Node* temp;
	int i = 0;
	int index = 0;

	if(items == 0){
		printf("Queue is empty\n");
	}
	else{
		Node* max = findMax();;

		for(i = head; i < tail; i++){
			index = i % SIZE;

			if(arr[index] -> pr == max -> pr){
				temp = arr[index];
				arr[index] = NULL;
				tail--;
				items--;

				while(index < SIZE - 1){
					arr[index] = arr[index + 1];
					index++;
					if(index == tail){
						arr[index] = NULL;
					}
				}

				i--;

				printf("pr= %d, data= %d\n", temp -> pr, temp -> data);
			}
		}
	}
}

void printQueue(){
	printf("[ ");

	for(int i = 0; i < SIZE; i++){
		if(arr[i] == NULL){
			printf("[*, *] ");
		}
		else{
			printf("[%d, %d] ", arr[i] -> pr, arr[i] -> data);
		}
	}

	printf("\n");
}

void taskOne(){
	init();
	insert(1, 11);
	insert(3, 22);
	insert(4, 33);
	insert(2, 44);
	insert(3, 55);
	insert(4, 66);
	insert(5, 77);
	insert(1, 88);
	insert(2, 99);
	insert(6, 100);
	printQueue();

	for(int i = 0; i < 3; i++){
		rem();
	}
	printQueue();

	insert(8, 123);
	insert(9, 321);
	insert(9, 222);
	insert(9, 333);
	printQueue();

	rem();
	printQueue();
}

// Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.

typedef int boolean;

int cursor = -1;
T Stack[SIZE];

void convIntToChar(char* result, T number){
	char binTemp[SIZEBINARY];
	int i = 0, temp = number;

	while(temp != 0){
		temp = temp >> 1;
		i++;
	}

	binTemp[i] = '\0';

	while(number > 0){
		binTemp[--i] = (number % 2) ? '1' : '0';
		number /= 2;
	}

	strcat(result, binTemp);
}

boolean pushStack(T data){
	if(cursor < SIZE){
		Stack[++cursor] = data;

		return true;
	}
	else{
		printf("Stack overflow\n");

		return false;
	}
}

void popStack(){
	if(cursor != -1){
		char binary[SIZEBINARY] = {};
		convIntToChar(binary, Stack[cursor]);

		printf("%2d - %s\n", Stack[cursor], binary);

		cursor--;
	}
	else{
		printf("Stack is empty\n");
	}
}

void taskTwo(){
	pushStack(1);
	pushStack(2);
	pushStack(12);
	pushStack(21);
	pushStack(35);
	pushStack(25);
	pushStack(15);

	while(cursor != -1){
		popStack();
	}

	printf("\n");
}

int main(int argc, char** argv){
	taskOne();
	taskTwo();

	return 0;
}