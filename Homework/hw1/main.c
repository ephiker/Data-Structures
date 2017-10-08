//21000348 seo andre

#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 1024


int main(void) {
	
  int i;
  char key[35];
  char key2[35];
  int value[35];

//setting array

  //key 0~25 = Upper case alphabet array
  for (i = 0; i < 26; i++){
    key[i] = 65+i; //65 = 'A'
    value[i] = 0;
  };

//key2 0~25 = Lower case alphabet array
  for (i = 0; i < 26; i++){
    key2[i] = 97+i; //97 = 'a'
    value[i] = 0;
  };

//both 26~35
  for (i = 0; i < 10; i++){
    key[26+i] = 48+i; //48 = '0'
    key2[26+i] = 48+i; //48 = '0'
    value[26+i] = 0;
  };

//check each array
//  for (i = 0; i < 36; i++){
//    // printf("%c : %d\n", key[i], value[i]);
//    printf("%c : %d\n", key2[i], value[i]);
//  };


  FILE *fp; //??
  char file_name[128];
  char line[MAX_LEN];
  
  printf("input file name?\n");
  scanf("%s", file_name);
  fp = fopen(file_name, "r");
  
  //check
  if (fp == NULL){
    printf("file open is not successful\n");
    return -1;
  }
  
  while (fgets(line, MAX_LEN, fp)) {
    int i = 0;
    int j = 0;
    printf("%s", line);
  
    //한 줄의 끝인 NULL까지 반복
    while ((line[i]) != NULL) {
      for(j = 0; j<36; j++){
        if (key[j] == line[i] || key2[j] == line[i]){
          value[j] = value[j]+1;
        }
      }
      i++;
    }
  }
  
  fclose(fp);
  
  //print out
  printf("\n");
  for (i = 0; i < 36; i++){
    printf("%c : %d\n", key[i], value[i]);
  }

	
	return 0;
}


