#include <stdio.h>
#include "ArrayList.h"

int main(void){
	List list;
	ListInit(&list);
	int data;
	int sum = 0;
	
	int i;
	for(i=0;i<9;i++){
		LInsert(&list, i+1);
	}
	
	if(LFirst(&list, &data)){
		sum += data;
		while(LNext(&list, &data))
			sum += data;
	}
	
	printf("%d", sum);
	printf("\n\n");
	
	if(LFirst(&list,&data)){
		if(data%2==0 || data%3==0)
			LRemove(&list);
		while(LNext(&list, &data))
			if(data%2==0 || data%3==0)
				LRemove(&list);	
	}
	
	if(LFirst(&list, &data))    // ù ��° ������ ��ȸ
	{
		printf("%d ", data);
		
		while(LNext(&list, &data))    // �� ��° ������ ������ ��ȸ, ������ �����Ͱ� ������  TRUE�� ��ȯ 
			printf("%d ", data);
	}
	printf("\n\n");
	
		
		
	return 0;
	}
		
	









//int main(void)
//{
//	/*** ArrayList�� ���� �� �ʱ�ȭ ***/
//	List list;
//	ListInit(&list);
//	int data;
//
//	/*** 5���� ������ ���� ***/
//	LInsert(&list, 11);  LInsert(&list, 11);
//	LInsert(&list, 22);  LInsert(&list, 22);
//	LInsert(&list, 33);
//
//	/*** ����� �������� ��ü ��� ***/
//	printf("���� �������� ��: %d \n", LCount(&list));
//
//	if(LFirst(&list, &data))    // ù ��° ������ ��ȸ
//	{
//		printf("%d ", data);
//		
//		while(LNext(&list, &data))    // �� ��° ������ ������ ��ȸ, ������ �����Ͱ� ������  TRUE�� ��ȯ 
//			printf("%d ", data);
//	}
//	printf("\n\n");
//
//	/*** ���� 22�� Ž���Ͽ� ��� ���� ***/
//	if(LFirst(&list, &data))
//	{
//		if(data == 22)
//			LRemove(&list);
//		
//		while(LNext(&list, &data))
//		{
//			if(data == 22)
//				LRemove(&list);
//		}
//	}
//
//	/*** ���� �� ����� ������ ��ü ��� ***/
//	printf("���� �������� ��: %d \n", LCount(&list));
//
//	if(LFirst(&list, &data))
//	{
//		printf("%d ", data);
//		
//		while(LNext(&list, &data))
//			printf("%d ", data);
//	}
//	printf("\n\n");
//	return 0;
//}
