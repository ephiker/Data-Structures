#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int i = 10;
    int *pi = &i;
    float *pf = (float*) pi;
    printf("%f\n", *pf);

    // int a = -123;
    // int*p = (*int)malloc(sizeof(int));
    // void * vp = &a;

    // *p = 10;
    // printf("%d\n",  vp);

}
// void Add(int a, int b){
//   printf("%d\n", a+b);
// }
//
// void SPrint(char * str){
//   printf("%s\n", str);
// }
//
//
// int main(void){
//
//   char * string = "andre is ephiker";
//   int a=10, b=20;
//
// //함수 선언
//   void (*fptr1)(int a, int b);
//   void (*fptr2)(char str);
//
//
// }



//
//
// typedef struct _Employee{
//   int empNum;
//   char name[30];
// } Employee;
//
// Employee * WhosNightDuty(List * plist, char * name, int day){
//   Employee * ret;
//   int i, num = LCount(plist);
//
//   //이름찾기//
//   LFirst(plist, &ret); //ret에 있는 이름이 맞으면 아래 if문 안훑고 바로 지나감
//   if(strcmp((ret->name), name) != 0){
//     for(i = 0; i < num-1; i++){
//       LNext(plist, &ret);
//       if(strcmp((ret->name), name) == 0)
//         break;
//     }
//   }
//
//   //그로부터 며칠뒤//
//   for(i = 0; i<day; i++)
//     LNext(plist, &ret);
//
//   return ret;
// }
//
// int main(void){
//   int i;
//   Employee * pemp;
//   List list; //원형연결리스트구조체선언;
//   ListInit(&list);
//
//   //데이터 저장
//   pemp = (Employee*)malloc(sizeof(Employee)); //사원생성1
//   pemp->empNum = ""; //사원생성2
//   strcpy(pemp->name , "") //사원생성3
//   LInsert(&list, pemp);//생성한 사원 리스트에 추가
//
//   //3명 더 추가
//
//   WhosNightDuty(&list, 'ephiker', '5일뒤!')
// }



//
// typedef int LData;
//
// typedef struct _node{
//   int data;
//   struct _node * next;
// } Node;
//
// typedef struct _linkedList{
//   Node * head;
//   Node * cur;
//   Node * before;
//   int numOfData;
//   int (*comp)(LData d1, Ldata d2);
// } LinkedList;
//
//
// //초기화
// void LinkedList(List * plist){
//   //plist는 linkedlilst 구조체에 접근하는..Node와 동의어이다.
//   plist->head = (Node*)malloc(sizeof(Node));
//   plist->head->next = NULL;
//   plist->comp = NULL;
//   plist->numOfData = 0;
// }
//
//
// //멤버 추가
// void LInsert(List * plist, LData data){
//   if(plist->comp == NULL)
//     FInsert(plist, data);
//   else
//     SInsert(plist, data)
// }
//
// void FInsert(List * plist, LData data){
//   Node * newNode = (Node*)malloc(sizeof(Node));
//   newNode->data = data;
//   plist->head->next = newNode;
//   newNode->next = plist->head->next;
// }
//
//
// // void SInsert(List * plist, LData data){{
// //   Node * newNode = (Node*)malloc(sizeof(Node));
// //   newNode->data = data;
// // }
//
//
// LData LRemove(List * plist){
//   Node * rpos = plist->cur;
//   LData rdata = rpos->data;
//
//   plist->before->next = plist->cur->next;
//   plsit->cur = plist->before;
//
//   free(rpos);
//   (plist->numOfData)--
//   return rdata;
//
// }




// typedef struct _node{
//   int data;
//   struct _node * next;
// } Node;
//
// int main(void){
//   Node * head = NULL;
//   Node * tail = NULL;
//   Node * cur = NULL;
//   Node * newNode = NULL;
//   int readData;
//
//   //더미노드
//
//   head = (Node*)malloc(sizeof(Node));
//   tail = head;
//
//   while(1){
//     printf("input : ");
//     scanf("%d", &readData);
//     if(readData<1){
//       break;
//     }
//
//     newNode = (Node*)malloc(sizeof(Node));
//     newNode->data = readData;
//     newNode->next = NULL;
//
//     tail->next = newNode;
//     tail = newNode;
//   }
//
//
//   cur = head->next;
//   printf("%d ", cur->data);
//   while(cur->next!=NULL){
//     cur = cur->next;
//     printf("%d ", cur->data);
//   }
//
//   Node * delNode = head;
//   Node * delNextNode = head->next;
//
//   while(delNextNode!=NULL){
//     delNode = delNextNode;
//     delNextNode = delNextNode->next;
//     free(delNode);
//   }
//
//
//
//
// return 0;
//
// }





// 32785 reverse
// typedef struct _node{
//   int data;
//   struct _node * next;
// } Node;
//
// int main(void){
//   Node * head = NULL;
//   Node * tail = NULL;
//   Node * cur = NULL;
//
//
//   Node * newNode = NULL;
//   int i = 0;
//   int readData;
//   for(i = 0; i < 5; i++){
//     printf("input : ");
//     scanf("%d", &readData);
//
//     newNode = (Node*)malloc(sizeof(Node));
//     newNode->data = readData;
//
//     if(head == NULL){
//       tail = newNode;
//       newNode->next = NULL;
//     }else{
//       newNode->next = head;
//     }
//     head = newNode;
//   }
//
//
//
//   cur = head;
//   printf("%d ", cur->data);
//
//   while(cur->next != NULL){
//     cur = cur->next;
//     printf("%d ", cur->data);
//   }
//
//   return 0;
// }






// typedef struct _node{
//   int data;
//   struct _node * next;
// } Node;
//
// int main(void){
//   Node * head = NULL;
//   Node * tail = NULL;
//   Node * cur = NULL;
//
//   Node * newNode = NULL;
//   int readData;
//
//   //데이터입력받는과정
//   while(1){
//     printf("input : ");
//     scanf("%d", &readData);
//
//     if(readData <1 ){
//       break;
//     }
//
//     //노드의추가과정
//     newNode = (Node*)malloc(sizeof(Node));
//     newNode->data = readData;
//     newNode->next = NULL;
//
//     if(head == NULL)
//       head = newNode;
//     else
//       tail->next = newNode;
//
//     tail = newNode;
//     }
//
//     printf("\n");
//
//     //입력받은 데이터의 출력 과정
//     if(head == NULL){
//       printf("xxx\n");
//     }
//     else
//     {
//       cur = head;
//       printf("%d ", cur->data);
//
//       while(cur->next != NULL){
//         cur = cur->next;
//         printf("%d ", cur->data);
//       }
//     }
//     printf("\n");
//
//     //메모리의해체과정
//     if(head==NULL){
//       return 0;
//     }else{
//       Node * delNode = head;
//       Node * delNextNode = head -> next;
//       printf("delete %d\n", head->data);
//       free(delNode);
//
//       while(delNextNode != NULL){
//         delNode = delNextNode;
//         delNextNode = delNextNode->next;
//         printf("delete %d\n", delNode->data);
//         free(delNode);
//       }
//     }
//
//     return 0;
// }




// List list;
// Point compPos;
// Point * ppos;
//
// ListInit(&list);
//   plist->numOfData = 0;
//   plist->curPosition = -1
//
// ppos = (Point*)malloc(sizeof(Point));
// setPointPos(ppos, 2, 1) //포인터 구조체
//   ppos->xpos = 2
//   ppos->xpos = 1
// LInsert(&list, ppos);
//   plist->arr[plist->numOfData] = ppos
//
//


//
// int main(){
//   List list;
//   int sum = 0;
//   ListInit(&list);
//   LInsert(&list, 1);
//   LInsert(&list, 2);
//   LInsert(&list, 3);
//   LInsert(&list, 4);
//   LInsert(&list, 5);
//   LInsert(&list, 6);
//   LInsert(&list, 7);
//   LInsert(&list, 8);
//   LInsert(&list, 9);
//
//
//
//   if(LFirst(&list, &data)){
//     sum += data;
//
//     while(LNext(&list, &data))
//     {
//       sum += data;
//     }
//   }
//
//   if(LFirst(&list, &data)){
//     if(data%2 == 0 || data%3 == 0)
//       LRemove(&list);
//
//       while(LNext(&list, &data)){
//         if(data%2 == 0 || data%3 == 0)
//           LRemove(&list);
//       }
//   }
//
//   if(LFirst(&list, &data)){
//     printf("%d\n", data);
//     while(LNext(&list, &data)){
//       printf("%d\n", data);
//
//     }
//   }
//
//
//
//
//
//
//
//   return 0;
// }



// int main(void){
//   int *a;
//   a = (int*)malloc(sizeof(int));
//   printf("%d\n", a);
//   if(a == NULL){
//     puts("fail memory");
//     exit(1);
//   }
//   *a = 20;
//   free(a);
// }



//
// struct simple {
//   int data1;
//   int data2;
// };
//
// void show(struct simple a){
//   printf("%d\n", a.data1);
//   printf("%d\n", a.data2);
// }
//
// void swap(struct simple* b){
//   int temp;
//   temp = b->data1;
//   b->data1 = b->data2;
//   b->data2 = temp;
// }
//
//
// int main(void){
//   struct simple s = {1,2};
//
//   show(s);
//   swap(&s);
//   show(s);
// }



// struct person{
//   char name[20];
//   char pID[20];
//   struct person* frnd;
// };
//
// int main(void){
//   struct person man1 = {"Seo", "910410"};
//   struct person man1 = {"Sim", "920223"};
//
//   man1.frnd = &man2;
//
// }



// struct perInfo{
//   char addr[30];
//   char tel[20];
// };
//
// struct person{
//   char name[20];
//   char pID[20];
//   struct perInfo* info;
// };
//
// int main(){
//   struct perInfo someinfo = {"Korea Seoul", "333-444"};
//   struct person man = {"Seo", "910410"};
//   man.info = &someinfo;
//
//   printf("name %s\n", man.name);
//   printf("pID %s\n", man.pID);
//   printf("addr %s\n", man.info->addr);
//   printf("tel %s\n", man.info->tel);
//
//   return 0;
// }





//
// struct person{
//   char name[20];
//   char phone[20];
//   int age;
// };
//
// int main(){
//   struct person man = {"ephiker","010-1234"};
//   struct person* pMan;
//   pMan = &man;
//   (*pMan).age = 10;
//   printf("%d\n", (*pMan).age);
//   printf("%d\n", pMan->age);
//   printf("%d\n", man.age);
//
//   return 0;
//
//   // struct person pArray[10];
//   // strcpy(pArray[1].name, "ephiker");
//   // return 0;
// }



// void reverse(char *s);
//
// int main(){
//   char str[100];
//   fgets(str, sizeof(str), stdin);
//   reverse(str);
//   printf("%s\n", str);
//   return 0;
// }
//
// void reverse(char *s){
//   int ca, i;
//   int len = strlen(s);
//   for(i=0; i<len/2; i++){
//     ca = s[i];
//     s[i]=s[len-i-2];
//     s[len-i-2] = ca;
//   }
// }



//
// struct Employee{
//   char name[10];
//   char iden[20];
//   int money;
// }p1;
//
//
// int main(void){
//
//   strcpy(p1.name, "ephiker");
//   strcpy(p1.iden, "910410");
//   p1.money = 10000;
//
//   return 0;
// }


// struct point{
//   int x;
//   int y;
// };
//
// int main(void){
//   struct point p1, p2, p3;
//   p1.x = 10;
//   return 0;
// }



// int main(int argc, char const *argv[]) {
//   int n = 10;
//   void *vp = &n;
//   *((int*)vp) = 20;
//   return 0  ;
// }

// int (*fPtr)(int) = 함수를 가리킬 수 있는 포인터 = 함수이름


// void Add(int a, int b){
//   printf("result: %d\n", a+b);
// }
// void SPrint(char * str){
//   printf("input string: %s\n", str);
// }
//
// int main(void){
//   char * string = "functional pointer";
//   int a = 10, b= 20;
//
//   void(*fPtr1)(int, int) = Add;
//   void(*fPtr2)(char*) = SPrint;
//
//   fPtr1(a,b);
//   fPtr2(string);
//
//   return 0;
// }

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
// cur->get_next() = temp;
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







// int main(int argc, char const *argv[]) {
//   char a[10] = "ephiker";
//   printf("%d\n", strlen(a));
//   printf("%c\n", a[8]);
//   return 0;
// }





// int main(void) {
//
//   int**coordinate;
//   int xSize, ySize;
//   // int array[10][10];
//   coordinate
//

  // 더블포인터 변수 = 어떤 변수를 가리키는 포인터를 가리키고, 그 포인터 변수의 주소값을 값으로 가지고 있는 변수




//   // int *i = (int*)malloc(4);
//   //공간을 먼저 할당 후에 그 주소값을 연결시킴
//   //4자리 공간 allocation, 포인터 i에 주소값 대입
//    int *a;//포인터 변수만 생성
//    a=(int*)malloc(sizeof(int));//4바이트메모리공간에연결
//    if(a=NULL)
//    {
//      puts("fail");
//      exit(1);
//    }
//    *a = 20;
//    printf("variable a : %d\n", *a);
//    free(a);
//
//   return 0;
// }



// int main(void){
//   List list; //생성
//   ListInit(&list);//초기화
//   LInsert(&list, 11)//11을 저장
//
//   if(LFirst(&list, &data)){//첫번째참조
//     printf("%d\n", data);
//     while(LNext(&list, &data))//두번째이후참조
//       printf("%d\n", data);
//   }
//
//   if(Lfirst(&list, &data)){
//     if(data == 22)
//       LRemove(&list);
//     while(LNext(&list, &data)){
//       if(data == 22)
//         LRemove(&list);
//     }
//   }
//
//   return 0;
// }
//










//
// int fib(int n){
// 	if(n == 1)
// 		return 0;
// 	if(n == 2)
// 		return 1;
// 	return (fib(n-1)+fib(n-2));
// }
//
//
// int main(void){
// 	int n = 5;
// 	printf("%d\n", fib(5));
//
// 	return 0;
// }
//





// int Factorial(int num){
// 	int sum = 1;
// 	if(num<=1)
// 		return num;
// 	return num*Factorial(num-1);
// }
//
// int main(void){
// 	int sum;
// 	sum = Factorial(4);
// 	printf("%d\n", sum);
// 	return 0;
// }






// typedef struct _wallet
// {
// 	int coin100Num;
// 	int bill5000Num;
// } Wallet;
//
// int TakeOutMoney(Wallet * pw, int coinNum, int billNum);
// void PutMoney(Wallet * pw, int coinNum, int billNum);
//
//
// int main(void) {





// int main(void){
//
// 	//s1의 경우 100바이트 공간을 마련하고, S2는 컴파일 시 4바이트 공간만 할당한다.
// 	char s1[100] = "dog";
// 	printf("%d\n", sizeof(s1));
// 	char s2[] = "dog";
// 	printf("%d\n", sizeof(s2));
//
// 	return 0;
// }
