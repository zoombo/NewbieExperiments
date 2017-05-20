#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errstruct.h"

static void human_construct(struct human* this_s);
void human_setname(struct human* this_s, char *hname);
struct errstruct human_getname(struct human* this_s);

//struct human {
//	char *name;
//	int age;
//	void (*human_construct)(struct human* this_s);
//	void (*human_setname)(struct human* this_s, char *hname);
//	struct errstruct (*human_getname)(struct human* this_s);
//};

struct human {
	char *name;
	int age;
	void(*human_construct)(struct human* this_s);
	void(*human_setname)(struct human* this_s, char *hname);
	struct errstruct(*human_getname)(struct human* this_s);
};

static void human_construct(struct human* this_s) {
	this_s->name = NULL;
	this_s->age = 0;
	printf("Human struct sizeof : %d\n", sizeof *this_s);
}

void human_setname(struct human* this_s, char *hname) {
	this_s->name = (char*)calloc(strlen(hname), sizeof(char));
	strcpy(this_s->name, hname);
}

struct errstruct human_getname(struct human* this_s) {
	struct errstruct errp;
	errstruct_construct(&errp);
	errp.errnum = printf("%s", this_s->name);
	if (errp.errnum < 0)
		return errp;
	errstruct_construct(&errp);
	return errp;
	
}
struct errstruct human_testerrret() {
	struct errstruct iserr;
	errstruct_construct(&iserr);
	iserr.errnum = 105;
	iserr.message = "Aha";
	return iserr; // Да, в вызывающую функцию вернется копия этой структуры с сохраненными значениями полей.
}


