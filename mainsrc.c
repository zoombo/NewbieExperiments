#include <stdio.h>
#include <stdlib.h>
#include "func_h.h"
#include <thr\threads.h> // Я его нашел :)))
#include <stddef.h>

int divi(int number, int divisor);

#define RUN 1

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
		printf("i = 5; i++; i++; i = i + i; : %d\n", i); // ≈бать мой мозг... ƒважды...
	}
	if (!RUN) {
		int num;
		scanf_s("%d", &num);
		int div;
		scanf_s("%d", &div);

		printf("%d\n", divi(num, div));
	}

	if (RUN) {
		struct human iams;
		{
			iams.human_construct = human_construct;
			iams.human_getname = human_getname;
			iams.human_setname = human_setname;
		}
		iams.human_construct(&iams);
		iams.human_setname(&iams, "Dimasik\n");
		struct errstruct merr;
		errstruct_construct(&merr);
		merr = iams.human_getname(&iams);
		printf("%s : %d\n", merr.message, merr.errnum);
		merr = human_testerrret();
		printf("%s : %d\n", merr.message, merr.errnum);
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

	if (RUN) {

		printf("char*\t: %zd\n", sizeof(char*));
		printf("void*\t: %zd\n", sizeof(void*));
		printf("char\t: %zd\n", sizeof(char));
		printf("wchar_t\t: %zd\n", sizeof(wchar_t));
		printf("size_t\t: %zd\n", sizeof(size_t));
		printf("int\t: %zd\n", sizeof(int));
		printf("long\t: %zd\n", sizeof(long));
		printf("long long\t: %zd\n", sizeof(long long));
		printf("float\t: %zd\n", sizeof(float));
		printf("double\t: %zd\n", sizeof(double));
		printf("NULL\t: %zd\n", NULL);
		int inull = NULL;
		printf("inull\t: %zd\n", inull);
	}

	//system("pause");

}

// –екурсивное нахождение остатка от делени€ по модулю.
int divi(int number, int divisor) {
	int result = number;
	if (number >= divisor) {
		number -= divisor;
		result = divi(number, divisor);
	}
	return result;
}


