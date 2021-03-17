#include <stdio.h>


// 1. Реализовать функцию перевода чисел из десятичной системы в двоичную, используя рекурсию.
void ConvertToBinary(int num){
	if(num > 0){
		printf("%d", num % 2);
		ConvertToBinary(num / 2);
	}
}

// 2. Реализовать функцию возведения числа [a] в степень [b]:
double IterPower(int a, int b){
	double res = 1.0;

	if(b == 0){
		return 1;
	}
	else if(b > 0){
		for(int i = 0; i < b; i++){
			res *= a;
		}
	}
	else{
    	for(int i = 0; i < -b; i++){
    		 res *= a;
    	}

    	res = 1 / res;
	}
	

	return res;
}

// 3. Рекурсивно.
double RecursPower(int a, int b){
	double res = a;

	if(b == 0){
		return 1;
	}
	if(b > 0){
		return res *= (RecursPower(a, b - 1));
	}
	if(b < 0){
		res *= RecursPower(a, -b - 1);
	}

	return res = 1 / res;
}

// 4. Рекурсивно, используя свойство чётности степени (то есть, если степень, в которую нужно возвести число, чётная, основание возводится в квадрат, а показатель делится на два, а если степень нечётная - результат умножается на основание, а показатель уменьшается на единицу)
double RecursTaskFour(int a, int b){
	double res;

	if( b % 2 == 0){
		a = RecursPower(a, 2);

		b /= 2;

		res = RecursPower(a,b);

		return res;
	}
	else{
		b--;

		res = RecursPower(a,b);

		return res *= a;
	}
}

// 5. Реализовать нахождение количества маршрутов шахматного короля с препятствиями (где единица - это наличие препятствия, а ноль - свободная для хода клетка). Результатом работы должен стать один файл с кодом на языке С, содержащий функцию main и четыре функции, соответствующие каждому из заданий.

int Routes(int x, int y){
	if(x == 0 && y == 0){
		return 0;
	}
	else if(x == 0 ^ y == 0){
		return 1;
	}
	else{
		return Routes(x, y - 1) + Routes(x - 1, y);
	}
}

int main(int argc, char** argv){
	// 1. Реализовать функцию перевода чисел из десятичной системы в двоичную, используя рекурсию.
	int numDec;

	do{
		printf("Enter the positive integer number: ");
		scanf("%d", &numDec);
	}while(!(numDec > 0));

	printf("Your binary: ");
	ConvertToBinary(numDec);
	printf("\n");

	// 2. Реализовать функцию возведения числа [a] в степень [b]:
	int a, b;
	printf("Enter numbers \"a\" and \"b\" separated by space: ");
	scanf("%d %d", &a, &b);

	printf("Your number: %f\n", IterPower(a, b));
	// 3. Рекурсивно.
	printf("Your number: %f\n", RecursPower(a, b));

	// 4. Рекурсивно, используя свойство чётности степени (то есть, если степень, в которую нужно возвести число, чётная, основание возводится в квадрат, а показатель делится на два, а если степень нечётная - результат умножается на основание, а показатель уменьшается на единицу)
	printf("Your number: %f\n", RecursTaskFour(a, b));

	// 5. Реализовать нахождение количества маршрутов шахматного короля с препятствиями (где единица - это наличие препятствия, а ноль - свободная для хода клетка). Результатом работы должен стать один файл с кодом на языке С, содержащий функцию main и четыре функции, соответствующие каждому из заданий.
	const int sizeX = 5;
	const int sizeY = 5;

	for(int i = 0; i < sizeY; i++){
		for(int j = 0; j < sizeX; j++){
			printf("%5d", Routes(j,i));
		}
		printf("\n");
	}

	return 0;
}