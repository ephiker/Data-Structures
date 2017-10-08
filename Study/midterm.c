#include <stdio.h>
#include <stdlib.h>
#include <string.h>




// //*동적메모리할당
// int main(){
//   int *pi; //동적 메모리 할당은, 포인터 변수에  할당한 주소값을 입력해 주는 것
//   int *pf;
//   pi = (int*)malloc(sizeof(int));
//   pf = (float*)malloc(sizeof(float));
//   *pi = 1024;
//   *pf = 3.14;
//   free(pi);
//   free(pf);
//   return 0;
// }

// //*변수,배열,구조체의 동적메모리 할당
// int main(){
//   int *a = (int*)malloc(sizeof(int));
//   int *arr = (int*)malloc(size * sizeof(int));
//
//   struct Time{
//     int hour, min, sec;
//   };
//   struct Time * pCurTime = (struct Time*)malloc(sizeof(struct Time));
//   pCurTime->hour = 10;
//
//   return 0;
// }

// //*잘못된 포인터의 사용
// 1. 잘못된 형변환 invalid type casting
// 2. 포인터의 비할당 unassigned pointer
// 3. 허상 포인터(free 반복하기) dangling pointer
// 4. 메모리 유실 memory leak


// //*셀렉션소트
// void swap(int *x, int *y){
//   int temp = *x;
//   *x = *y;
//   *y = temp;
// }
//
// void sort(int list[], int n){
//   //find the minimum of list[i] through list[n-1]
//   int idx_min = 0;
//   int i = 0, j = 0, temp = 0;
//   for(i=0;i<n-1;i++){
//     idx_min = i;
//     for(j=i+1; j < n; j++){
//       if(list[j] < list[idx_min])
//         idx_min = j;
//     }
//     swap(&list[i], &list[idx_min]);
//   }
//   for(i=0; i<n; i++){
//     printf("%d", list[i]);
//   }
// }
//
// int main(void){
//   int i;
//   int arr[5] = {5,1,3,9,7};
//   int len = sizeof(arr)/sizeof(int);
//   sort(arr, len);
//   printf("\n");
// 	return 0;
// }


// //*바이너리 서치
// int COMPARE(int x, int y){
//   if(x < y)
//     return -1;
//   else if(x == y)
//     return 0;
//   else
//     return 1;
//   }
//
// int bsearch(int list[], int searchnum, int left, int right){
//   int middle;
//   while(left <= right){
//     middle = (left + right)/2;
//     switch (COMPARE(list[middle], searchnum)) {
//       case -1:
//         left = middle +1;
//         break;
//       case 0:
//         return middle;
//       case 1:
//         right = middle -1 ;
//     }
//   }
//   return -1;
// }
//
// int main(void){
//   int arr[5] = {1,3,5,7,9};
//   int res_idx;
//   res_idx = bsearch(arr, 9, 0, sizeof(arr)/sizeof(int));
//
//   printf("%d\n", res_idx);
//
// 	return 0;
// }


// //*폴리노미널 시간복잡도
// 단일for문일 경우 O(n)
// 이중for문일 경우 O(n^2)
// 삼중for문일 경우 O(n^3)

// //* 1차원 배열 동적할당
// int main(void){
//   int i = 0;
//   int *list = (int*)malloc(100*sizeof(int));
//   for(i=0; i<100; i++){
//     list[i] = i;
//   }
//   printf("%d\n", list[99]);
//   return 0;
// }


// //* 2차원 배열 동적 할당
// int main(){
//   int i;
//   int row, col;
//   int **arr = NULL;
// //int*형의 원소를 row개 가지는 1차원 배열 생성
//   arr = (int**)malloc(sizeof(int*)*row);
// //
//   for (i = 0; i<row; i++){
//     arr[i] = (int*)malloc(sizeof(int)*col);
//   }
//   //free
//   for (i = 0; i<row; i++){
//     free(arr[i]);
//   }
//   free(arr);
//
//   return 0;
// }
