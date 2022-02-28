/* 연결리스트로 구현된 스택 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int element;	//스택 자료형

typedef struct node		// 리스트 구조체
{ 
	int data;
	struct node* link;
}Node;
  
typedef struct			// 헤드 구조체
{
	
	Node* head;

}HStack;

HStack* createHead();
bool isEmpty(HStack*);
//bool isFull(HStack*);			//연결리스트는 필요할 떄 마다 노드를 추가하는 것 이므로, full이란 계념이 없다
void push(HStack*, element);
element pop(HStack*);
element peek(HStack*);

int main()
{
	
	HStack* h = createHead();
	
	printf("%d\n", isEmpty(h));
	pop(h);
	push(h, 10);
	printf("최신항목 : %d\n", peek(h));
	push(h, 20);
	printf("최신항목 : %d\n", peek(h));
	push(h, 30);
	printf("최신항목 : %d\n", peek(h));
	push(h, 40);
	printf("최신항목 : %d\n", peek(h));
	printf("%d\n\n", isEmpty(h));
	

	

	//h= pop(h);
	printf("element %d항목의 삭제를 완료\n", pop(h));
	printf("최근항목 : %d\n", peek(h));
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
	//노드에 value를 넣는다.
	//노드가 완정 비어있을 경우
	//head가 생성된 경우
	
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) exit(1);

	newNode->data = value;
	newNode->link = ahead->head;
	ahead->head = newNode;

}
element pop(HStack* ahead)		//값삭제
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
		//젤 최근항목 삭제
		//ahead->head에 제일 최근항목이 들어있음.
		//ahead->head가 ahead->head->list가 저장되어야하고...
		
		d = ahead->head->data;

		curr = ahead->head; // 삭제항목을 담는다

		ahead->head = ahead->head->link;
		free(curr);			//삭제항목에 할당된 메모리 영역을 해제한다.

		return d;
	}
}
element peek(HStack* ahead)		//가장 최근항목 확인
{
	if (isEmpty(ahead))			//노드가 비어있으면
	{
		printf("stack Underflower...\n");
		exit(1);
	}
	else
	{
		return ahead->head->data;	//가장 최근항목에 있는 데이터 반환
	}
}