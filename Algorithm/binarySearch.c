#include <stdio.h>

int COMPARE(int x, int y){
  if(x < y)
    return -1;
  else if(x == y)
    return 0;
  else
    return 1;
  }


int bsearch(int list[], int searchnum, int left, int right){
  int middle;
  while(left <= right){
    middle = (left + right)/2;
    switch (COMPARE(list[middle], searchnum)) {
      case -1:
        left = middle +1;
        break;
      case 0:
        return middle;
      case 1:
        right = middle -1 ;
    }
  }
  return -1;
}



int main(void){
  int arr[5] = {1,3,5,7,9};
  int res_idx;
  res_idx = bsearch(arr, 9, 0, sizeof(arr)/sizeof(int));

  printf("%d\n", res_idx);

	return 0;
}
