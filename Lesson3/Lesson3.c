#include <stdio.h>

void IsSimpleNumber(int num);

int main(int argc, char** argv){
	int number;

	do{
		printf("Enter the integer number more then two: ");

		scanf("%d", &number);
	}while(!(number > 2));

	IsSimpleNumber(number);

	getchar();

	return 0;
}

void IsSimpleNumber(int num){
	for(int i = 2; i < num; i++){
		if(num % i == 0){
			printf("This number isn't simple!\n");

			return;
		}
	}
	
	printf("This number is simple!\n");
}