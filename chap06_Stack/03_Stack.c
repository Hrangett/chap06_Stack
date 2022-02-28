/* ���Ḯ��Ʈ�� ������ ���� */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int element;	//���� �ڷ���

typedef struct node		// ����Ʈ ����ü
{ 
	int data;
	struct node* link;
}Node;
  
typedef struct			// ��� ����ü
{
	
	Node* head;

}HStack;

HStack* createHead();
bool isEmpty(HStack*);
//bool isFull(HStack*);			//���Ḯ��Ʈ�� �ʿ��� �� ���� ��带 �߰��ϴ� �� �̹Ƿ�, full�̶� ����� ����
void push(HStack*, element);
element pop(HStack*);
element peek(HStack*);

int main()
{
	
	HStack* h = createHead();
	
	printf("%d\n", isEmpty(h));
	pop(h);
	push(h, 10);
	printf("�ֽ��׸� : %d\n", peek(h));
	push(h, 20);
	printf("�ֽ��׸� : %d\n", peek(h));
	push(h, 30);
	printf("�ֽ��׸� : %d\n", peek(h));
	push(h, 40);
	printf("�ֽ��׸� : %d\n", peek(h));
	printf("%d\n\n", isEmpty(h));
	

	

	//h= pop(h);
	printf("element %d�׸��� ������ �Ϸ�\n", pop(h));
	printf("�ֱ��׸� : %d\n", peek(h));
	return 0;

}

HStack* createHead()
{
	
	HStack* h = (HStack*)malloc(sizeof(HStack));
	if (h == NULL) exit(1);
	h->head = NULL;
	return h;

}
bool isEmpty(HStack* ahead)
{
	if (ahead->head == NULL) return true;
	else return false;
}
void push(HStack* ahead, element value)
{	
	//��忡 value�� �ִ´�.
	//��尡 ���� ������� ���
	//head�� ������ ���
	
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) exit(1);

	newNode->data = value;
	newNode->link = ahead->head;
	ahead->head = newNode;

}
element pop(HStack* ahead)		//������
{

	element d;
	HStack* curr;

	if (isEmpty(ahead))
	{
		printf("stack Underflower...\n");
		exit(1);
	}
	else
	{
		//�� �ֱ��׸� ����
		//ahead->head�� ���� �ֱ��׸��� �������.
		//ahead->head�� ahead->head->list�� ����Ǿ���ϰ�...
		
		d = ahead->head->data;

		curr = ahead->head; // �����׸��� ��´�

		ahead->head = ahead->head->link;
		free(curr);			//�����׸� �Ҵ�� �޸� ������ �����Ѵ�.

		return d;
	}
}
element peek(HStack* ahead)		//���� �ֱ��׸� Ȯ��
{
	if (isEmpty(ahead))			//��尡 ���������
	{
		printf("stack Underflower...\n");
		exit(1);
	}
	else
	{
		return ahead->head->data;	//���� �ֱ��׸� �ִ� ������ ��ȯ
	}
}