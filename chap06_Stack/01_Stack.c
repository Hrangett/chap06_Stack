#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#define STACK_SZ 5

typedef int element;		//�����ڷ���

bool isEmpty();
bool isFull();
void push(element);

element stack[STACK_SZ];	//���� ����
int top = -1;				//������ �ʱⰪ :: top�� -1�̸� ������ִٴ� ��.

int main(void)
{



	return 0;
}
bool isEmpty()		//stack�� ���� ���� �� ó���ϴ� �Լ� ����
{
	if (top <= -1)return true;		//����������� 1�� ����
	else return false;				//�׷��� ������ 0�� ����

}

bool isFull()		//stack�� �� á�� �� ó���ϴ� �Լ� ����
{
	if (top >= STACK_SZ - 1)return true;	//���� �������� 1�� ����
	else return false;						//�׷��� ������ 0�� ����

}
void push(element value)				//stack�� ���� ����
{
	if (isFull())
	{
		printf("STACK overflow!!\n");
		return;
	}
	else stack[++top] = value;			//top�� �ʱⰪ�� -1�̹Ƿ� 1 ������Ų �� ���� ����
}
element pop()							//���ÿ��� ��� :: ���� �����ϴ� �Լ�
{
	if (isEmpty())
	{
		printf("STACK underflow!!\n");
		return 0;
	}
	else return stack[top--];
}
element peek()							//stack �� �� �߰�
{
	if (isEmpty())
	{
		printf("STACK underflow!!\n");
		exit(1);
	}
	else return stack[top];

}