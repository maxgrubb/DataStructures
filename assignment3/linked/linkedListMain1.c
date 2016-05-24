
#include "linkedList.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(){


	struct linkedList *grubbList = createLinkedList(); 
	addList(grubbList, 5); 	
	printf("back list: %i\n", backList(grubbList));
	printf("front list: %i\n", frontList(grubbList));

	addList(grubbList, 6); 	
	printf("back list: %i\n", backList(grubbList));
	printf("front list: %i\n", frontList(grubbList));

	addList(grubbList, 7); 
	printf("back list: %i\n", backList(grubbList));
	printf("front list: %i\n", frontList(grubbList));

	addList(grubbList, 8); 
	printf("back list: %i\n", backList(grubbList));
	printf("front list: %i\n", frontList(grubbList));


	addList(grubbList, 9); 
	printf("back list: %i\n", backList(grubbList));
	printf("front list: %i\n", frontList(grubbList));

	_printList(grubbList); 
	if(containsList(grubbList, 7))
	{
		printf("The list contains your value\n"); 
	}
	else
	{
		printf("The list does not contain your value.\n");
	}

	if(containsList(grubbList, 1))
	{
		printf("The list contains your value\n"); 
	}
	else
	{
		printf("The list does not contain your value.\n");
	}


	_printList(grubbList); 
	removeList(grubbList, 7); 
	printf("after removal:\n"); 
	_printList(grubbList); 
/*

	removeBackList(grubbList); 
	printf("back list: %i\n", backList(grubbList));
	printf("front list: %i\n", frontList(grubbList));
	
	removeBackList(grubbList); 
	printf("back list: %i\n", backList(grubbList));
	printf("front list: %i\n", frontList(grubbList));


	removeFrontList(grubbList); 
	removeFrontList(grubbList); 
//	printf("back list: %i\n", backList(grubbList));
//	printf("front list: %i\n", frontList(grubbList));
//	removeFrontList(grubbList); 

8*/	return 0;
}
