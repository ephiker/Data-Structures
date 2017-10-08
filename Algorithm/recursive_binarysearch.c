#include <stdio.h>

int bSearchRecur(int ar[], int first, int last, int target){
  int mid;
  if(first > last)
    return -1;
  mid = (first+last)/2 ;
  if(ar[mid] == target)
    return mid;
  else if(ar[mid] < target){
    return bSearchRecur(ar, mid+1, last, target);
  } else{
    return bSearchRecur(ar, first, mid-1, target);
  }
}

int main(void){
  int arr[5] = {1,3,5,7,9};
  int idx;
  idx = bSearchRecur(arr, 0, sizeof(arr)/sizeof(int)-1, 9);

  printf("%d\n", idx);

  return 0;
}
