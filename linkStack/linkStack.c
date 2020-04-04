#include "linkStack.h"
#include <stdlib.h>
#define NULL 0

Status initLStack(LinkStack* s) {

	s->top = (LinkStackPtr)malloc(sizeof(StackNode));	
	if (!s->top) return ERROR;
	s->top = NULL;
	s->count = 0;		
	return SUCCESS;

}

Status isEmptyLStack(LinkStack* s) {

	if (s->count == 0) return SUCCESS;
	return ERROR;

}

Status getTopLStack(LinkStack* s, ElemType* e) {

	if (!isEmptyLStack(&s)) {
		*e = s->top->data;
		return SUCCESS;
	}
	return ERROR;

}

Status clearLStack(LinkStack* s) {

	if (!s->top) {

		LinkStackPtr now = s->top;

		while (now) {
			s->top = s->top->next;
			free(now);
			now = s->top;
		}

		s->top = NULL;
		s->count = 0;
		return SUCCESS;
	}
	
	return ERROR;
}

Status destroyLStack(LinkStack* s) {

	if (!s->top) {

		LinkStackPtr now = s->top;

		while (now) {
			s->top = s->top->next;
			free(now);
			now = s->top;
		}

		s->count = 0;
		return SUCCESS;
	}
	return ERROR;
}

Status LStackLength(LinkStack* s, int* length) {

	if (s->top) {
		*length = s->count;
		return SUCCESS;
	}

	return ERROR;
}

Status pushLStack(LinkStack* s, ElemType data) {

	LinkStackPtr now = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!now) return ERROR;

	now->data = data;
	now->next = s->top;
	s->top = now;
	s->count++;
	return SUCCESS;

}

Status popLStack(LinkStack* s, ElemType* data) {

	LinkStackPtr now = s->top;

	if (now) {
		*data = now->data;
		s->top = now->next;
		free(now);
		s->count--;
		return SUCCESS;
	}

	return ERROR;
}