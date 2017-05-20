#include <stdio.h>
#include <stdlib.h>
#include "func_h.h"
#include <thr\threads.h>
#include <stddef.h>

int divi(int number, int divisor);

#define RUN 1
#define nl printf("\n")

#define TESTDEFF

void main(void) {
	if (!RUN) {
		int i = 5;
		i = i++;
		printf("i = i++ : %d\n", i);

		i = 5;
		i = ++i;
		printf("i = ++i : %d\n", i);

		i = 5;
		i = i++ + i++;
		printf("i = i++ + i++ : %d\n", i);

		i = 5;
		i = ++i + i++;
		printf("i = ++i + i++ : %d\n", i);

		i = 5;
		i = ++i + ++i;
		printf("i = ++i + ++i : %d\n", i);

		i = 5;
		i = (i += 1) + (i += 1);
		printf("i = (i+=1) + (i+=1) : %d\n", i);

		i = 5;
		i++;
		i++;
		i = i + i;
		printf("i = 5; i++; i++; i = i + i; : %d\n", i); // Ебать мой мозг... Дважды...
	}
	if (!RUN) {
		int num;
		scanf_s("%d", &num);
		int div;
		scanf_s("%d", &div);

		printf("%d\n", divi(num, div));
	}

	if (!RUN) {

		printf("char*\t: %zd\n", sizeof(char*));
		printf("void*\t: %zd\n", sizeof(void*));
		printf("char\t: %zd\n", sizeof(char));
		printf("wchar_t\t: %zd\n", sizeof(wchar_t));
		printf("size_t\t: %zd\n", sizeof(size_t));
		printf("int\t: %zd\n", sizeof(int));
		printf("short int\t: %zd\n", sizeof(short int));
		printf("long\t: %zd\n", sizeof(long));
		printf("long long\t: %zd\n", sizeof(long long));
		printf("float\t: %zd\n", sizeof(float));
		printf("double\t: %zd\n", sizeof(double));
		printf("NULL\t: %zd\n", NULL);
		int inull = NULL;
		printf("inull\t: %zd\n", inull); nl;
		system("pause");
	}

	if (!RUN) {
		struct human iams = {
			.human_construct = human_construct,
			.human_getname = human_getname,
			.human_setname = human_setname,
		};

		iams.human_construct(&iams);
		iams.human_setname(&iams, "Dimasik\n");
		struct errstruct merr;
		errstruct_construct(&merr);
		merr = iams.human_getname(&iams);
		printf("%s : %d\n", merr.message, merr.errnum);
		merr = human_testerrret();
		printf("%s : %d\n", merr.message, merr.errnum);
		system("pause");
	}

	if (!RUN) {
		char *p1 = (char*)0x1000;
		printf("%d\n", p1);
		system("pause");
		*p1 = '1';
	}

	if (!RUN) {
		enum MyEnumTest
		{
			ZERO = 0,
			ONE = 1,
			TWO = 2
		} entest;

		entest = TWO;
		printf("%d\n", entest);

	}

	if (!RUN) {

		//printf("%d", TESTDEFF); nl; // Не работает.

	}

	if (RUN) {

		int testarr1[][4] = { { 1, 2, 3, 11 },{ 9, 8, 7, 70 } };
		for (int i = 0; i < 8; i++)
			printf("%d : ", *(testarr1 + i)); // ???
			// printf("%d : ", **(testarr1 + i)); // ???
			// printf("%d : ", *((int*)testarr1 + i)); // ???!!!
		nl;

		int testarr2[][5] = { {1, 2, 3, 11, 12}, {9, 8, 7, 70, 80} };
		for (int i = 0; i < 10; i++)
			printf("%d : ", *(testarr2 + i)); // ???
			// printf("%d : ", **(testarr2 + i)); // ???
			// printf("%d : ", *((int*)testarr2 + i)); // ???!!!
		nl;

		int testarr3[][3] = { {10, 11, 12}, {50, 60, 70} };
		for (int i = 0; i < 2; i++) {
			nl;
			for (int k = 0; k < 3; k++)
				printf("%d\t", &(testarr3[i][k]));
		}
		nl;

		system("pause");
	}

	//system("pause");

}

// Рекурсивное нахождение остатка от деления по модулю.
int divi(int number, int divisor) {
	int result = number;
	if (number >= divisor) {
		number -= divisor;
		result = divi(number, divisor);
	}
	return result;
}


