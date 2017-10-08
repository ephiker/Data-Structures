// using GCC COMPILER
// 21000348 andre,seo

// This program reads text files line by line, and writes them as a new files, reverses the order.
// using linked list
// 2017-04-10


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 1024


//defining node struct
typedef struct _node{
  char* data; // node content
  struct _node * next; //node pointer
} Node;

//fuction for writing in reverse order
void recursion(Node * line, FILE* fp2){
  if (line == NULL)
    return;
  recursion(line->next, fp2);
  fputs(line->data, fp2); //file writing
}


///////////////////////main function
int main(void){
  //initializing nodes
  Node * head = NULL;
  Node * tail = NULL;
  Node * cur = NULL;
  Node * newNode = NULL;

  //initializing files
  FILE *fp1, *fp2;
  char file_name1[128], file_name2[128];
  char line[MAX_LEN];

  //selecting input file and output file
  printf("input file name?(test.txt is prepared for you.)\n");
  scanf("%s", file_name1);
  printf("output file name?(name format = xxx.txt)\n");
  scanf("%s", file_name2);
  printf("\n");

  //appending 'enter' to the end of file because last line doesn't have '\n'
  fp1 = fopen(file_name1, "a");
  fputc('\n', fp1);
  fclose(fp1);

  //openning file
  fp1 = fopen(file_name1, "r");

  //warning to empty file
  if (fp1 == NULL){
    printf("file open is not succeerssful\n");
    return -1;
  }

  //linked list
  while (fgets(line, MAX_LEN, fp1)) {
    newNode = (Node*)malloc(sizeof(Node)); //allocation for newnode
    newNode->data = (char*)malloc(sizeof(line)); //allocation for input data
    strcpy(newNode->data, line); //copy data
    newNode->next = NULL;

    if(head == NULL){ //first node linking
      printf("Reading Completed\n");
      head = newNode;
    } else { //other nodes linking
      tail->next = newNode;
    }
    tail = newNode;
  }

  //writing
  fp2 = fopen(file_name2, "w");
  if(head == NULL)
    printf("fail \n");
  else {
    cur = head; //to the first node
    recursion(head, fp2); //writing function using recursion
    printf("Writing Completed\n");
    }

  fclose(fp1);
  fclose(fp2);
  return 0;
}
