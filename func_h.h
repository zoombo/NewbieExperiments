#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errstruct.h"

void human_construct(struct human* this_s);
void human_setname(struct human* this_s, char *hname);
struct errstruct human_getname(struct human* this_s);

struct human {
	char *name;
	int age;
	void(*human_construct)(struct human* this_s);
	void(*human_setname)(struct human* this_s, char *hname);
	struct errstruct(*human_getname)(struct human* this_s);
};

void human_construct(struct human* this_s) {
	this_s->name = NULL;
	this_s->age = 0;
}

void human_setname(struct human* this_s, char *hname) {
	this_s->name = (char*)calloc(strlen(hname)+1, sizeof(char));
	//strcpy(this_s->name, hname);
	strcpy_s(this_s->name, strlen(hname)+1, hname);
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
	return iserr;
}


