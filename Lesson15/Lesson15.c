#include <stdio.h>
#include <stdlib.h>

//  1.) Реализовать простейшую хеш-функцию. На вход функции подается строка, на выходе сумма кодов
//  символов. int simpleHashSum(char* in)

void printString(char* arr){
    for(int i = 0; arr[i] != '\0'; ++i){
        printf("%c", arr[i]);
    }

    printf("\n");
}

int simpleHashSum(char *in){
    int hashSum = 0;
    for(int i = 0; in[i] != '\0'; ++i){
        hashSum += in[i];
    }

    return hashSum;
}

void taskOne(){
    char string[] = "Hello world!";
    printString(string);
    printf("Hash is %d", simpleHashSum(string));
}

//  2.) Имеются монеты номиналом 50, 10, 5, 2, 1 коп. Напишите функцию которая минимальным количеством
//  монет наберет сумму 98 коп. Для решения задачи используйте “жадный” алгоритм.
//  int* exchange(int* money, int size, int sum). Входные параметры: int* money - Массив с доступными
//  номиналами монет размером size. Например: int money[] = {50, 10, 5, 2, 1};, size = 5. Выходные параметры:
//  Можно просто вывести необходимые монеты в консоль, либо вернуть указатель int* на массив, в котором первый
//  элемент будет хранить его размер. Считается что монет каждого номинала у нас неограниченное количество.
void clearIntArr(int* arr, const int size){
    for(int i = 0; i < size; ++i){
        arr[i] = 0;
    }
}

void printIntArray(int* array, int size, int offset) {
    char format[7];
    sprintf(format, "%%%dd", offset);
    for (int i = 0; i < size; ++i) {
        printf(format, array[i]);
        if (i != size - 1)
            printf(",");
    }
    printf("\n");
}

int* exchange(int* money, int size, int sum){
    int *out = (int *) calloc(size, sizeof(int));

    int tempSum = 0;
    for(int i = 0; i < size; ++i){
        while(tempSum + money[i] <= sum){
            tempSum += money[i];
            *(out + i) += 1;
        }
    }

    return out;
}

void taskTwo(){
    const int SIZECOINS = 5;
    const int SUM = 98;
    int arrCoins[] = {50, 10, 5, 2, 1};
    int *arrNumOfCoins = exchange(arrCoins, SIZECOINS, SUM);
    printIntArray(arrCoins, SIZECOINS, 3);
    printIntArray(arrNumOfCoins, SIZECOINS, 3);
    free(arrNumOfCoins);
}

int main(const int argc, const char** argv){
    printf("TaskOne:\n");
    taskOne();
    printf("\n");
    printf("TaskTwo:\n");
    taskTwo();

    return 0;
}