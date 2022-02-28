#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#define STACK_SZ 5

typedef int element;		//스택자료형

bool isEmpty();
bool isFull();
void push(element);

element stack[STACK_SZ];	//스택 생성
int top = -1;				//스택의 초기값 :: top이 -1이면 비워져있다는 뜻.

int main(void)
{



	return 0;
}
bool isEmpty()		//stack에 값이 없을 떄 처리하는 함수 생성
{
	if (top <= -1)return true;		//비워져있으면 1을 전달
	else return false;				//그렇지 않으면 0을 전달

}

bool isFull()		//stack이 다 찼을 떄 처리하는 함수 생성
{
	if (top >= STACK_SZ - 1)return true;	//가득 차있으면 1을 전달
	else return false;						//그렇지 않으면 0을 전달

}
void push(element value)				//stack에 원소 삽입
{
	if (isFull())
	{
		printf("STACK overflow!!\n");
		return;
	}
	else stack[++top] = value;			//top의 초기값이 -1이므로 1 증가시킨 후 값을 넣음
}
element pop()							//스택원소 출력 :: 원소 삭제하는 함수
{
	if (isEmpty())
	{
		printf("STACK underflow!!\n");
		return 0;
	}
	else return stack[top--];
}
element peek()							//stack 에 값 추가
{
	if (isEmpty())
	{
		printf("STACK underflow!!\n");
		exit(1);
	}
	else return stack[top];

}