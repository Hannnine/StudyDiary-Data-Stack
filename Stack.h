#include <stdio.h>
#include <stdlib.h>
typedef int Element;
#define MAX_SIZE 10
/*---------------ArrStack--------------*/
//顺序栈头：固定大小
typedef struct {
	Element* data;
	int top;
}ArrStack;

ArrStack* creatArrStack();
void releasesArrStack(ArrStack* stack);

int insertArrStack(ArrStack* stack, Element val);

void showArrStack(ArrStack* stack);


/*---------------LinkStack------------*/

typedef struct _Node {
	Element data;
	struct _Node *next;
}Node;

typedef struct {
	Node *top;	//链式栈，只需要栈顶指针
	int num;	//统计压入了多少个元素
}LinkStack;

LinkStack* creatLinkStack();
void releaseLinkStack(LinkStack *stack);

//insert其实是头插法
int insertLinkStack(LinkStack *stack, Element val);

int popLinkStack(LinkStack *stack, Element *val);

void showLinkStack(LinkStack *stack);