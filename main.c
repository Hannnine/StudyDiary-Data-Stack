#include "Stack.h"

int main() {
	/*ArrStack* stack = creatArrStack();
	insertArrStack(stack, 1);
	showArrStack(stack);

	insertArrStack(stack, 3);
	showArrStack(stack);

	insertArrStack(stack, 4);
	showArrStack(stack);

	insertArrStack(stack, 3);
	showArrStack(stack);

	releasesArrStack(stack);*/

/*-----------------------------*/
	LinkStack *stack = creatLinkStack();
	Element e;

	insertLinkStack(stack, 1);
	showLinkStack(stack);

	insertLinkStack(stack, 3);
	showLinkStack(stack);

	insertLinkStack(stack, 4);
	showLinkStack(stack);

	insertLinkStack(stack, 3);
	showLinkStack(stack);

	popLinkStack(stack, &e);
	printf("e = %d\n", e);
	showLinkStack(stack);

	releaseLinkStack(stack);
	return 0;
}