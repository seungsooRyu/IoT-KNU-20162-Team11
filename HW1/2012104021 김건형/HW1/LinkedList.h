#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#define TRUE	1
#define FALSE	0

int indexnumber[20];

typedef struct listnode {
	int index;
	char data[20];
	struct listnode *nextPtr;
}ListNode;

typedef ListNode *ListNodePtr;

void insert(ListNodePtr *, char *);
int search(ListNodePtr *, char *);
int isEmpty(ListNodePtr);
void printList(ListNodePtr);
void instructions(void);

#endif // __LINKED_LIST__