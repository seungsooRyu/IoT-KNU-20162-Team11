#include "LinkedList.h"
#include <stdlib.h>
#include <string.h>

void insert(ListNodePtr *sPtr, char *value)
{
	ListNodePtr newPtr, previousPtr, currentPtr;

	newPtr = malloc(sizeof(ListNode));

	if (newPtr != NULL) {
		newPtr->index = 1;
		if (strcspn(value, ".") < strlen(value) || strcspn(value, ",") < strlen(value) || strcspn(value, "!") < strlen(value) || strcspn(value, "?") < strlen(value)) {
			value[strlen(value + 1)] = '\0';
		}
		strcpy_s(newPtr->data, sizeof(newPtr->data), value);
		newPtr->nextPtr = NULL;

		previousPtr = NULL;
		currentPtr = *sPtr;
		while (currentPtr != NULL) {
			newPtr->index++;
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		if (previousPtr == NULL) {
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}
		else {
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
	}
	else
		printf("%s not inserted. No memory available.\n", value);
}

int search(ListNodePtr *sPtr, char *value)
{
	ListNodePtr previousPtr, currentPtr;
	int overlap = 0;
	int i = 0;

	if (strcmp(value, (*sPtr)->data)==0) {
		overlap++;
		indexnumber[i++] = (*sPtr)->index;
	}
	previousPtr = *sPtr;
	currentPtr = (*sPtr)->nextPtr;
	
	while (currentPtr != NULL) {
		if (strcmp(currentPtr->data, value) == 0) {
			overlap++;
			indexnumber[i++] = currentPtr->index;
		}
		previousPtr = currentPtr;
		currentPtr = currentPtr->nextPtr;
	}
	return overlap;
}

int isEmpty(ListNodePtr sPtr)
{
	return sPtr == NULL;
}