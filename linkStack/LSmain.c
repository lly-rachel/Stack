#include "linkStack.h"
#include <stdlib.h>
#include <stdio.h>

int main() {

	int choice, length, i;
	LinkStack S;

	ElemType e;

	printf("\n\t********************MENU********************\n");
	printf("\t\t1--Initialize LinkStack\n");
	printf("\t\t2--Destroy\n");
	printf("\t\t3--Clear\n");
	printf("\t\t4--Gettop\n");
	printf("\t\t5--IsEmpty\n");
	printf("\t\t6--pop\n");
	printf("\t\t7--push\n");
	printf("\t\t8--LinkStackLength\n");
	printf("\t\t9--Exit\n");
	printf("\t********************************************\n");

loop:

	printf("\nYour choice:");
	scanf("%d", &choice);

	switch (choice) {
	case 1:
	
		if (initLStack(&S)) {
			printf("success\n");
		}
		else {
			printf("failed\n");
		}
		break;

	case 2:

		destroyLStack(&S);
		printf("Stack already destoryed\n");
		break;

	case 3:

		clearLStack(&S);
		printf("Stack already cleared\n");
		break;

	case 4:

		if (getTopLStack(&S, &e)) {
			printf("top is -->%d\n", e);
		}
		else {
			printf("failed\n");
		}

		break;

	case 5:

		if (isEmptyLStack(&S)) {
			printf("The stack is empty\n");
		}

		break;


	case 6:

		if (popLStack(&S, &e)) {
			printf("pop -->%d\n", e);
		}
		else {
			printf("failed\n");
		}

		break;

	case 7:

		printf("enter which data you want to push:");
		scanf("%d", &e);
		if (pushLStack(&S, e)) {
			printf("push -->%d\n", e);
		}
		else {
			printf("failed\n");
		}
		break;

	case 8:

		if (LStackLength(&S, &length)) {
			printf("stackLength is %d\n", length);
		}
		else {
			printf("failed\n");
		}
		break;

	case 9:

		return 0;

	default:printf("data error!\n");
	}

	do {
		printf("\ncontinue to use the menu or stop(enter 1 or 0):");
		scanf("%d", &i);
		if (i == 1) goto loop;
		if (i != 1 && i != 0) printf("data error!");
	} while (i != 1 && i != 0);

	return 0;
}