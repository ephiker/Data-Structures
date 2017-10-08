#include <stdio.h>
#include <stdlib.h>

typedef struct _linkedList{
  Node * head;
  Node * cur;
  Node * before;
  int numOfData;
  int (*comp)(LData d1, LData d2);
} LinkedList;

void ListInit(List * plist){
  plist->head = (Node*)malloc(sizeof(Node));
  plist->head->next = NULL;
  plist->comp = NULL;
  plist->numOfData = 0;
}

void LInsert(List * plist, Ldata data){
  if(plist->comp == NULL)
    FInsert(plist, data); //머리에 추가
  else
    SInsert(plist, data); //정렬기준에 맞게 추가
}

new

void FInsert(List * plist, LData data){
  Node * newNode = (Node*)malloc(sizeof(Node));
  newNode -> data = data;

  newNode->next = plist->head->next; //더미노드와 기존 두번째 노드(기존 머리) 사이에 끼워넣음(새로운 머리가 된다)
  plist->head->next = newNode; //더미는 그대로 더미인 것
}

void LFirst(List * plist, LData *pdata){
  if(plist->head->next = NULL)
    return FALSE;

  plist->before = plist->head;
  plist->cur = plist->head->next;

  *pdata = plist->cur->data;
  return TRUE;
}

void LNext(List * plist, LData * pdata){
  if(plist->cur->next = NULL)
    return FALSE;

  plist->before = plist->cur;
  plist->cur = plist->cur->next;

  *pdata = plist->cur->data;
  return TRUE;
}

void LRemove(List * plist){
  Node * rpos = plist->cur; // 소명 대상의 주소값 백업
  LData rdata = rpos->data; //소멸 대상의 데이터 백업

  plist->before->next = plist->cur->next;
  plist->cur = plist->before;

  free(rpos);
  (plist->numOfData)--;
  return data;
}


int main(void){
  ListInit

  return 0;
}
//
//
// //노드 스트럭쳐 선언
// typedef struct _node{
//   int data;
//   struct _node * next;
// } Node;
//
// //노드 헤드 테일 커런트 NULL로 선언
// int main(void){
//   Node * head = NULL;
//   Node * tail = NULL;
//   Node * cur = NULL;
//
//   Node * newNode = NULL;
//   int readData;
//
//   head = (Node*)malloc(sizeof(Node)); //dummy node code
//   tail = head; //dummy node code
//
//   //while문으로 데이터 입력받고 1 미만이면 탈출
//
//   while(1){
//     printf("input data");
//     scanf("%d", &readData);
//
//     if (readData < 1)
//       break;
//     //노드의 추가과정
//     newNode = (Node*)malloc(sizeof(Node));
//     newNode->data = readData;
//     newNode->next = NULL;
//
//     // 입력받은 데이터는 뉴노드의 데이터에 저장되고 각각 헤드와 테일 설정
//
// /*
//     if(head == NULL)
//       head = newNode;
//     else
//       tail->next = newNode;
//       */
//
//     tail->next = newNode;
//     tail = newNode;
//
//     // if(head == NULL){
//     //   head = newNode;
//     //   tail = newNode;
//     // }else{
//     //   newNode->next = head;
//     //   head = newNode;
//     // }
//
//   }
//
//   //데이터 전체 출력
//   if(head == NULL){
//     printf("no data\n");
//   }else{
//     cur = head;
//     // printf("%d ", cur->data);
//     while(cur->next != NULL){
//       cur = cur->next;
//       printf("%d ", cur->data);
//     }
//   }
//
//
//
//     if(head == NULL){
//       return 0;
//     }else{
//       Node*delNode = head;
//       Node*delNextNode = head->next;
//
//       // printf("%d is deleted \n", head->data);
//       // free(delNode);
//
//       while(delNextNode != NULL){
//         delNode = delNextNode;
//         delNextNode = delNextNode->next;
//         printf("%d is deleted \n", delNode->data);
//         free(delNode);
//       }
//     }
//
//
//
//
//
//
//   return 0;
// }
//
//
