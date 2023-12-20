#include "Stack.h"

ArrStack* creatArrStack() {
	ArrStack* stackhead = (ArrStack*)malloc(sizeof(ArrStack));
	if (!stackhead) {
		fprintf(stderr, "malloc stackhead error!\n");
		return NULL;
	}
	stackhead->data = (Element*)malloc(sizeof(Element) * MAX_SIZE);
	if (!stackhead->data) {
		fprintf(stderr, "malloc data error!\n");
		return NULL;
	}
	stackhead->top = -1;
	return stackhead;
}

void releasesArrStack(ArrStack *stack) {
	if (stack) {
		if (stack->data) {
			free(stack->data);
		}
		free(stack);
	}
}

int insertArrStack(ArrStack *stack, Element val) {
	if (stack->top < MAX_SIZE - 1) {
		stack->data[++stack->top] = val;
		return 0;
	} else {
		fprintf(stderr, "Stack overflow!\n");
		return -1;
	}
}

void showArrStack(ArrStack *stack) {
	printf("[");
	for (int i = 0; i <= stack->top; i++) {
		printf("%d", stack->data[i]);
		if (i != stack->top)
			printf(", ");
	}
	printf("]\n");
}

/*---------------------------------------*/


LinkStack* creatLinkStack() {
	LinkStack *stack = (LinkStack *)malloc(sizeof(LinkStack));
	if (!stack) { 
		fprintf(stderr, "malloc stack failed!\n");
		return NULL;
	}

	stack->num = 0;
	stack->top = NULL;	//	一定要等于Null
	return stack;
}

void releaseLinkStack(LinkStack* stack) {
	if (stack) {
		while (stack->top) {
			//遍历栈中所有，全部释放
			Node *tmp = stack->top;
			stack->top = tmp->next;
			free(tmp);
			stack->num--;
		}
		printf("stack node: %d\n", stack->num);
		free(stack);
	}
}

int insertLinkStack(LinkStack *stack, Element val) {
	Node *node = (Node *)malloc(sizeof(Node));
	if (!node) {
		fprintf(stderr, "malloc node failed!\n");
		return NULL;
	}
	node->data = val;
	node->next = stack->top;
	stack->top = node;
	stack->num++;
	return 0;
}

int popLinkStack(LinkStack *stack, Element *retval) {
	if (stack->top == NULL) {
		printf("No stack node!\n");
		return -1;
	}
	*retval = stack->top->data;
	//在这一步已经有一个指针指向data，所以不用再return
	/*
	Element e;
		if (popLinkStack(stack, &e) == 0) {
		// 在这里使用 e，它现在包含了被弹出的栈顶元素的值
		}
	调用时就这么调用*/

	Node *tmp = stack->top;
	stack->top = tmp->next;
	free(tmp);
	stack->num--;
	return 0;
}

void showLinkStack(LinkStack *stack) {
	printf("[");
	Node *tmp = stack->top;
	while (tmp != NULL) {
		printf("%d", tmp->data);
		tmp = tmp->next;
		if (tmp != NULL) {
			printf(", ");
		}
	}
	printf("]\n");
}

