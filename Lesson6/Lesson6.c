#include <stdio.h>
#include <math.h>

void print2dArray(int* arr, const int size){
	for(int i = 0; i < size; i++){
		printf("%d", *(arr + i));
	}
	printf("\n");
}

void bubbleSort(int* arr, const int size){
	int temp;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size - 1; j++){
			if(*(arr + j) > *(arr + j + 1)){
				temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
		}
	}
}

void TPKAlgorithm(int* arr, int len){
	float res;

	for(int i = len -1; i >= 0; i--){
		res = sqrt(fabs(arr[i])) + 5 * pow(arr[i], 3);

		if(res > 400){
			printf("Index %d more than 400!\n", i);

		}
		else{
			printf("Index %d = %f\n", i, res);
		}
	}
}

int main(int argc, char** argv){
	int arr[3][3] = {
		{1, 9, 2},
		{5, 7, 6},
		{4, 3, 8}
	};

	int* ptrarr = &arr[0][0];
	const int ARRSIZE = 3 * 3;

	print2dArray(ptrarr, ARRSIZE);
	bubbleSort(ptrarr, ARRSIZE);
	print2dArray(ptrarr, ARRSIZE);

	int arrOne[11]; //{1, 8, 4, 9, 2, 3, 7, 11, 5, 10, 6};

	for(int i = 0; i < 11; i++){
		scanf("%d", &arrOne[i]);
	}

	TPKAlgorithm(arrOne, 11);
}