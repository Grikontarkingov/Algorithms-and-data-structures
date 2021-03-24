#include <stdio.h>
#include <stdlib.h>

#define SIZEONE 12

void fillingArray(int* arr, int len, int randUpper);
void printArray(int* arr, int len);
void sortInsert(int* arr, int len);
void swap(int* a, int* b);
int findMedian(int a, int b, int c);
void qs(int* arr, int first, int last);
void improvedSort(int* arr, int first, int last);
void bucketSort(int* arr, int len);


int main(int argc, char** argv){
    /*const int SIZE = 10;
    int arr[SIZE];

    fillingArray(arr, SIZE, 10);
    printArray(arr, SIZE);

    printf("\n");

    improvedSort(arr, 0, SIZE - 1);
    printArray(arr, SIZE);*/

    int arrOne[SIZEONE] = {0, 2, 8, 3, 4, 6, 5, 9, 8, 2, 7, 3};
    printArray(arrOne, SIZEONE);

    printf("\n");

    bucketSort(arrOne, SIZEONE);
    printArray(arrOne, SIZEONE);

    return 0;
}

void fillingArray(int* arr, int len, int border){
    for(int i = 0; i < len; ++i){
        *(arr + i) = rand() % border;
    }
}

void printArray(int* arr, int len){
    for(int i = 0; i < len; ++i){
        if(i == len - 1){
            printf("%2d", arr[i]);
        }
        else{
            printf("%2d, ", arr[i]);
        }
    }
}

void sortInsert(int* arr, int len){
    int temp, pos;

    for(int i = 1; i < len; ++i){
        temp = arr[i];
        pos = i - 1;

        while(pos >= 0 && arr[pos] > temp){
            arr[pos + 1] = arr[pos];
            pos--;
        }

        arr[pos + 1] = temp;
    }
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int findMedian(int a, int b, int c){
    if((a <= b && a >= c) || (a >= b && a <= c)){
        return a;
    }
    else if((b <= a && b >= c) || (b >= a && b <= c)){
        return b;
    }
    else{
        return c;
    }
}

void qs(int* arr, int first, int last){
    int i = first;
    int j = last;

    int x = arr[(first + last) / 2];

    do{
        while(arr[i] < x){
            i++;
        }

        while(arr[j] > x){
            j--;
        }

        if(i <= j){
            swap(&arr[i], &arr[j]);

            i++;
            j--;
        }
    }while(i <= j);

    if(i < last){
        qs(arr, i, last);
    }

    if(first < j){
        qs(arr, first, j);
    }
}

void improvedSort(int* arr, int first, int last){
    int mid = (first + last) / 2;

    if(last + 1 < 11){
        printf("Massive is less than 10\n");
        sortInsert(arr, last + 1);
    }
    else{
        printf("Massive is more than 10\n");

        int median = findMedian(arr[first], arr[mid], arr[last]);

        if(arr[first] == median){
            swap(&arr[first], &arr[mid]);
        }
        if(arr[last] == median){
            swap(&arr[last], &arr[mid]);
        }

        qs(arr, first, last);
    }
}

void bucketSort(int* arr, int len){
    const int max = len;
    const int b = 10;
    int buckets[b][max + 1];

    for(int i = 0; i < b; ++i){
        buckets[i][max] = 0;
    }

    for(int digit = 1; digit < 1000000000; digit *= 10){
        for(int i = 0; i < max; ++i){

            int d = (arr[i] / digit) % b;

            int counter = buckets[d][max];
            buckets[d][counter] = arr[i];
            counter++;
            buckets[d][max] = counter;

            //buckets[d][buckets[d][max]++] = arr[i];
        }

        int index = 0;

        for(int i = 0; i < b; ++i){
            if(arr[i] % 2 != 0){
                index++;
                continue;
            }
            for(int j = 0; j < buckets[i][max]; ++j){
                if(buckets[i][j] % 2 == 0) {
                    arr[index++] = buckets[i][j];
                }
                else{
                    index++;
                }
            }

            buckets[i][max] = 0;
        }
    }
}