#include <stdio.h>

void swap(int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

void sort(int list[], int n){
  //find the minimum of list[i] through list[n-1]
  int idx_min = 0;
  int i = 0, j = 0, temp = 0;
  for(i=0;i<n-1;i++){
    idx_min = i;
    for(j=i+1; j < n; j++){
      if(list[j] < list[idx_min])
        idx_min = j;
    }
    swap(&list[i], &list[idx_min]);
  }
  for(i=0; i<n; i++){
    printf("%d", list[i]);
  }
}


int main(void){
  int i;
  int arr[5] = {5,1,3,9,7};
  int len = sizeof(arr)/sizeof(int);
  sort(arr, len);
  printf("\n");

	return 0;
}
