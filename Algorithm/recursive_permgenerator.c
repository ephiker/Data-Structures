#include<stdio.h>
#include<string.h>
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void perm(char *list, int i, int n){
  int j, temp;
  if (i == n){ //한 개일 때
    for (j=0; j<=n; j++)
      printf("%c", list[j]);
    printf(" ");
  }else{
    for (j=i; j<n+1; j++){
      SWAP(list[i], list[j], temp);
      perm(list, i+1, n);
      SWAP(list[j], list[i], temp);
    }
  }
}

int main(){

  char list[3] = {'a','b','c'};
  perm(list, 0, ((sizeof(list)/sizeof(char))-1));
  return 0;
}
