#include <stdio.h>

//4개가 있으면, 우선 맨 아래 1개를 옮기기 위해 위의 세개를 옮겨.
//그래고 맨 아래 1개를 옮겨, 나머지 3개를 다시 재귀로 옮겨.
void hanoi(int a, char from, char by, char to){
  if (a == 1){
    printf("Circle 1, Move from %c To %c \n", from, to);
  } else {
    hanoi(a-1, from, to, by);
    printf("Circle %d, Move from %c To %c \n", a, from, to);
    hanoi(a-1, by, from, to);
  }
}

int main(void){
  int n = 3;
  hanoi(n, 'A', 'B', 'C');
  return 0;

}




// return (2*hanoi(a-1) + 1);
