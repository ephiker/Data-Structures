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
	
	if(LFirst(&list, &data))    // 첫 번째 데이터 조회
	{
		printf("%d ", data);
		
		while(LNext(&list, &data))    // 두 번째 이후의 데이터 조회, 참조할 데이터가 있으면  TRUE를 반환 
			printf("%d ", data);
	}
	printf("\n\n");
	
		
		
	return 0;
	}
		
	









//int main(void)
//{
//	/*** ArrayList의 생성 및 초기화 ***/
//	List list;
//	ListInit(&list);
//	int data;
//
//	/*** 5개의 데이터 저장 ***/
//	LInsert(&list, 11);  LInsert(&list, 11);
//	LInsert(&list, 22);  LInsert(&list, 22);
//	LInsert(&list, 33);
//
//	/*** 저장된 데이터의 전체 출력 ***/
//	printf("현재 데이터의 수: %d \n", LCount(&list));
//
//	if(LFirst(&list, &data))    // 첫 번째 데이터 조회
//	{
//		printf("%d ", data);
//		
//		while(LNext(&list, &data))    // 두 번째 이후의 데이터 조회, 참조할 데이터가 있으면  TRUE를 반환 
//			printf("%d ", data);
//	}
//	printf("\n\n");
//
//	/*** 숫자 22을 탐색하여 모두 삭제 ***/
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
//	/*** 삭제 후 저장된 데이터 전체 출력 ***/
//	printf("현재 데이터의 수: %d \n", LCount(&list));
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
