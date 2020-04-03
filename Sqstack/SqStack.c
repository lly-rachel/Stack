#include "SqStack.h"
#include <stdlib.h>
#define NULL 0

Status initStack(SqStack* s, int sizes) {

	s->elem = (ElemType*)malloc(sizes*sizeof(ElemType));
	if (s->elem == NULL) return ERROR;

	s->size = sizes;
	s->top = -1;
	return SUCCESS;

}

Status isEmptyStack(SqStack* s) {

	if (s->top == -1) 	return SUCCESS;
	return ERROR;

}

Status getTopStack(SqStack* s, ElemType* e) {

	if (s->elem&&s->top!=-1) {
		*e = s->elem[s->top];
		return SUCCESS;
	}
	
	return ERROR;
}

Status clearStack(SqStack* s) {

	if (isEmptyStack(&s))  return ERROR;
	s->top = -1;
	return SUCCESS;

}

Status destroyStack(SqStack* s) {

	if (s->elem) {
		free(s->elem);
		s->elem = NULL;
	}		
	return SUCCESS;
}

Status stackLength(SqStack* s, int* length) {

	if (s->elem == NULL) {
		printf("The stack didn't initialize");
		return ERROR;
	}
	*length = s->top + 1;
	return SUCCESS;

}

Status pushStack(SqStack* s, ElemType data) {

	if (s->top >= (s->size - 1)||s->elem==NULL) return ERROR;
	
	s->top++;
	s->elem[s->top] = data;

	return SUCCESS;

}

Status popStack(SqStack* s, ElemType* data) {

	if (isEmptyStack(s) || s->elem == NULL)  return ERROR;
	*data = s->elem[s->top];
	s->top--;
	return SUCCESS;

}