// using GCC COMPILER, test file is prepared!
// 21000348 andre,seo

// The program is a program that outputs the most frequently used words in order to output the most frequently used words in the text file.
// using QuickSort
// 2017-05-22


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD 2048
#define MAX_LEN 2048




char word[MAX_WORD][MAX_LEN];
int count[MAX_WORD] = { 0 };


void Swap(int arr[], int x, int y)
{
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}


int Partition(int arr[], int left, int right, char (*arr2)[MAX_LEN])
{
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high)
	{

		while (pivot <= arr[low] && low <= right)
			low++;

		while (pivot >= arr[high] && high >= (left + 1))
			high--;

		if (low <= high) {
			Swap(arr, low, high);
			char* temp[MAX_LEN];
			strcpy(temp, arr2[low]);
			strcpy(arr2[low], arr2[high]);
			strcpy(arr2[high], temp);
		}

	}

	Swap(arr, left, high);
	char* temp[MAX_LEN];
	strcpy(temp, arr2[left]);
	strcpy(arr2[left], arr2[high]);
	strcpy(arr2[high], temp);

	return high;
}

void QuickSort(int arr[], int left, int right, char (*arr2)[MAX_LEN])
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right, arr2);
		QuickSort(arr, left, pivot - 1, arr2);
		QuickSort(arr, pivot + 1, right, arr2);
	}
}


FILE * fp;

int main(void) {
	int index = 0;
	int i, j;


	// retrieve text file
	fp = fopen("test.txt", "r");
	if (fp != NULL) {
		char Temp[MAX_LEN];
		char *str, *str2;
		char *pstr = NULL;



		while (!feof(fp)) {
			str = fgets(Temp, sizeof(Temp), fp); // replace one sentence with one sentence
			str2 = strtok(str, "\n"); //delete \n
			pstr = strtok(str2, " ");
			while (pstr != NULL) {
				//delete punctuation
				for (i = 0; i<strlen(pstr); i++) {
					if (ispunct(pstr[i])) { //if punctuation exists
						pstr[i] = NULL; //turn it to NULL
					}
				}
				//input to array
				strcpy(word[index], pstr);
				count[index]++;
				index++;
				pstr = strtok(NULL, " ");
			}
		}
	}
	fclose(fp);




	//making count
	for (i = 0; i<index - 1; i++) {
		for (j = i + 1; j<index; j++) {
			if (strcmp(word[i], word[j]) == 0) {
				count[i] += count[j];
				count[j] = -1;
			}
		}
	}


	printf("\n");

	//Sort using Count
	QuickSort(count, 0, index - 1, word);


	//printing TOP5
	printf("The 5 Most Frequent words\n");
	for (i = 0; i<5; i++) {
		printf("%d %s\n", count[i], word[i]);
	}


	getchar();
	return 0;
}
