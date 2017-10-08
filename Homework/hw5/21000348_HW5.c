// using GCC COMPILER
// using GCC COMPILER
// using GCC COMPILER
// using GCC COMPILER
// using GCC COMPILER
// using GCC COMPILER
// using GCC COMPILER

// 21000348 andre,seo

// When you receive a word to modify this program,
// it is a program that corrects the word in the input text file. Use a binary navigation tree.

// 2017-06-04



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



//Defining node struct
typedef struct node
{
	int order;
	char data[25];
	struct node *left;
	struct node *right;
}Node;


//Insert Function
void insert_node(Node **tree_root, int order, char * data)
{
	Node *current, *finding;

	//First Add
	if (*tree_root == NULL)
	{
		current = (Node *)malloc(sizeof(Node)); //make new node
		current->order = order;//data input
		strcpy(current->data, data); //data2 input
		current->left = current->right = NULL;//linking setting
		*tree_root = current;//initial root
		return;
	}

	finding = *tree_root;

	//Add and Find Parent Node After First Add
	while (finding)
	{
		if (order == finding->order) { //Unaccepted Same Value
			return;
		}
		if (order < finding->order)
		{//if data < finding
			if (finding->left == NULL)
			{//found!
				break;
			}
			else {//left down
				finding = finding->left;
			}
		}
		else {//data > finding
			if (finding->right == NULL)
			{//found!
				break;
			}
			else
			{//right down
				finding = finding->right;
			}
		}
	}


	//Make child node at current
	current = (Node *)malloc(sizeof(Node));
	current->order = order;//data input
	strcpy(current->data , data);//data2 input
	current->left = current->right = NULL;//linking setting


	if (order < finding->order)
	{
		finding->left = current;//hang left
	}
	else {
		finding->right = current;//hang right
	}
}


//Inorder Travel and File Write
void inorder_write(Node *sroot, FILE * fp2) {
		if (sroot == NULL)
      return;

	inorder_write(sroot->left, fp2);

  //Write to file considering newline
  fprintf(fp2, "%s ", sroot->data);
  printf("%s ", sroot->data);


	inorder_write(sroot->right, fp2);
}

//Inorder Travle and Word Replace
void inorder_replace(Node *sroot, char *target, char *newone) {
	if (sroot == NULL)
		return;

	inorder_replace(sroot->left, target, newone);
  if(strcmp(sroot->data, target) == 0){ //If the node's data is the same as the target
    strcpy(sroot->data, newone); //Replace the node's data with a new one
  }
  inorder_replace(sroot->right, target, newone);
}



int main(void) {

	//Node declaration
	Node *root = NULL;
	char data[25];
  int order = -1;
  char target[25];
  char newone[25];
  int i;
  int res;
	int how;
	char file_name1[128], file_name2[128], file_name3[128];
	char rev[10] = ".rev.txt";


	FILE * fp; //text file
  FILE * fp2; //revised file
  FILE * fp3; //map file

	printf("Input file name?(test.txt is prepared for you.)\n");
  scanf("%s", file_name1);
	fflush(stdin);
	printf("\n");


		// Create revised file name
   int cnt1 = 0; // count for file name 2
	 int cnt2 = 0; // count for file name 1 and .rev.txt

   while(file_name1[cnt2] != '\0') //Store the first character of a string in a temporary variable, one character at a time
   {
       file_name2[cnt1++] = file_name1[cnt2++];
   }

	 cnt1 = cnt1-4;
	 cnt2 = 0;

   while(rev[cnt2] != '\0')//Save the characters of the second argument string to temporary variables, one character at a time
   {
       file_name2[cnt1++] = rev[cnt2++];
   }
   file_name2[cnt1]= '\0';
   printf("Revised file name is generated. \n");
	 printf("\n");



	 printf("Map file name?(map.txt is prepared for you.)\n");
   scanf("%s", file_name3);
   printf("\n");


  fp = fopen(file_name1, "r"); //file open
  fp2 = fopen(file_name2 , "w");
  fp3 = fopen(file_name3, "r");



	// Read from file
  while (fscanf(fp, "%s", data) == 1){ // Read by word
    order += 1;
    // Add to input string node
    insert_node(&root, order, data);
  }




  while(1){
    res = fscanf(fp3, "%s%s", target, newone);
    if (res == EOF)
      break;

    for (i = 0; i<strlen(target); i++) {
      if (ispunct(target[i])) { //if punctuation exists
        target[i] = NULL; //turn it to NULL
      }
    }


		// Search and populate
    inorder_replace(root, target, newone);
}


// Write to file
	printf("Revising is completed.\n\n");
  inorder_write(root, fp2);

	fclose(fp);
  fclose(fp2);
  fclose(fp3);

	return 0;
	}
