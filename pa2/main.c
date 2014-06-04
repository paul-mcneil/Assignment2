/*
 * sorted-list.c
 */

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"sorted-list.h"

int compareInts(void *p1, void *p2)
{
	int i1 = *(int*)p1;
	int i2 = *(int*)p2;

	return i1 - i2;
}

int compareDoubles(void *p1, void *p2)
{
	double d1 = *(double*)p1;
	double d2 = *(double*)p2;

	return (d1 < d2) ? -1 : ((d1 > d2) ? 1 : 0);
}

int compareStrings(void *p1, void *p2)
{
	char *s1 = p1;
	char *s2 = p2;

	return strcmp(s1, s2);
}
//Destructor functions
void destroyBasicTypeAlloc(void *p){
	//For pointers to basic data types (int*,char*,double*,...)
	//Use for allocated memory (malloc,calloc,etc.)
	free(p);
}

void destroyBasicTypeNoAlloc(void *p) {
	//For pointers to basic data types (int*,char*,double*,...)
	//Use for memory that has not been allocated (e.g., "int x = 5;SLInsert(mylist,&x);SLRemove(mylist,&x);")
	return;
}

int main(int argc, char** argv){

printf("Sample test cases, for more test cases look at testcode.txt and at testplan.txt for its expected behavior\n\n");
printf("********************************************* TEST CASE 1 ***********************************************\n\n");

SortedListPtr sl1 = SLCreate(compareInts, NULL);
SLDestroy(sl1);
printf("\n");

printf("********************************************* TEST CASE 6 ***********************************************\n\n");

const char * stringArray[] = {"Zoid", "Brackets", "Apple"};
void * printer;

SortedListPtr sl2 = SLCreate(compareStrings, destroyBasicTypeNoAlloc);

int i;
for(i=0; i<(sizeof(stringArray)/sizeof(stringArray[0])); i++){
	if(SLInsert(sl2, (void *)stringArray[i])==0)
		printf("There was an error but the list was still created anyway\n");
}

SortedListIteratorPtr iter2 = SLCreateIterator(sl2);

printf("List: ");
while((printer=SLNextItem(iter2)) != NULL)
	printf("%s ", (char *)printer);

SLInsert(sl2, "  zoom");
printf("%s ", (char *)SLNextItem(iter2));
printf("\n\n");

SLDestroy(sl2);
SLDestroyIterator(iter2);

printf("********************************************* TEST CASE 8 ***********************************************\n\n");

const char * stringArr[] = {"zoom", "wii", "Soccer", "Zoid", "Brackets", " zoom"};
void * print;
void * print2;

SortedListPtr sl = SLCreate(compareStrings, destroyBasicTypeNoAlloc);

int p;
for(p=0; p<(sizeof(stringArr)/sizeof(stringArr[0])); p++){
	if(SLInsert(sl, (void *)stringArr[p])==0)
		printf("There was an error but the list was still created anyway\n");
}

SortedListIteratorPtr iterator = SLCreateIterator(sl);
SortedListIteratorPtr iterator2 = SLCreateIterator(sl);			

printf("iterator 1: ");
print = SLNextItem(iterator);
printf("%s \n", (char *)iterator->currentNode->data);
		
printf("iterator 2: ");
print2 = SLNextItem(iterator2);
print2 = SLNextItem(iterator2);
printf("%s \n", (char *)iterator2->currentNode->data);	
		

SLRemove(sl, iterator->currentNode->data);
SLRemove(sl, iterator2->currentNode->data);

printf("%s \n", (char *)SLNextItem(iterator));
printf("%s \n", (char *)SLNextItem(iterator2));	

SLDestroyIterator(iterator);
SLDestroy(sl);

return 0;
}