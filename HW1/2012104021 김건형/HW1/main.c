#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

int main() 
{
	ListNodePtr startPtr = NULL;
	char item[20];
	int overlap;
	FILE *f;

	fopen_s(&f, "Input.txt", "r");

	printf("Input data by Text File\n\n");
	for (int i=0; i<1024; i++) {
		fscanf_s(f, "%s", item, sizeof(item));
		if (item == NULL) break;
		insert(&startPtr, item);
		item[0] = '\0';
	}
	
	while (1) {
		instructions();
		scanf_s("%s", item, sizeof(item));
		if (strcmp(item, "Q") == 0) break;
		else {
			overlap = search(&startPtr, item);
			if (overlap) {
				if (overlap == 1) {
					printf("%s is founded. this word shown once.\n", item);
					printf("This word's index is %d.\n\n", indexnumber[0]);
				}
				else if (overlap > 1) {
					printf("%s is founded. this word shown %d times.\n", item, overlap);
					for (int i = 0; i < overlap; i++) {
						printf("This word's index is %d.\n", indexnumber[i]);
					}
				}
				printf("\n");
			}
			else
			{
				printf("%s is not found.\n\n", item);
			}
		}
	}
	printf("End of run.\n");
	return 0;
}


void instructions(void)
{
	printf("Input the word, if you want find or Q : ");
}