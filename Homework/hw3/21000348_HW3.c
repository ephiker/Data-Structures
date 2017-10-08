// using GCC COMPILER
// 21000348 andre,seo

// This program is a roster management program that can add and delete using binary search tree.
// using Binary Search Tree
// 2017-05-04



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Node Structure
typedef struct node
{
   int data;
   char data2[99];
   struct node *left;
   struct node *right;
}Node;


///////////////////////
////Insert Function////
///////////////////////
void insert_node(Node **tree_root, int data, char * data2)
{
   Node *current, *finding;

   //First Add
   if (*tree_root == NULL)
   {
      current = (Node *)malloc(sizeof(Node)); //make new node
      current->data = data;//data input
      strcpy(current->data2, data2); //data2 input
      current->left = current->right = NULL;//linking setting
      *tree_root = current;//initial root
      return;
   }

   finding = *tree_root;

   //Add and Find Parent Node After First Add
   while (finding)
   {
      if (data == finding->data){ //Unaccepted Same Value
         return;
      }
      if (data < finding->data)
      {//if data < finding
         if (finding->left == NULL)
         {//found!
            break;
         }else{//left down
            finding = finding->left;
         }
      }else{//data > finding
         if (finding->right == NULL)
         {//found!
            break;
         }else
         {//right down
            finding = finding->right;
         }
      }
   }


   //make child node at current
   current = (Node *)malloc(sizeof(Node));
   current->data = data;//data input
   strcpy(current->data2, data2);//data2 input
   current->left = current->right = NULL;//linking setting
   if (data < finding->data)
   {
      finding->left = current;//hang left
   }else{
      finding->right = current;//hang right
   }
}






////////////////////////////////
////Sub Functions For Delete////
////////////////////////////////
Node * MakeTreeNode(void){ //making tree node
	Node * nd = (Node*)malloc(sizeof(Node));
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

int GetData(Node * bt){//getting data
	return bt->data;
}

void SetData(Node * bt, int data){//setting data
	bt->data = data;
}

Node * GetRightSubTree(Node * bt){//getting right sub tree
	return bt->right;
}

Node * GetLeftSubTree(Node * bt){//getting left sub tree
	return bt->left;
}

Node * RemoveLeftSubTree(Node * bt){//removing left sub tree
	Node * delNode;
	if(bt != NULL) {
		delNode = bt->left;
		bt->left = NULL;
	}
	return delNode;
}

Node * RemoveRightSubTree(Node * bt){//removing right sub tree
	Node * delNode;
	if(bt != NULL) {
		delNode = bt->right;
		bt->right = NULL;
	}
	return delNode;
}

void ChangeLeftSubTree(Node * main, Node * sub){//changing left sub tree
	main->left = sub;
}

void ChangeRightSubTree(Node * main, Node * sub){//changing right sub tree
	main->right = sub;
}


///////////////////////
////Delete Function////
///////////////////////
void remove_node(Node **tree_root, int target){

  Node *temporary = MakeTreeNode();
  Node *pNode = temporary; // parent node
  Node *cNode = *tree_root; // current node
  Node *dNode;  // delete node

  // make root node right sub tree to temporary node
  ChangeRightSubTree(temporary, *tree_root);



  //find delete node
	while(cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode;
		if(target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

  // input key isn't exist
	if(cNode == NULL)
		return;

  //found delete node
	dNode = cNode; //it is dnode

	// In the first case: the node to be deleted is a leaf node
	if(GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL){
		if(GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}

	// Second case: If you have one child node
	else if(GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL){
		Node * dcNode;  // childe node of delete node

		if(GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);
		else
			dcNode = GetRightSubTree(dNode);

		if(GetLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	}

  // Third case: Having both child nodes
	else{
		Node * mNode = GetRightSubTree(dNode);    // mininum node
		Node * mpNode = dNode;    // parents node of mininum node

    //back up variable
    int delData;
    char delData2[99];

		// find replace node
		while(GetLeftSubTree(mNode) != NULL){
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		// backup data of delete node
		delData = GetData(dNode);
    strcpy(delData2, dNode->data2);

    // replace data to delete node
		SetData(dNode, GetData(mNode));
    strcpy(dNode->data2, mNode->data2);

		// linking
		if(GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
		dNode = mNode;
	}

	// when the deleted node is the root node
	if(GetRightSubTree(temporary) != *tree_root)
		*tree_root = GetRightSubTree(temporary);
	free(temporary);
}



///////////////////////////////
////Inorder Travel Function////
///////////////////////////////
void inorder(Node *sroot){
  if(sroot == NULL)
    return;

  inorder(sroot->left);
  printf("(%d, %s) ", sroot->data, sroot->data2);
  inorder(sroot->right);
}


/////////////////////
////Main Function////
/////////////////////
int main(void){
  int i;
  Node *root = NULL;

  char command;
  int key;
  char value[99] = {0};

 // get command, key, value
  printf("run %% bst\n");

  while(1){
    scanf("%c", &command); //first

    if(command == 'q') //quit
      break;

    if(command == 'p'){ //print inorder
      inorder(root);
      printf("\n");
    }

    scanf("%d", &key); //second

    if(command == 'd')
      remove_node(&root, key); //remove node

    if(command == 'a'){
      scanf("%s", value);
      insert_node(&root, key, value); //insert (key, value) pair
    }
  }

   return 0;
}
