#include <stdio.h>
#include <stdlib.h>
typedef int Element;
#define MAX_SIZE 10
/*---------------ArrStack--------------*/
//˳��ջͷ���̶���С
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
	Node *top;	//��ʽջ��ֻ��Ҫջ��ָ��
	int num;	//ͳ��ѹ���˶��ٸ�Ԫ��
}LinkStack;

LinkStack* creatLinkStack();
void releaseLinkStack(LinkStack *stack);

//insert��ʵ��ͷ�巨
int insertLinkStack(LinkStack *stack, Element val);

int popLinkStack(LinkStack *stack, Element *val);

void showLinkStack(LinkStack *stack);