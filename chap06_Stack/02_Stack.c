/*순차리스트 배열 구현*/
#include <stdio.h>
#include<stdbool.h>

#define STACK_SZ 10

typedef int element;

typedef struct
{
	int top;
	element stack_element[STACK_SZ];
}Stack;

void initStack(Stack*);
bool isEmpty(Stack*);
bool isFUll(Stack*);
void push(Stack*, element);
element pop(Stack*);

int main(void)
{
	Stack stack;

	initStack(&stack);
	
	//isEmpty(&stack);
	pop(&stack);
	push(&stack, 10);
	push(&stack, 20);
	push(&stack, 30);
	push(&stack, 40);
	printf("%d\n", pop(&stack));	//40
	printf("%d\n", pop(&stack));	//30
	printf("%d\n", pop(&stack));	//20
	printf("%d\n", pop(&stack));	//10?
	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack));

	
	//pop(&stack);
	return 0;

}



void initStack(Stack* pstack)		//stack 구조체 초기화
{

	pstack->top = -1;

}

bool isEmpty(Stack* pstack)
{

	if (pstack->top <= -1)
	{
		printf("stack Underflower\n");
		return true;
	}
	else return false;

}

bool isFUll(Stack* pstack)
{
	if (pstack->top >= STACK_SZ)
	{
		printf("stack Overflower\n");
		return true;
	}
	else return false;
}

void push(Stack* pstack, element value)
{
	if (isFUll(pstack))
	{
		printf("stack is Over..");
		return;
	}
	else
	{
		//pstack->top = pstack->top + 1;
		pstack->stack_element[++(pstack->top)] = value;
		printf("add stack : ");
		printf("%d\n", pstack->stack_element[(pstack->top)]);
	}
}

element pop(Stack* pstack)
{
	if (isEmpty(pstack))
	{
		printf("stac Under..\n");
		return;
	}
	else
	{
		pstack->top = pstack->top - 1;
		printf("min stack\n");
		return pstack->stack_element[pstack->top];
	}
}