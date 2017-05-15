#pragma once
#include <stdio.h>

struct errstruct {
	int errnum;
	char *message;
};

void errstruct_construct(struct errstruct *this_s) {
	this_s->errnum = 0;
	this_s->message = NULL;
}

//
//int errstruct_geterror(struct errstruct* this_s) {
//	return this_s->errnum;
//}
//
//int errstruct_showmsg(struct errstruct* this_s) {
//	printf("%s");
//}

